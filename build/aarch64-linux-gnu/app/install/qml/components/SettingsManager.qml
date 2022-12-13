import QtQuick 2.9
import U1db 1.0 as U1db

//This component is used as an interface to localstorage
Item{
    id: settingsmanager

    property int difficulty_index: 0
    property var difficulty_strings: ["Easy", "Medium", "Hard", "Insane", "Yumi"]
    property var difficulty_params: [[5,5,1,20], [7,7,1,40], [9,9,2,64], [9,9,2,90], [18,18,4,180]]

    property real cell_zoom: 1.0
    property bool initialized: false
    property bool glowing: false
    property bool rotation: true
    property var highscores: [[], [], [], []]

    U1db.Database {
        id: settingsDatabase
        path: "ubuntu-netwalk-settings.db"
    }

    U1db.Document {
        id: db
        database: settingsDatabase
        docId: "settings"
        create: true
        defaults:{"glowing": "true",
                  "difficulty_index" : "0",
                  "roration" : "false",
                  "cell_zoom" : "1.0",
                  "highscores": "[[], [], [], []]"}

        Component.onCompleted: {
            var tempContents = {};
            tempContents = contents;
            glowing = Boolean(tempContents["glowing"]);
            difficulty_index = parseInt(tempContents["difficulty_index"]);
            rotation = Boolean(tempContents["rotation"]);
            cell_zoom = parseFloat(tempContents["cell_zoom"]);
            highscores = JSON.parse(tempContents["highscores"]);
        }

        Component.onDestruction: {
            var tempContents = {};
            tempContents["glowing"] = String(glowing);
            tempContents["difficulty_index"] = String(difficulty_index);
            tempContents["rotation"] = String(rotation);
            tempContents["cell_zoom"] = String(cell_zoom);
            tempContents["highscores"] = JSON.stringify(highscores);
            contents = tempContents;
        }
    }

    function getDifficultyParams(){
        return difficulty_params[difficulty_index];
    }

    function addHighScore(name, time, moves){
        var scoresArray = highscores[difficulty_index];

        scoresArray.push({"name": name, "time": time, "moves": moves});
        scoresArray.sort(function (a,b){return parseFloat(a.time) - parseFloat(b.time)});
        scoresArray = scoresArray.splice(0, 10);

        highscores[difficulty_index] = scoresArray;
    }
}
