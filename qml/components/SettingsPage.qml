import QtQuick 2.9
import Ubuntu.Components 1.3

Page {
    title: i18n.tr("Settings")

    Column {
        anchors.fill: parent
        anchors.margins: units.gu (2)
        spacing: units.gu (2)

        Row{
            spacing: units.gu (2)
            Label{
                text: i18n.tr("Glowing wires")
            }
            Switch{
                checked: settingsmanager.glowing
                onCheckedChanged: settingsmanager.glowing = checked;
            }
        }

        Row{
            spacing: units.gu (2)
            Label{
                text: i18n.tr("Rotations")
            }
            Switch{
                checked: settingsmanager.rotation
                onCheckedChanged: settingsmanager.rotation = checked;
            }
        }

        OptionSelector {
            text: i18n.tr("Difficulty")
            model: settingsmanager.difficulty_strings
            onDelegateClicked: {
                settingsmanager.difficulty_index = index;
                var params = settingsmanager.getDifficultyParams();
                logic.newGame(params[0], params[1], params[2], params[3]);
            }
        }
    }
}
