import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Window 2.12
import QtGraphicalEffects 1.10


Item{
    id: splash
    visible: true
    width: mainGrid.width
    height: mainGrid.height
    signal timeout

    Grid
    {
        id:mainGrid
        width: 400
        height: 600
        rows: 3


        Rectangle
        {
            width: 400
            height: 100
            color: "white"
            Label
            {
                anchors.centerIn: parent
                text: qsTr("Welcome To SixR Robot")
                color: "#21be2b"
                font.pointSize: 25
            }
        }

        Image {
            id: image
            source: "qrc:/icons/sixr_icon.png"
            width: 400
            height: 400
        }

        Rectangle
        {
            width: 400
            height: 100
            color: "white"
            ProgressBar{
                id: mainProgressBar
                height: parent.height * 1/3
                width: parent.width * 1/2
                anchors.centerIn: parent
                from:0
                to:60
                value: 0

                //*******************************************************************
                //*******************************************************************
                // Test Animation
                background: Rectangle
                {
                    implicitWidth: 200
                    implicitHeight: 6
                    border.color: "#21be2b"
                    radius: 5
                }
                contentItem: Item {
                    implicitWidth: 200
                    implicitHeight: 4

                    Rectangle {
                        id: bar
                        width: mainProgressBar.visualPosition * parent.width
                        height: parent.height
                        radius: 5
                        color: "#21be2b"
                    }

                    LinearGradient {
                        anchors.fill: bar
                        start: Qt.point(0, 0)
                        end: Qt.point(bar.width, 0)
                        source: bar
                        gradient: Gradient {
                            GradientStop { position: 0.0; color: "#21be2b" }
                            GradientStop { id: grad; position: 0.5; color: Qt.lighter("#21be2b", 2) }
                            GradientStop { position: 1.0; color: "#21be2b" }
                        }
                        PropertyAnimation {
                            target: grad
                            property: "position"
                            from: 0.1
                            to: 0.9
                            duration: 1000
                            running: true
                            loops: Animation.Infinite
                        }
                    }
                    LinearGradient {
                        anchors.fill: bar
                        start: Qt.point(0, 0)
                        end: Qt.point(0, bar.height)
                        source: bar
                        gradient: Gradient {
                            GradientStop { position: 0.0; color: Qt.rgba(0,0,0,0) }
                            GradientStop { position: 0.5; color: Qt.rgba(1,1,1,0.3) }
                            GradientStop { position: 1.0; color: Qt.rgba(0,0,0,0.05) }
                        }
                    }
                }

                //*******************************************************************
                //*******************************************************************
            }
        }
    }

    Timer {
        interval: 3000; running: true; repeat: false
        onTriggered: {
            visible = false
            splash.timeout()
        }
    }

    Timer
    {
        interval: 50; running: true; repeat: true
        onTriggered:
        {
            mainProgressBar.value +=1
        }
    }

    Component.onCompleted:
    {
        visible = true
        setX(Screen.width / 2 - width / 2);
        setY(Screen.height / 2 - height / 2);
    }
}
