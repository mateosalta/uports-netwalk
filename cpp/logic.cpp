#include "logic.h"
#include <QTime>
#include <qglobal.h>

Logic::Logic(QObject *parent) :
    QObject(parent)
{
    _moves = 0;
    _gameState = GAME_LOADING();
    _time = 0;
    _rows = 0;
    _cols = 0;
    _board.clear();
}

bool Logic::isGameFinished(){
    for (int i = 0; i < _board.size(); i++) {
        if(_board[i]->getCellType() == Cell::TYPE_DESTINATION()){
            if(!_board[i]->getFlowing()) return false;
        }
    }

    setGameState(GAME_FINISHED());
    return true;
}

bool Logic::isValidIndex(int row, int col){
    return (row >= 0 && row < _rows && col >= 0 && col < _cols);
}

//Return if the current place is expandable in the given direction
bool Logic::isExpandable(int index, int direction){
    int row, col;
    if(direction == 0){
        row = (index / _cols) - 1;
        col = (index % _cols);
    }else if(direction == 1){
        row = (index / _cols);
        col = (index % _cols) + 1;
    }else if(direction == 2){
        row = (index / _cols) + 1;
        col = (index % _cols);
    }else if(direction == 3){
        row = (index / _cols);
        col = (index % _cols) - 1;
    }

    //Debug
    //std::cerr << "Row, col: " << row << ' ' << col << '\n';
    //std::cerr << isValidIndex(row, col) << '\n';

    if(isValidIndex(row, col)){
        //std::cerr << row * _cols + col << '\n';
        if(_board[row * _cols + col]->countLinks() == 0) return true;
    }
    return false;
}

void Logic::findExpandableDirections(int index, QVector<int> &result){
    result.clear();

    for(int i=0; i<4;i++){
        if(isExpandable(index, i)) {
            result.append(i);
        }
    }
}

//Expand the following node in the direction return the index of the neighbor node
int Logic::expand(int index, int direction){
    Q_ASSERT(isExpandable(index, direction));
    switch(direction){
    case 0:
        _board[index]->setNorth(true);
        _board[index - _cols]->setSouth(true);
        return index - _cols;
        break;
    case 1:
        _board[index]->setEast(true);
        _board[index + 1]->setWest(true);
        return index + 1;
        break;
    case 2:
        _board[index]->setSouth(true);
        _board[index + _cols]->setNorth(true);
        return index + _cols;
        break;
    case 3:
        _board[index]->setWest(true);
        _board[index - 1]->setEast(true);
        return index - 1;
        break;
    }

    return -1;
}

void Logic::generatePuzzle(){
    sourcesIndexes.clear();

    for (int i = 0; i < _rows * _cols; ++i) {
        _board.append(new Cell);
    }

    int i = 0;
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    while(i < _nSources){
        int srcIndex = qrand() % _board.size();
        _board[srcIndex]->setCellType(Cell::TYPE_SOURCE());
        sourcesIndexes.append(srcIndex);
        i++;
    }

    //Tracing wires
    QVector<int> frontier;

    //Add to the frontier all the sources
    foreach (int i, sourcesIndexes) {
        frontier.append(i);
    }

    QVector<int> directions;

    while(frontier.size() > 0){
        int randIndex = qrand() % frontier.size();
        int currIndex = frontier[randIndex];
        frontier.remove(randIndex);

        findExpandableDirections(currIndex, directions);

        if(directions.size() == 0){
            Cell* c = _board[currIndex];
            if(c->getCellType() != Cell::TYPE_SOURCE()){
                if(c->countLinks() == 1) c->setCellType(Cell::TYPE_DESTINATION());
            }
        } else {
            int dirIndex = qrand() % directions.size();
            int neighborIndex = expand(currIndex, directions[dirIndex]);
            frontier.append(currIndex);
            frontier.append(neighborIndex);
        }
    }
}

int Logic::toIndex(int row, int col){
    return row * _cols + col;
}

void Logic::getConnectedNodesIndexes(int index, QList<int> &result){
    result.clear();

    Cell* node = _board[index];
    Cell * otherNode;
    int otherIndex;
    int row = index / _cols;
    int col = index % _cols;

    if(node->getNorth() && isValidIndex(row-1, col)){
        otherIndex = toIndex(row-1, col);
        otherNode = _board[otherIndex];
        if(otherNode->getSouth()) result.append(otherIndex);
    }
    if(node->getEast() && isValidIndex(row, col+1)){
        otherIndex = toIndex(row, col+1);
        otherNode = _board[otherIndex];
        if(otherNode->getWest()) result.append(otherIndex);

    }
    if(node->getSouth() && isValidIndex(row+1, col)){
        otherIndex = toIndex(row+1, col);
        otherNode = _board[otherIndex];
        if(otherNode->getNorth()) result.append(otherIndex);
    }
    if(node->getWest() && isValidIndex(row, col-1)){
        otherIndex = toIndex(row, col-1);
        otherNode = _board[otherIndex];
        if(otherNode->getEast()) result.append(otherIndex);
    }
}

void Logic::newGame(int rows, int cols, int sources, int moves){
    setGameState(GAME_LOADING());
    setTime(0);
    _moves = 0;
    emit movesChanged();

    _rows = rows;
    _cols = cols;
    _nSources = sources;

    _board.clear();
    generatePuzzle();

    while (!randomlyRotatePieces(moves));

    updateEnergyFlow();
    emit cellsChanged();
    setGameState(GAME_READY());
}

//Antirotate some cells return false if failed true if ok
bool Logic::randomlyRotatePieces(int moves){
    QSet<int> rotated;

    while(moves > 0 || rotated.size() == (_board.size() - _nSources)){
        int index = qrand() % _board.size();
        if(_board[index]->getCellType() == Cell::TYPE_SOURCE()) continue;
        if(rotated.find(index) != rotated.end()) continue;

        int rotations = _board[index]->antiClockwiseRandomRotate(moves);
        rotated.insert(index);
        moves -= rotations;
    }

    if(moves != 0){
        //Revert to previous situation
        foreach (Cell* c, _board){
            c->resetRotation();
        }
        return false;
    }

    return true;
}

void Logic::updateEnergyFlow(){
    QVector<int> frontier;
    QSet<int> explored;
    QList<int> neighborsConnected;

    foreach (int i, sourcesIndexes) {
        frontier.append(i);
    }

    while(frontier.size() > 0){
        int index = frontier[0];
        frontier.pop_front();
        if(explored.find(index) != explored.end()) continue;
        _board[index]->setFlowing(true);
        explored.insert(index);

        getConnectedNodesIndexes(index, neighborsConnected);
        foreach (int i, neighborsConnected) {
            frontier.append(i);
        }
    }

    for (int i = 0; i < _board.size(); i++) {
        if(explored.find(i) == explored.end()){
            _board[i]->setFlowing(false);
        }
    }
}

void Logic::rotate(int index){
    if(getGameState() == GAME_FINISHED() || getGameState() == GAME_PAUSED()) return;
    if(_board[index]->rotate()){
        setGameState(GAME_RUNNING());

        _moves++;
        emit movesChanged();

        updateEnergyFlow();
    }
}

QQmlListProperty<Cell> Logic::getCells(){
    return QQmlListProperty<Cell>(this, _board);
}
