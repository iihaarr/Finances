import QtQuick 2.10
import QtQuick.Window 2.10
import  QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    TabView {
         id: frame
         anchors.fill: parent
         anchors.margins: 4
         Tab { title: "Tab 1" }
         Tab { title: "Tab 2" }
         Tab { title: "Tab 3" }

         style: TabViewStyle {
             frameOverlap: 1
             tab: Rectangle {
                 color: styleData.selected ? "steelblue" :"lightsteelblue"
                 border.color:  "steelblue"
                 implicitWidth: Math.max(text.width + 4, 80)
                 implicitHeight: 20
                 radius: 2
                 Text {
                     id: text
                     anchors.centerIn: parent
                     text: styleData.title
                     color: styleData.selected ? "white" : "black"
                 }
             }
             frame: Rectangle { color: "steelblue" }
         }
     }
}
