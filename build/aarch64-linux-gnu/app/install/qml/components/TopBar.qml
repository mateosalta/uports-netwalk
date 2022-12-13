import QtQuick 2.9
import Lomiri.Components 1.3

Rectangle{
    id: statsbar
    property int extendedy: parent.height - height
    property int hiddeny: 0
    property int prev_gamestate: 0
    property int gameState: logic.gameState
    property bool expanded: false

    radius: units.dp(5)

    onGameStateChanged: {
        switch(gameState){
        case logic.GAME_FINISHED:
        case logic.GAME_PAUSED:
            expanded = true;
            break;
        default:
            expanded = false;
        }
    }

    height: units.gu(5)
    anchors{
        left: parent.left
        right: parent.right
    }


    z: 5
    color: "black"

    Button{
        property int prev_gamestate
        id: pausebutton

        anchors{
            left: parent.left
            top: parent.top
            bottom: parent.bottom
            margins: units.dp(2)
        }

        onClicked: {
            if(logic.gameState != logic.GAME_PAUSED && logic.gameState !== logic.GAME_FINISHED){
                prev_gamestate = logic.gameState;
                logic.gameState = logic.GAME_PAUSED
            }
            else if(logic.gameState == logic.GAME_PAUSED) logic.gameState = prev_gamestate;
            else if(logic.gameState == logic.GAME_FINISHED) expanded = !expanded;
        }

        iconSource: {
            if(!statsbar.expanded && logic.gameState == logic.GAME_FINISHED) "../imgs/svg/downarrow.svg"
            else if(!statsbar.expanded) "../imgs/svg/pause.svg"
            else "../imgs/svg/uparrow.svg"
        }

        width: height
        color: "green";
    }

    //Timer view
    Rectangle{
        id: timerviewid
        width: parent.width * 0.5
        radius: units.dp(5)
        color: "black"

        anchors{
            top: parent.top
            bottom: parent.bottom
            left: pausebutton.right
            margins: units.dp(2)
        }

        GlossyEffect{
            opacity: 0.4
        }

        //Time icon
        Rectangle{
            id: clockimage
            color: "white"
            opacity: 0.20

            radius: width * 0.5
            antialiasing: true

            anchors{
                verticalCenter: parent.verticalCenter
                right: parent.right
                margins: units.gu(1)
            }

            width: units.gu(3.5)
            height: units.gu(3.5)
        }

        Image {
            anchors.centerIn: clockimage
            width: units.gu(4)
            height: units.gu(4)
            opacity: 0.5
            source: "../imgs/svg/clock.svg"
        }

        Label{
            id: timerlabelid

            anchors{
                right: clockimage.left
                rightMargin: units.gu(1)
                verticalCenter: timerviewid.verticalCenter
            }

            font.pixelSize: timerviewid.height * 0.5
            font.bold: true
            text: parseFloat(logic.time).toFixed(1)
            color: "white"
        }
    }

    //Moves view
    Rectangle{
        id: movesviewid
        color: "black"
        width: parent.width * 0.5
        radius: units.dp(5)

        anchors{
            top: parent.top
            bottom: parent.bottom
            left: timerviewid.right
            right: parent.right
            margins: units.dp(2)
        }

        GlossyEffect{
            opacity: 0.4
        }

        //Moves icon
        Rectangle{
            id: rotateimage
            color: "white"
            opacity: 0.20

            radius: width * 0.5
            antialiasing: true

            anchors{
                verticalCenter: parent.verticalCenter
                right: parent.right
                margins: units.gu(1)
            }

            width: units.gu(3.5)
            height: units.gu(3.5)
        }

        Image {
            anchors.centerIn: rotateimage
            width: units.gu(2.5)
            height: units.gu(2.5)
            opacity: 0.5
            source: "../imgs/svg/rotate.svg"
        }

        Label{
            id: moveslabelid

            anchors{
                right: rotateimage.left
                verticalCenter: movesviewid.verticalCenter
                rightMargin: units.gu(1)
            }

            font.pixelSize: timerviewid.height * 0.5
            font.bold: true
            text: logic.moves
            color: "white"
        }
    }

    state: "hidden"

    states: [
        State {
            when: !expanded
            name: "hidden"
            PropertyChanges {
                target: statsbar
                y: hiddeny
            }
        },
        State{
            name: "expanded"
            when: expanded
            PropertyChanges{
                target: statsbar
                y: extendedy
            }
        }
    ]

    transitions: [
        Transition {
            from: "*"
            to: "*"
            PropertyAnimation{property: "y"; duration: 300}
        }
    ]
}
