
import QtQuick 2.9
import Lomiri.Components 1.3


import "components"

/*!
    \brief MainView with a Label and Button elements.
*/

MainView {
    // objectName for functional testing purposes (autopilot-qt5)
    objectName: "mainView"
    
    // Note! applicationName needs to match the .desktop filename
   applicationName: "ubuntu-netwalk.mateo-salta"
  
    
    width: units.gu(100)
    height: units.gu(75)
    

    backgroundColor: "#111111";

    
    PageStack {
        id: page_stack
        Component.onCompleted: push (gamepage)

        Page {
            id: gamepage
            title: i18n.tr("UBports NetWalk")

            head.actions:
            [
                Action {
                    text: i18n.tr("Settings")
                    iconName: "settings"
                    onTriggered: page_stack.push (settings_page)
                },
                Action {
                    text: i18n.tr("New Game")
                    iconName: "reload"
                    onTriggered: {
                        var params = settingsmanager.getDifficultyParams();
                        logic.newGame(params[0],params[1],params[2],params[3]);
                    }
                },
            
                Action {
                    text: i18n.tr("About")
                    iconName: "info"
                    onTriggered: page_stack.push (about_page)
                }
            ]

            Timer{
                interval: 100
                onTriggered: logic.time += 0.1
                running: logic.gameState === logic.GAME_RUNNING
                repeat: true
            }

            SettingsManager{
                id: settingsmanager
            }

            LomiriShape{
                id: maincontainer
                color: "#191919";
                aspect: LomiriShape.Flat
                clip: true

                anchors.fill: parent

                DropdownMenu{
                    id: dropdownmenu
                    anchors{
                        top: parent.top
                        bottom: statsbar.bottom
                        left: parent.left
                        right: parent.right
                    }

                    z: 5
                }

                TopBar{
                    id: statsbar
                }

                anchors{
                    bottom: parent.bottom
                    top: parent.top
                    left: parent.left
                    right: parent.right
                    margins: units.gu(1)
                }

                GameView {
                    id: mainview
                    objectName: "mainview"

                    anchors.fill: parent
                    anchors.topMargin: statsbar.height
                    visible: true
                }
            }
        }

        HighScoresPage {
            id: high_scores_page
            visible: false
        }

        SettingsPage {
            id: settings_page
            visible: false
        }

        AboutPage {
            id: about_page
            visible: false
        }
    }

    Component.onCompleted:{
        var params = settingsmanager.getDifficultyParams();
        logic.newGame(params[0],params[1],params[2],params[3]);
    }
}
