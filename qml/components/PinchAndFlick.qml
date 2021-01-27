import QtQuick 2.9

/*This item manages a flickable and pinchable areas. It also supports keyboard
 *with CTRL+PLUS CTRL+MINUS*/

Item{
    id: containerItem
    property alias delegate: placeholder.children
    property real minimuxScale: 0.5
    property real maximumScale: 2.0

    property real finalScale: 1.0

    Flickable{
        id: flick
        anchors.fill: parent
        clip: true
        enabled: true

        PinchArea{
            enabled: !parent.flicking
            anchors.fill: parent

            pinch.maximumScale: containerItem.maximumScale
            pinch.minimumScale: containerItem.minimuxScale

            onPinchUpdated: {
                var newScale = finalScale * pinch.scale;
                if (newScale > minimuxScale && newScale < maximumScale){
                    placeholder.scale = pinch.scale;
                }
            }

            onPinchFinished: {
                finalScale = placeholder.scale * finalScale;
                placeholder.scale = 1.0;
                flick.returnToBounds();
            }
        }

        contentWidth: placeholder.childrenRect.width * placeholder.scale
        contentHeight: placeholder.childrenRect.height * placeholder.scale

        leftMargin: (flick.width > flick.contentWidth) ? (flick.width - flick.contentWidth) * 0.5: 0
        topMargin: (flick.height > flick.contentHeight) ? (flick.height - flick.contentHeight) * 0.5: 0

        boundsBehavior: Flickable.DragOverBounds

        Item{
            id: placeholder
        }
    }

    Item{
        id: keyhandler
        property real zoomDelta: 0.1
        anchors.fill: parent
        focus: true
        Keys.onPressed: {
            if (event.key === Qt.Key_Plus && (event.modifiers & Qt.ControlModifier)){
                finalScale = (finalScale + zoomDelta < maximumScale) ? finalScale + zoomDelta : finalScale
            } else if(event.key === Qt.Key_Minus && (event.modifiers & Qt.ControlModifier)){
                finalScale = (finalScale - zoomDelta > minimuxScale) ? finalScale - zoomDelta : finalScale
            }
            flick.returnToBounds();
        }

        Component.onCompleted: forceActiveFocus();
    }
}
