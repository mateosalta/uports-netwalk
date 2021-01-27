#ifndef CELL_H
#define CELL_H

#include <QObject>

class Cell : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int TYPE_WIRE READ TYPE_WIRE() CONSTANT)
    Q_PROPERTY(int TYPE_SOURCE READ TYPE_SOURCE() CONSTANT)
    Q_PROPERTY(int TYPE_DESTINATION READ TYPE_DESTINATION() CONSTANT)

    Q_PROPERTY(int cellType READ getCellType NOTIFY typeChanged)
    Q_PROPERTY(bool north READ getOriginalNorth NOTIFY cellChanged)
    Q_PROPERTY(bool east READ getOriginalEast NOTIFY cellChanged)
    Q_PROPERTY(bool south READ getOriginalSouth NOTIFY cellChanged)
    Q_PROPERTY(bool west READ getOriginalWest NOTIFY cellChanged)
    Q_PROPERTY(int cellRotation READ getRotation NOTIFY rotationChanged)
    Q_PROPERTY(bool flowing READ getFlowing NOTIFY flowingChanged)

public:
    explicit Cell(QObject *parent = 0);
    static int TYPE_WIRE(){return 0;}
    static int TYPE_SOURCE(){return 1;}
    static int TYPE_DESTINATION(){return 2;}

    bool getOriginalNorth(){return _directions[0];}
    bool getNorth();
    void setNorth(bool newNorth){
        Q_ASSERT(_rotation == 0);
        if(_directions[0] != newNorth){
            _directions[0] = newNorth;
            emit cellChanged();
        }
    }
    bool getOriginalSouth(){return _directions[2];}
    bool getSouth();
    void setSouth(bool newSouth){
        Q_ASSERT(_rotation == 0);
        if(_directions[2] != newSouth){
            _directions[2] = newSouth;
            emit cellChanged();
        }
    }
    bool getOriginalEast(){return _directions[3];}
    bool getEast();
    void setEast(bool newEast){
        Q_ASSERT(_rotation == 0);
        if(_directions[3] != newEast){
            _directions[3] = newEast;
            emit cellChanged();
        }
    }
    bool getOriginalWest(){return _directions[1];}
    bool getWest();
    void setWest(bool newWest){
        Q_ASSERT(_rotation == 0);
        if(_directions[1] != newWest){
            _directions[1] = newWest;
            emit cellChanged();
        }
    }

    int getCellType(){return _cellType;}
    int getRotation(){return _rotation;}
    void resetRotation(){_rotation = 0;}

    bool getFlowing(){return _flowing;}
    void setFlowing(bool newFlowing){
        if(newFlowing != _flowing){
            _flowing = newFlowing;
            emit flowingChanged();
        }
    }

    void setCellType(int newType){
        if(newType != _cellType){
            _cellType = newType;
            emit typeChanged();
        }
    }

    bool rotate();
    int antiClockwiseRandomRotate(int maxRotations);
    int countLinks();

private:
    int _cellType;
    int _rotation;
    bool _flowing;
    bool* _directions;

    bool* getCurrentDirections();
    bool hasStraightConnections();

signals:
    void cellChanged();
    void rotationChanged();
    void flowingChanged();
    void typeChanged();
    
public slots:
    
};

#endif // CELL_H
