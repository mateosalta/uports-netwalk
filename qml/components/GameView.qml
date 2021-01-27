import QtQuick 2.9
import Ubuntu.Components 1.3

Item {
    id: gameview
    property real lineWidth: cell_size * 0.1
    property var flowingLineColor: UbuntuColors.orange;
    property var unflowingLineColor: UbuntuColors.warmGrey;
    property double glowing_strength: 0
    property real default_size: units.gu(10)
    property real cell_size: default_size * settingsmanager.cell_zoom


    SequentialAnimation on glowing_strength {
        running: settingsmanager.glowing
        NumberAnimation{
            from: 0
            to: 1
            duration: 2000
        }
        NumberAnimation{
            from: 1
            to: 0
            duration: 2000
        }
        loops: Animation.Infinite
    }

    anchors.centerIn: parent

    PinchAndFlick{
        id: flickable
        anchors.fill: parent
        finalScale: settingsmanager.cell_zoom
        onFinalScaleChanged: settingsmanager.cell_zoom = finalScale;
        enabled: statsbar.state == "hidden"

        delegate: Grid{
            id: gridid
            rows: logic.rows
            columns: logic.cols

            Repeater{
                id: repeaterid
                model: logic.cells
                delegate: Rectangle{
                    id: cellcontaier
                    scale: gridid.scale
                    width: cell_size
                    height: width
                   radius: width * 0.5
                    antialiasing: true

                    color: (cellType === TYPE_SOURCE) ? "#9c330e" : "#262626";

                    GameCell{}

                    Loader{
                        id: deviceimages
                        anchors.centerIn: parent
                        width: parent.width
                        height: width
                        source: {(cellType === TYPE_DESTINATION) ? "Destination.qml" : ""}
                    }

                    Loader{
                        id: sourceimages
                        anchors.centerIn: parent
                        width: parent.width - 2 * lineWidth
                        source: (cellType === TYPE_SOURCE) ? "Source.qml" : ""
                    }

                    MouseArea{
                        anchors.fill: parent

                        onClicked: {
                            logic.rotate(index);
                        }
                    }
                }
            }
            
        }
    }
}
