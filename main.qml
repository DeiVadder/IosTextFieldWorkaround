import QtQuick 2.12

Rectangle {

    Rectangle{
        color: "red"
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: lEdit.top
    }

    IosLineEdit{
        id:lEdit
        anchors.left: parent.left

        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter

        height: 200

        text: "defaultText"
    }

    Rectangle{
        color: "blue"
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.top: lEdit.bottom
    }

}
