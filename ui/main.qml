import QtQuick 2.5
import QtQuick.Window 2.5
import QtQuick.Layouts 1.11

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
        spacing: 5
        width: parent.width
        height: parent.height

        CategoryCost {
            width: parent.width
            height: 50
            name: qsTr("Продукты")
            cost: qsTr("10 397 Р")
            percent: qsTr("23%")
        }
        CategoryCost {
            width: parent.width
            height: 50
            name: qsTr("Продукты")
            cost: qsTr("10 397 Р")
            percent: qsTr("23%")
        }
        CategoryCost {
            width: parent.width
            height: 50
            name: qsTr("Продукты")
            cost: qsTr("10 397 Р")
            percent: qsTr("23%")
        }
    }
}
