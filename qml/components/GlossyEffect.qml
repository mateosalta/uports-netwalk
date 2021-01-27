import QtQuick 2.9

Rectangle {
    anchors.centerIn: parent
    width: parent.width - parent.border.width
    height: parent.height - parent.border.width
    radius:parent.radius - parent.border.width/2
    antialiasing: true
    smooth: true
    opacity: 0.25


}
