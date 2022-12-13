#ifndef LOGIC_H
#define LOGIC_H

#include <QObject>
#include <QVector>
#include <QSet>
#include <QQmlListProperty>

#include "cell.h"

class Logic : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int GAME_LOADING READ GAME_LOADING CONSTANT)
    Q_PROPERTY(int GAME_READY READ GAME_READY CONSTANT)
    Q_PROPERTY(int GAME_RUNNING READ GAME_RUNNING CONSTANT)
    Q_PROPERTY(int GAME_PAUSED READ GAME_PAUSED CONSTANT)
    Q_PROPERTY(int GAME_FINISHED READ GAME_FINISHED CONSTANT)

    Q_PROPERTY(int gameState READ getGameState WRITE setGameState NOTIFY gameStateChanged)
    Q_PROPERTY(QQmlListProperty<Cell> cells READ getCells NOTIFY cellsChanged)
    Q_PROPERTY(int moves READ getMoves NOTIFY movesChanged)
    Q_PROPERTY(int rows READ getRows() NOTIFY cellsChanged)
    Q_PROPERTY(int cols READ getCols() NOTIFY cellsChanged)
    Q_PROPERTY(float time READ getTime WRITE setTime NOTIFY timeChanged)
public:
    explicit Logic(QObject *parent = 0);
    static int GAME_LOADING(){return -1;}
    static int GAME_READY(){return 0;}
    static int GAME_RUNNING(){return 1;}
    static int GAME_PAUSED(){return 2;}
    static int GAME_FINISHED(){return 3;}

    Q_INVOKABLE void newGame(int rows, int cols, int sources, int moves);
    Q_INVOKABLE void rotate(int index);
    int getRows(){ return _rows; }
    int getCols(){ return _cols; }
    Q_INVOKABLE bool isGameFinished();
    QQmlListProperty<Cell> getCells();

    float getTime(){ return _time;}
    void setTime(float newTime){_time = newTime; emit timeChanged();}

    int getMoves(){return _moves;}

    int getGameState(){return _gameState;}
    void setGameState(int newState){
        if(newState != _gameState){
            _gameState = newState;
            emit gameStateChanged();
        }
    }
    
private:
    QList<Cell*> _board;
    QList<int> sourcesIndexes;
    int _gameState;
    int _rows;
    int _cols;
    int _nSources;
    float _time;
    int _moves;

    void generatePuzzle();
    bool isValidIndex(int row, int col);
    bool isExpandable(int index, int direction);
    int expand(int index, int direction);
    void findExpandableDirections(int index, QVector<int> &result);
    void getConnectedNodesIndexes(int index, QList<int> &result);
    int toIndex(int row, int col);
    void updateEnergyFlow();
    bool randomlyRotatePieces(int moves);

signals:
    void gameStateChanged();
    void cellsChanged();
    void timeChanged();
    void movesChanged();
    
public slots:
    
};

#endif // LOGIC_H
