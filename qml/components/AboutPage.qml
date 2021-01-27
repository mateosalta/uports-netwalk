import QtQuick 2.9
import Ubuntu.Components 1.3

Page {
    title: i18n.tr("About")

    Label {
        anchors.fill: parent
        anchors.margins: units.gu (2)
        text: i18n.tr("The remake of the popular game Netwalk optimized for Ubuntu Touch! \n\n Filippo Scognamiglio (flscogna@gmail.com)")
    }
}
