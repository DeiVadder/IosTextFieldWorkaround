import QtQuick 2.12
import QtQuick.Controls 2.12

import QLineEdit 1.0

TextInput {
    id:root
    onEditingFinished: parent.forceActiveFocus()


    MouseArea{
        anchors.fill: parent
        visible: Qt.platform.os === "ios" && !root.activeFocus

        onClicked: backend.init(root.text)

        QLineEdit{
            id:backend
            onTextChanged: root.text = text
            onEditingFinished: root.parent.forceActiveFocus()
            onShiftFocus: root.forceActiveFocus()
        }
    }
}
