import QtQuick 2.10
import QtQuick.Layouts 1.2

Rectangle {
    property double rad: 5
    property alias name: label.text
    property alias cost: cost.text
    property alias percent: percentText.text

    width: parent.width
    height: parent.height
    border.color: "lightsteelblue"
    border.width: 3
    radius: rad
    Rectangle {
        property double topMargin: 10
        property double bottomMargin: 10
        property double leftMargin: 10

        implicitWidth: 50
        height: parent.height - topMargin - bottomMargin
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.topMargin: topMargin
        anchors.bottomMargin: bottomMargin
        anchors.leftMargin: leftMargin
        Text {
            id: label
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }
    Rectangle {
        property double topMargin: 10
        property double bottomMargin: 10
        property double rightMargin: 10

        id: rectPercent
        implicitWidth: 50
        height: parent.height - topMargin - bottomMargin
        anchors.right: rectCost.left
        anchors.top: parent.top
        anchors.topMargin: topMargin
        anchors.bottomMargin: bottomMargin
        anchors.rightMargin: rightMargin
        Text {
            id: percentText
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }
    Rectangle {
        property double topMargin: 10
        property double bottomMargin: 10
        property double rightMargin: 5

        id: rectCost
        implicitWidth: 50
        height: parent.height - topMargin - bottomMargin
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.rightMargin: rightMargin
        anchors.topMargin: topMargin
        anchors.bottomMargin: bottomMargin
        Text {
            id: cost
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }
}

