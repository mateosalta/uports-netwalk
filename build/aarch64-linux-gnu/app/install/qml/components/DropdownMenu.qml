import QtQuick 2.9
import Lomiri.Components 1.3

LomiriShape {
    id: dropdownmenu

    color: "black"
    opacity: 0.9
    clip: true

    Loader{
        anchors.fill: parent
        anchors.bottomMargin: statsbar.height
        sourceComponent: logic.gameState == logic.GAME_FINISHED ? endcomponent : pausecomponent
        Component{
            id: pausecomponent
            Item{
                anchors.fill: parent
                Label{
                    anchors.centerIn: parent
                    text: i18n.tr("Paused")
                    fontSize: "x-large"
                    color: "white"
                }
            }
        }
        Component{
            id: endcomponent
            Item{
                anchors.fill: parent
                Column{
                    property int column_width: Math.min(parent.width, units.gu(30))
                    width: column_width
                    anchors.centerIn: parent
                    spacing: units.gu(2)
                    Label{
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: i18n.tr("You Won!")
                        color: "white"
                        fontSize: "x-large"
                    }
             
                 
                    Row{
                        property real button_size: (parent.width - spacing) * 0.5
                        width: parent.width
                        height: childrenRect.height
                        spacing: units.gu(1)
                        anchors.horizontalCenter: parent.horizontalCenter
                  
                        Button {
                            width: parent.width
                            text: i18n.tr("Play Again")
                            color: "green"
                            onClicked: {
                                var params = settingsmanager.getDifficultyParams();
                                logic.newGame(params[0],params[1],params[2],params[3]);
                            }
                        }
                    }
                    //Separator
                    Item{
                        height: units.gu(5)
                        width: 100
                    }
                    Image{
                        id: logoimage
                        width: parent.width * 0.5
                        height: width
                        anchors.horizontalCenter: parent.horizontalCenter
                        source: "../imgs/svg/yumi2.svg"
                        fillMode: Image.PreserveAspectFit

                        NumberAnimation on rotation{
                            from: 0
                            to: 360
                            duration: 2000
                            running: settingsmanager.rotation
                            loops: Animation.Infinite
                        }
                    }
                }
            }
        }
    }
}
