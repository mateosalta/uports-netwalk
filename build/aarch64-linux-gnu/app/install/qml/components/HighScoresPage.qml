import QtQuick 2.9
import Lomiri.Components 1.3

Page {
    title: i18n.tr("HighScores")

    ListModel{        
        id: highscoremodel        

        function appendAll(array){        
            for(var i = 0; i<array.length; i++){        
                highscoremodel.append(array[i]);        
            }        
        }        
    }        

    Column{
        anchors.fill: parent
        anchors.margins: units.gu (2)
        spacing: units.gu (2)

        OptionSelector {
            id: difficultyselector
            text: i18n.tr("Difficulty")
            model: settingsmanager.difficulty_strings

            selectedIndex: settingsmanager.difficulty_index

            function loadModel(difficulty){
                highscoremodel.clear();
                highscoremodel.appendAll(settingsmanager.highscores[difficulty]);
            }

            onSelectedIndexChanged: loadModel(selectedIndex)
            Component.onCompleted: loadModel(selectedIndex);
        }

        Label{        
            color: "white"        
            anchors.left: parent.left        
            text: highscoremodel.count !== 0 ? i18n.tr("Name") : i18n.tr("No scores")        
            font.bold: true        
        }        
        Label{        
            color: "white"        
            font.bold: true        
            anchors.right: parent.right        
            text: highscoremodel.count !== 0 ? i18n.tr("Time") + "  (" + i18n.tr("Moves") + ")" : ""        
        }        

        Repeater{
            model: highscoremodel

            delegate: Text{
                Label{
                    anchors.left: parent.left
                    text: name
                    color: "white"
                }
                Label{
                    anchors.right: parent.right
                    color: "white"
                    font.bold: true
                    text: time.toFixed(1) + "  ("+ moves + ")";
                }
            }
        }
    }
}
