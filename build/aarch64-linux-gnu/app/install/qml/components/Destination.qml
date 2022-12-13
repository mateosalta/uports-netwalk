import QtQuick 2.9

//Device
Item{
    anchors.fill: parent
    property var images: ["laptop", "smartphone", "monitor"]

    function pickRandomImage(value){
        var index = (value % 3)
        return "../imgs/svg/" + images[index];
    }

    Image{
        id: onimage
        anchors.centerIn: parent
        width: parent.width * 0.65
        height: width
        source: pickRandomImage(index) + "_on.svg"
        sourceSize.width: width
        sourceSize.height: height
        opacity: 0
        z: 6
    }

    Image{
        id: offimage
        anchors.centerIn: parent
        width: parent.width * 0.65
        height: width
        source: pickRandomImage(index) + "_off.svg"
        sourceSize.width: width
        sourceSize.height: height
        z: 5
    }

    Image{
        id: smalllogoicon
        anchors.centerIn: parent
        width: parent.width * 0.2
        height: width
        source: "../imgs/svg/yumi.svg"
        z: 6
        opacity: 0
    }

    states: [
        State {
            name: "on"
            when: flowing
            PropertyChanges {target: onimage; opacity: 1}
            PropertyChanges {target: smalllogoicon; opacity: 1}
        },
        State {
            name: "off"
            when: !flowing
            PropertyChanges {target: onimage; opacity: 0}
            PropertyChanges {target: smalllogoicon; opacity: 0}
        }
    ]

    transitions: [
        Transition {
            from: "*"
            to: "*"

            PropertyAnimation{property: "opacity"; duration: 500}
        }
    ]
}
