import QtQuick 2.9

Image{
    id: sourceimage
    anchors.centerIn: parent
    width: parent.width - lineWidth * 2
    height: width
    source: "../imgs/png/ubuntu_logo64.png"

    Rectangle{
        anchors.fill: parent
        radius: width / 2
        color: "white"
        antialiasing: true
        visible: settingsmanager.glowing
        opacity: glowing_strength * 0.5
    }

    RotationAnimation on rotation {
        from: 0
        to: 360
        duration: 2000
        running: settingsmanager.rotation
        loops: Animation.Infinite
    }
}
