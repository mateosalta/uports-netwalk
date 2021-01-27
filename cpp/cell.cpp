#include "cell.h"

Cell::Cell(QObject *parent) :
    QObject(parent)
{
    _rotation = 0;
    _directions = new bool[4];
    _directions[0] = false;_directions[1] = false;
    _directions[2] = false;_directions[3] = false;
    _flowing = false;
    _cellType = TYPE_WIRE();
}

bool Cell::getNorth(){
    return _directions[(0 + _rotation) % 4];
}
bool Cell::getWest(){
    return _directions[(1 + _rotation) % 4];
}
bool Cell::getSouth(){
    return _directions[(2 + _rotation) % 4];
}
bool Cell::getEast(){
    return _directions[(3 + _rotation) % 4];
}

bool Cell::hasStraightConnections(){
    return (getOriginalNorth() && getOriginalSouth() && !getOriginalEast() && !getOriginalWest()) ||
           (!getOriginalNorth() && !getOriginalSouth() && getOriginalEast() && getOriginalWest());
}

bool* Cell::getCurrentDirections(){
    bool* result = new bool[4];
    result[0] = getNorth();
    result[1] = getEast();
    result[2] = getSouth();
    result[3] = getWest();
    return result;
}

//Randomly rotate the cell and return how many rotations were made.
int Cell::antiClockwiseRandomRotate(int maxRotations){
    if(_cellType == TYPE_SOURCE()) return 0;
    if(countLinks() == 4) return 0;

    int rotations = 1;
    if(!hasStraightConnections()) rotations += qrand() % 3;
    if(rotations > maxRotations) rotations = maxRotations;

    _rotation = (_rotation + 4 - rotations);

    return rotations;
}

bool Cell::rotate(){
    if(_cellType == TYPE_SOURCE()) return false;
    _rotation = (_rotation + 1);
    emit rotationChanged();
    return true;
}

int Cell::countLinks(){
    int count = 0;
    for (int i = 0; i < 4; i++) {
        if(_directions[i]) count++;
    }
    return count;
}
