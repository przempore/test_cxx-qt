import QtQuick 2.15
import QtQuick.Controls 2.12
import QtQuick.Window 2.15

import com.kdab.cxx_qt.demo 1.0


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    MyObject {
        id: myObject
        number: 1
        string: "My String with my number: " + myObject.number
    }

    Column {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 10

        Label {
            text: "Number: " + myObject.number
        }

        Label {
            text: "String: " + myObject.string
        }

        Button {
            text: "Increment Number"

            onClicked: myObject.incrementNumber()
        }

        Button {
            text: "Say Hi!"

            onClicked: myObject.sayHi(myObject.string, myObject.number)
        }
    }

}
