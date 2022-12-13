import QtQuick 2.9

Item{
    property real lineThickness: lineWidth
    property real lineLength: (width + lineWidth) * 0.5
    property color lineColor: (flowing) ? flowingLineColor : unflowingLineColor
    id: gamecell
    anchors.fill: parent

    Item{
        id: linecontainer
        anchors.fill: parent
        //West line
        Rectangle{
            height: lineThickness
            width: lineLength
            visible: west
            color: lineColor

            x: 0
            y: (parent.height - lineThickness) * 0.5

        }
        //East line
        Rectangle{
            height: lineThickness
            width: lineLength
            color: lineColor
            visible: east

            x: (parent.width - lineThickness) * 0.5
            y: (parent.height - lineThickness) * 0.5
        }
        //North line
        Rectangle{
            height: lineLength
            width: lineThickness
            color: lineColor
            visible: north

            x: (parent.width - lineThickness) * 0.5
            y: 0
        }
        //South line
        Rectangle{
            height: lineLength
            width: lineThickness
            color: lineColor
            visible: south

            x: (parent.width - lineThickness) * 0.5
            y: (parent.height - lineThickness) * 0.5
        }

    }

    //Glow image
    Loader{
        anchors.fill: parent
        source: settingsmanager.glowing ? "GlowingImage.qml" : ""
        z: 4
    }

    transform: Rotation{
        origin.x: cell_size * 0.5
        origin.y: cell_size * 0.5
        angle: 90 * (cellRotation)

        Behavior on angle{
            NumberAnimation{
                duration: 350
                onRunningChanged: {if(!running) logic.isGameFinished();}
            }
        }
    }

    Behavior on lineColor {
        ColorAnimation{duration: 400}
    }
}

