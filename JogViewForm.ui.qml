import QtQuick 2.7
import QtQuick.Controls 2.2
import JogViewModel 1.0

Item {
    property int _width: 255
    property int _height: 75
    property bool _joint: true
    property int _feed: 100

    property var _nameJoint: ["M1", "M2", "M3", "M4", "M5", "M6"]
    property var _valueJoint: ["1234.1234", "1234.1234", "1234.1234", "1234.1234", "1234.1234", "1234.1234"]


    property var _nameCartesian: ["X", "Y", "Z", "Ro", "Pi", "Ya"]
    property var _valueCartesian: ["25", "4544", "789", "12345", "453642", "4563456"]



    Timer{
        id:timer_actual
           interval: 20; running: true; repeat: true
           onTriggered: {
//               rightviewmodel.UpdateStatusWord()
               jogviewmodel.UpdateActualPosition()
           }
    }

    JogViewModel{
        id:jogviewmodel
    }


   Grid{ // main grid
       width: parent.width
       height: parent.height * 9/10
       columns: 2
       spacing: 5

        // switch button
       Switch {
           id: control
           text:control.checked ? qsTr("Cartesian") : qsTr("Joint")
           width: parent.width * 0.5
           height: parent.height * 0.25
           onClicked: _joint = ! _joint
           indicator: Rectangle {
               implicitWidth: 48
               implicitHeight: 26
               x: control.leftPadding
               y: parent.height / 2 - height / 2
               radius: 13
               color: control.checked ? "#17a81a" : "#ffffff"
               border.color: control.checked ? "#17a81a" : "#cccccc"

               Rectangle {
                   x: control.checked ? parent.width - width : 0
                   width: 26
                   height: 26
                   radius: 13
                   color: control.down ? "#cccccc" : "#ffffff"
                   border.color: control.checked ? (control.down ? "#17a81a" : "#21be2b") : "#999999"
               }
           }

           contentItem: Text {
               text: control.text
               font: control.font
               opacity: enabled ? 1.0 : 0.3
               color: control.down ? "#17a81a" : "#21be2b"
               verticalAlignment: Text.AlignVCenter
               leftPadding: control.indicator.width + control.spacing
           }
       }

       //feed override
       Grid{
           width: parent.width * 0.5
           height: parent.height * 0.25
           columns: 1

           Label{
             padding: 10
             text: "Feed Override: " + _feed.toFixed(0)
             width: parent.width
             height: parent.height * 0.5
             color: "#21be2b"
             verticalAlignment: Text.AlignVCenter
             //horizontalAlignment: Text.AlignHCenter
           }
           Slider {
               id: control1
               width: parent.width
               height: parent.height * 0.5
               from: 0
               value: 100
               to: 200
               stepSize: 20
               onMoved: {
                   _feed = control1.value
               }

               background: Rectangle {
                   x: control1.leftPadding
                   y: control1.topPadding + control1.availableHeight / 2 - height / 2
                   implicitWidth: 200
                   implicitHeight: 4
                   width: control1.availableWidth
                   height: implicitHeight
                   radius: 2
                   color: "#bdbebf"

                   Rectangle {
                       width: control1.visualPosition * parent.width
                       height: parent.height
                       color: "#21be2b"
                       radius: 2
                   }
               }

               handle: Rectangle {
                   x: control1.leftPadding + control1.visualPosition * (control1.availableWidth - width)
                   y: control1.topPadding + control1.availableHeight / 2 - height / 2
                   implicitWidth: 26
                   implicitHeight: 26
                   radius: 13
                   color: control1.pressed ? "#f0f0f0" : "#f6f6f6"
                   border.color: "#bdbebf"
               }
           }

       }



       //Joint
       MFrame{ // Motor1
           width: parent.width * 0.5
           height: parent.height * 0.25
           visible: _joint
           Grid{
               width: parent.width
               height: parent.height
               columns: 4
               spacing: 0
               Label{
                   width: parent.width * 0.15
                   height: parent.height
                   horizontalAlignment: Text.AlignHCenter
                   verticalAlignment: Text.AlignVCenter
                   text: "<b>" + _nameJoint[0] + "</b>"
                   color: "#21be2b"
               }
               MButton{
                   _width: parent.width * 0.15
                   _height: parent.height
                   _text:"-"
                   onBtnPress: {
                       jogviewmodel.jogJoint(0,0,1)
                   }
                   onBtnReleased: {
                       jogviewmodel.jogJoint(0,0,0)
                   }
               }

              Label{
                  width: parent.width * 0.55
                  height: parent.height
                  horizontalAlignment: Text.AlignHCenter
                  verticalAlignment: Text.AlignVCenter
                  text: jogviewmodel.ActualPosition[0].toFixed(3)
                  color: "#21be2b"
              }
               MButton{
                   _width: parent.width * 0.15
                   _height: parent.height
                   _text:"+"
                   onBtnPress: {
                       jogviewmodel.jogJoint(1,0,1)
                   }
                   onBtnReleased: {
                       jogviewmodel.jogJoint(1,0,0)
                   }
               }
           }
       }

       //************************************************************************
       //************************************************************************


       MFrame{ // Motor2
           width: parent.width * 0.5
           height: parent.height * 0.25
           visible: _joint
           Grid{
               width: parent.width
               height: parent.height
               columns: 4
               spacing: 0
               Label{
                   width: parent.width * 0.15
                   height: parent.height
                   horizontalAlignment: Text.AlignHCenter
                   verticalAlignment: Text.AlignVCenter
                   text: "<b>" + _nameJoint[1] + "</b>"
                   color: "#21be2b"
               }
               MButton{
                   _width: parent.width * 0.15
                   _height: parent.height
                   _text:"-"
                   onBtnPress: {
                       jogviewmodel.jogJoint(0,1,1)
                   }
                   onBtnReleased: {
                       jogviewmodel.jogJoint(0,1,0)
                   }
               }

              Label{
                  width: parent.width * 0.55
                  height: parent.height
                  horizontalAlignment: Text.AlignHCenter
                  verticalAlignment: Text.AlignVCenter
                  text: jogviewmodel.ActualPosition[1].toFixed(3)
                  color: "#21be2b"
              }
               MButton{
                   _width: parent.width * 0.15
                   _height: parent.height
                   _text:"+"
                   onBtnPress: {
                       jogviewmodel.jogJoint(1,1,1)
                   }
                   onBtnReleased: {
                       jogviewmodel.jogJoint(1,1,0)
                   }
               }
           }
       }

       //************************************************************************
       //************************************************************************


       MFrame{ // Motor3
           width: parent.width * 0.5
           height: parent.height * 0.25
           visible: _joint
           Grid{
               width: parent.width
               height: parent.height
               columns: 4
               spacing: 0
               Label{
                   width: parent.width * 0.15
                   height: parent.height
                   horizontalAlignment: Text.AlignHCenter
                   verticalAlignment: Text.AlignVCenter
                   text: "<b>" + _nameJoint[2] + "</b>"
                   color: "#21be2b"
               }
               MButton{
                   _width: parent.width * 0.15
                   _height: parent.height
                   _text:"-"
                   onBtnPress: {
                       jogviewmodel.jogJoint(1,2,1)
                   }
                   onBtnReleased: {
                       jogviewmodel.jogJoint(1,2,0)
                   }
               }

              Label{
                  width: parent.width * 0.55
                  height: parent.height
                  horizontalAlignment: Text.AlignHCenter
                  verticalAlignment: Text.AlignVCenter
                  text: jogviewmodel.ActualPosition[2].toFixed(3)
                  color: "#21be2b"
              }
               MButton{
                   _width: parent.width * 0.15
                   _height: parent.height
                   _text:"+"
                   onBtnPress: {
                       jogviewmodel.jogJoint(0,2,1)
                   }
                   onBtnReleased: {
                       jogviewmodel.jogJoint(0,2,0)
                   }
               }
           }
       }

       //************************************************************************
       //************************************************************************


       MFrame{ // Motor4
           width: parent.width * 0.5
           height: parent.height * 0.25
           visible: _joint
           Grid{
               width: parent.width
               height: parent.height
               columns: 4
               spacing: 0
               Label{
                   width: parent.width * 0.15
                   height: parent.height
                   horizontalAlignment: Text.AlignHCenter
                   verticalAlignment: Text.AlignVCenter
                   text: "<b>" + _nameJoint[3] + "</b>"
                   color: "#21be2b"
               }
               MButton{
                   _width: parent.width * 0.15
                   _height: parent.height
                   _text:"-"
                   onBtnPress: {
                       jogviewmodel.jogJoint(0,3,1)
                   }
                   onBtnReleased: {
                       jogviewmodel.jogJoint(0,3,0)
                   }
               }

              Label{
                  width: parent.width * 0.55
                  height: parent.height
                  horizontalAlignment: Text.AlignHCenter
                  verticalAlignment: Text.AlignVCenter
                  text: jogviewmodel.ActualPosition[3].toFixed(3)
                  color: "#21be2b"
              }
               MButton{
                   _width: parent.width * 0.15
                   _height: parent.height
                   _text:"+"
                   onBtnPress: {
                       jogviewmodel.jogJoint(1,3,1)
                   }
                   onBtnReleased: {
                       jogviewmodel.jogJoint(1,3,0)
                   }
               }
           }
       }

       //************************************************************************
       //************************************************************************


       MFrame{ // Motor5
           width: parent.width * 0.5
           height: parent.height * 0.25
           visible: _joint
           Grid{
               width: parent.width
               height: parent.height
               columns: 4
               spacing: 0
               Label{
                   width: parent.width * 0.15
                   height: parent.height
                   horizontalAlignment: Text.AlignHCenter
                   verticalAlignment: Text.AlignVCenter
                   text: "<b>" + _nameJoint[4] + "</b>"
                   color: "#21be2b"
               }
               MButton{
                   _width: parent.width * 0.15
                   _height: parent.height
                   _text:"-"
                   onBtnPress: {
                       jogviewmodel.jogJoint(0,4,1)
                   }
                   onBtnReleased: {
                       jogviewmodel.jogJoint(0,4,0)
                   }
               }

              Label{
                  width: parent.width * 0.55
                  height: parent.height
                  horizontalAlignment: Text.AlignHCenter
                  verticalAlignment: Text.AlignVCenter
                  text: jogviewmodel.ActualPosition[4].toFixed(3)
                  color: "#21be2b"
              }
               MButton{
                   _width: parent.width * 0.15
                   _height: parent.height
                   _text:"+"
                   onBtnPress: {
                       jogviewmodel.jogJoint(1,4,1)
                   }
                   onBtnReleased: {
                       jogviewmodel.jogJoint(1,4,0)
                   }
               }
           }
       }

       //************************************************************************
       //************************************************************************


       MFrame{ // Motor6
           width: parent.width * 0.5
           height: parent.height * 0.25
           visible: _joint
           Grid{
               width: parent.width
               height: parent.height
               columns: 4
               spacing: 0
               Label{
                   width: parent.width * 0.15
                   height: parent.height
                   horizontalAlignment: Text.AlignHCenter
                   verticalAlignment: Text.AlignVCenter
                   text: "<b>" + _nameJoint[5] + "</b>"
                   color: "#21be2b"
               }
               MButton{
                   _width: parent.width * 0.15
                   _height: parent.height
                   _text:"-"
                   onBtnPress: {
                       jogviewmodel.jogJoint(1,5,1)
                   }
                   onBtnReleased: {
                       jogviewmodel.jogJoint(1,5,0)
                   }
               }

              Label{
                  width: parent.width * 0.55
                  height: parent.height
                  horizontalAlignment: Text.AlignHCenter
                  verticalAlignment: Text.AlignVCenter
                  text: jogviewmodel.ActualPosition[5].toFixed(3)
                  color: "#21be2b"
              }
               MButton{
                   _width: parent.width * 0.15
                   _height: parent.height
                   _text:"+"
                   onBtnPress: {
                       jogviewmodel.jogJoint(0,5,1)
                   }
                   onBtnReleased: {
                       jogviewmodel.jogJoint(0,5,0)
                   }
               }
           }
       }


       //************************************************************************
       //************************************************************************
       //************************************************************************
       //************************************************************************


       //Cartesian
       MFrame{ //Motor1
           width: parent.width * 0.5
           height: parent.height * 0.25
           visible: !_joint
           Grid{
               width: parent.width
               height: parent.height
               columns: 4
               spacing: 0
               Label{
                   width: parent.width * 0.15
                   height: parent.height
                   horizontalAlignment: Text.AlignHCenter
                   verticalAlignment: Text.AlignVCenter
                   text: "<b>" + _nameCartesian[0] + "</b>"
                   color: "#21be2b"
               }
               MButton{
                   _width: parent.width * 0.15
                   _height: parent.height
                   _text:"-"
                   onBtnPress: {
                       jogviewmodel.jogCart(0,0,1)
                   }
                   onBtnReleased: {
                       jogviewmodel.jogCart(0,0,0)
                   }
               }

              Label{
                  width: parent.width * 0.55
                  height: parent.height
                  horizontalAlignment: Text.AlignHCenter
                  verticalAlignment: Text.AlignVCenter
                  text:  jogviewmodel.ActualPosition[0].toFixed(3)
                  color: "#21be2b"
              }
               MButton{
                   _width: parent.width * 0.15
                   _height: parent.height
                   _text:"+"
                   onBtnPress: {
                       jogviewmodel.jogCart(1,0,1)
                   }
                   onBtnReleased: {
                       jogviewmodel.jogCart(1,0,0)
                   }
               }
           }
       }

       //************************************************************************
       //************************************************************************


       MFrame{//Motor2
           width: parent.width * 0.5
           height: parent.height * 0.25
           visible: !_joint
           Grid{
               width: parent.width
               height: parent.height
               columns: 4
               spacing: 0
               Label{
                   width: parent.width * 0.15
                   height: parent.height
                   horizontalAlignment: Text.AlignHCenter
                   verticalAlignment: Text.AlignVCenter
                   text: "<b>" + _nameCartesian[1] + "</b>"
                   color: "#21be2b"
               }
               MButton{
                   _width: parent.width * 0.15
                   _height: parent.height
                   _text:"-"
                   onBtnPress: {
                       jogviewmodel.jogCart(0,1,1)
                   }
                   onBtnReleased: {
                       jogviewmodel.jogCart(0,1,0)
                   }
               }

              Label{
                  width: parent.width * 0.55
                  height: parent.height
                  horizontalAlignment: Text.AlignHCenter
                  verticalAlignment: Text.AlignVCenter
                  text: jogviewmodel.ActualPosition[1].toFixed(3)
                  color: "#21be2b"
              }
               MButton{
                   _width: parent.width * 0.15
                   _height: parent.height
                   _text:"+"
                   onBtnPress: {
                       jogviewmodel.jogCart(1,1,1)
                   }
                   onBtnReleased: {
                       jogviewmodel.jogCart(1,1,0)
                   }
               }
           }
       }

       //************************************************************************
       //************************************************************************


       MFrame{//Motor3
           width: parent.width * 0.5
           height: parent.height * 0.25
           visible: !_joint
           Grid{
               width: parent.width
               height: parent.height
               columns: 4
               spacing: 0
               Label{
                   width: parent.width * 0.15
                   height: parent.height
                   horizontalAlignment: Text.AlignHCenter
                   verticalAlignment: Text.AlignVCenter
                   text: "<b>" + _nameCartesian[2] + "</b>"
                   color: "#21be2b"
               }
               MButton{
                   _width: parent.width * 0.15
                   _height: parent.height
                   _text:"-"
                   onBtnPress: {
                       jogviewmodel.jogCart(0,2,1)
                   }
                   onBtnReleased: {
                       jogviewmodel.jogCart(0,2,0)
                   }
               }

              Label{
                  width: parent.width * 0.55
                  height: parent.height
                  horizontalAlignment: Text.AlignHCenter
                  verticalAlignment: Text.AlignVCenter
                  text: jogviewmodel.ActualPosition[2].toFixed(3)
                  color: "#21be2b"
              }
               MButton{
                   _width: parent.width * 0.15
                   _height: parent.height
                   _text:"+"
                   onBtnPress: {
                       jogviewmodel.jogCart(1,2,1)
                   }
                   onBtnReleased: {
                       jogviewmodel.jogCart(1,2,0)
                   }
               }
           }
       }

       //************************************************************************
       //************************************************************************


       MFrame{ //Motor4
           width: parent.width * 0.5
           height: parent.height * 0.25
           visible: !_joint
           Grid{
               width: parent.width
               height: parent.height
               columns: 4
               spacing: 0
               Label{
                   width: parent.width * 0.15
                   height: parent.height
                   horizontalAlignment: Text.AlignHCenter
                   verticalAlignment: Text.AlignVCenter
                   text: "<b>" + _nameCartesian[3] + "</b>"
                   color: "#21be2b"
               }
               MButton{
                   _width: parent.width * 0.15
                   _height: parent.height
                   _text:"-"
                   onBtnPress: {
                       jogviewmodel.jogCart(0,3,1)
                   }
                   onBtnReleased: {
                       jogviewmodel.jogCart(0,3,0)
                   }
               }

              Label{
                  width: parent.width * 0.55
                  height: parent.height
                  horizontalAlignment: Text.AlignHCenter
                  verticalAlignment: Text.AlignVCenter
                  text: jogviewmodel.ActualPosition[3].toFixed(3)
                  color: "#21be2b"
              }
               MButton{
                   _width: parent.width * 0.15
                   _height: parent.height
                   _text:"+"
                   onBtnPress: {
                       jogviewmodel.jogCart(1,3,1)
                   }
                   onBtnReleased: {
                       jogviewmodel.jogCart(1,3,0)
                   }
               }
           }
       }

       //************************************************************************
       //************************************************************************


       MFrame{//Motor5
           width: parent.width * 0.5
           height: parent.height * 0.25
           visible: !_joint
           Grid{
               width: parent.width
               height: parent.height
               columns: 4
               spacing: 0
               Label{
                   width: parent.width * 0.15
                   height: parent.height
                   horizontalAlignment: Text.AlignHCenter
                   verticalAlignment: Text.AlignVCenter
                   text: "<b>" + _nameCartesian[4] + "</b>"
                   color: "#21be2b"
               }
               MButton{
                   _width: parent.width * 0.15
                   _height: parent.height
                   _text:"-"
                   onBtnPress: {
                       jogviewmodel.jogCart(0,4,1)
                   }
                   onBtnReleased: {
                       jogviewmodel.jogCart(0,4,0)
                   }
               }

              Label{
                  width: parent.width * 0.55
                  height: parent.height
                  horizontalAlignment: Text.AlignHCenter
                  verticalAlignment: Text.AlignVCenter
                  text: jogviewmodel.ActualPosition[4].toFixed(3)
                  color: "#21be2b"
              }
               MButton{
                   _width: parent.width * 0.15
                   _height: parent.height
                   _text:"+"
                   onBtnPress: {
                       jogviewmodel.jogCart(1,4,1)
                   }
                   onBtnReleased: {
                       jogviewmodel.jogCart(1,4,0)
                   }
               }
           }
       }

       //************************************************************************
       //************************************************************************


       MFrame{//Motor6
           width: parent.width * 0.5
           height: parent.height * 0.25
           visible: !_joint
           Grid{
               width: parent.width
               height: parent.height
               columns: 4
               spacing: 0
               Label{
                   width: parent.width * 0.15
                   height: parent.height
                   horizontalAlignment: Text.AlignHCenter
                   verticalAlignment: Text.AlignVCenter
                   text: "<b>" + _nameCartesian[5] + "</b>"
                   color: "#21be2b"
               }
               MButton{
                   _width: parent.width * 0.15
                   _height: parent.height
                   _text:"-"
                   onBtnPress: {
                       jogviewmodel.jogCart(0,5,1)
                   }
                   onBtnReleased: {
                       jogviewmodel.jogCart(0,5,0)
                   }
               }

              Label{
                  width: parent.width * 0.55
                  height: parent.height
                  horizontalAlignment: Text.AlignHCenter
                  verticalAlignment: Text.AlignVCenter
                  text:  jogviewmodel.ActualPosition[5].toFixed(3)
                  color: "#21be2b"
              }
               MButton{
                   _width: parent.width * 0.15
                   _height: parent.height
                   _text:"+"
                   onBtnPress: {
                       jogviewmodel.jogCart(1,5,1)
                   }
                   onBtnReleased: {
                       jogviewmodel.jogCart(1,5,0)
                   }
               }
           }
       }

       //************************************************************************
       //************************************************************************



   }
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
