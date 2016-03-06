import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    signal flipCoinsSignal(int m, int n)

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    GroupBox {
        id: settingsGroupBox
        x: 23
        y: 24
        width: 91
        height: 123
        title: qsTr("Settings")

        TextField {
            id: mTextField
            x: 26
            y: 7
            width: 48
            height: 20
            text: "2"
            transformOrigin: Item.Right
            placeholderText: qsTr("Text Field")
        }

        Label {
            id: mLabel
            x: 0
            y: 9
            width: 18
            height: 14
            text: qsTr("m = ")
            visible: true
            wrapMode: Text.NoWrap
        }

        Label {
            id: nLabel
            x: 0
            y: 48
            width: 18
            height: 14
            text: qsTr("n = ")
            wrapMode: Text.NoWrap
            visible: true
        }

        TextField {
            id: nTextField
            x: 26
            y: 46
            width: 48
            height: 20
            text: "10"
            placeholderText: qsTr("Text Field")
        }

        Button {
            id: runButton
            x: 0
            y: 77
            text: qsTr("Run")
            onClicked: applicationWindow.flipCoinsSignal(mTextField.text*1, nTextField.text*1)
        }
    }

    GroupBox {
        id: outputGroupBox
        x: 146
        y: 24
        width: 261
        height: 123
        title: qsTr("Output")

        Label {
            id: label1
            x: 0
            y: 8
            text: qsTr("Incorrect guesses")
        }

        TextField {
            id: textField1
            x: 109
            y: 5
            placeholderText: qsTr("Text Field")
        }

        Label {
            id: label2
            x: 0
            y: 49
            text: qsTr("Computed bound")
        }

        TextField {
            id: textField2
            x: 109
            y: 46
            placeholderText: qsTr("Text Field")
        }
    }
}

