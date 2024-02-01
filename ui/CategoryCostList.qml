import QtQuick 2.5

ListView {
    id: root
    property alias model: root.model
    property alias spacing: root.spacing

    width: parent.width
    height: parent.width
    anchors.fill: parent

    delegate: CategoryCostElement {
        width: ListView.view.width
        height: 40
        name: model.name
        cost: model.cost + " P"
        percent: model.percent + '%'
    }
    spacing: 10
}
