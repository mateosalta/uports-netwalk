import QtQuick 2.9

Image {
    id: glowimage
    anchors.fill: parent
    z: 2
    visible: flowing

    opacity: glowing_strength

    source: {
        var path = "../imgs/glow_";
        if(north) path += "n";
        if(east) path += "e";
        if(south) path += "s";
        if(west) path += "w";
        path+= ".png";
        return path;
    }
}
