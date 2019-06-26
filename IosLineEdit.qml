import QtQuick 2.12
import QtQuick.Controls 2.12

import QLineEdit 1.0

TextInput {
    id:root

    QLineEdit{
        id:backend

        onTextChanged: root.text = text
        onEditingFinished: root.parent.forceActiveFocus()
    }

    MouseArea{
        anchors.fill: parent
        visible: Qt.platform.os === "ios"

        onClicked: backend.init(root.text)
    }
}
