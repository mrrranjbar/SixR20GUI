import QtQuick 2.7
import QtQuick.Controls 2.2
import PositionViewModel 1.0

Item {

    id:mainitem
    property int _width: 260
    property int _height: 75

    PositionViewModel
    {
        id:positionviewmodel
    }

    Grid{ // main grid
        width: parent.width
        height: parent.height * 9/10
        columns: 2
        spacing: 5

        //***************************************************************
        //***************************************************************

        MFrame{ // Motor1
            width: parent.width * 0.5
            height: parent.height * 0.25
            Grid{
                width: parent.width
                height: parent.height
                columns: 3
                spacing: 0
                Label{
                    width: parent.width * 1/3
                    height: parent.height
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "<b> M1 </b>"
                    color: "#21be2b"
                }

              TextInput {
                   id: mTextField1
                   width: parent.width * 1/3
                   height:parent.height
                   horizontalAlignment: Text.AlignHCenter
                   verticalAlignment: Text.AlignVCenter
                   color: "#21be2b"
                   text: "0"
               }
                MButton{
                    _width: parent.width * 1/3
                    _height: parent.height
                    _text:"Go"
                    onBtnClick: {
                        positionviewmodel.setPosition( mTextField1.text,0)
                        //positionviewmodel.Positions[0] = mTextField1._text
                        positionviewmodel.Move(0)
                    }

                }
            }
        }

        //***************************************************************
        //***************************************************************

        MFrame{ // Motor2
            width: parent.width * 0.5
            height: parent.height * 0.25
            Grid{
                width: parent.width
                height: parent.height
                columns: 3
                spacing: 0
                Label{
                    width: parent.width * 1/3
                    height: parent.height
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "<b> M2 </b>"
                    color: "#21be2b"
                }

                TextInput {
                     id: mTextField2
                     width: parent.width * 1/3
                     height:parent.height
                     horizontalAlignment: Text.AlignHCenter
                     verticalAlignment: Text.AlignVCenter
                     color: "#21be2b"
                     text: "0"
                 }
                MButton{
                    _width: parent.width * 1/3
                    _height: parent.height
                    _text:"Go"
                    onBtnClick: {
                        positionviewmodel.setPosition( mTextField2.text,1)
                        //positionviewmodel.Positions[1] = mTextField2._text
                        positionviewmodel.Move(1)
                    }

                }
            }
        }

        //***************************************************************
        //***************************************************************


        MFrame{ // Motor3
            width: parent.width * 0.5
            height: parent.height * 0.25
            Grid{
                width: parent.width
                height: parent.height
                columns: 3
                spacing: 0
                Label{
                    width: parent.width * 1/3
                    height: parent.height
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "<b> M3 </b>"
                    color: "#21be2b"
                }

                TextInput {
                     id: mTextField3
                     width: parent.width * 1/3
                     height:parent.height
                     horizontalAlignment: Text.AlignHCenter
                     verticalAlignment: Text.AlignVCenter
                     color: "#21be2b"
                     text: "0"
                 }
                MButton{
                    _width: parent.width * 1/3
                    _height: parent.height
                    _text:"Go"
                    onBtnClick: {
                        positionviewmodel.setPosition( mTextField3.text,2)
                        //positionviewmodel.Positions[2] = mTextField3._text
                        positionviewmodel.Move(2)
                    }

                }
            }
        }

        //***************************************************************
        //***************************************************************

        MFrame{ // Motor4
            width: parent.width * 0.5
            height: parent.height * 0.25
            Grid{
                width: parent.width
                height: parent.height
                columns: 3
                spacing: 0
                Label{
                    width: parent.width * 1/3
                    height: parent.height
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "<b> M4 </b>"
                    color: "#21be2b"
                }

                TextInput {
                     id: mTextField4
                     width: parent.width * 1/3
                     height:parent.height
                     horizontalAlignment: Text.AlignHCenter
                     verticalAlignment: Text.AlignVCenter
                     color: "#21be2b"
                     text: "0"
                 }
                MButton{
                    _width: parent.width * 1/3
                    _height: parent.height
                    _text:"Go"
                    onBtnClick: {
                        positionviewmodel.setPosition( mTextField4.text,3)
                        //positionviewmodel.Positions[3] = mTextField4._text
                        positionviewmodel.Move(3)
                    }

                }
            }
        }

        //***************************************************************
        //***************************************************************


        MFrame{ // Motor5
            width: parent.width * 0.5
            height: parent.height * 0.25
            Grid{
                width: parent.width
                height: parent.height
                columns: 3
                spacing: 0
                Label{
                    width: parent.width * 1/3
                    height: parent.height
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "<b> M5 </b>"
                    color: "#21be2b"
                }

                TextInput {
                     id: mTextField5
                     width: parent.width * 1/3
                     height:parent.height
                     horizontalAlignment: Text.AlignHCenter
                     verticalAlignment: Text.AlignVCenter
                     color: "#21be2b"
                     text: "0"
                 }
                MButton{
                    _width: parent.width * 1/3
                    _height: parent.height
                    _text:"Go"
                    onBtnClick: {
                        positionviewmodel.setPosition( mTextField5.text,4)
                        //positionviewmodel.Positions[4] = mTextField5._text
                        positionviewmodel.Move(4)
                    }

                }
            }
        }

        //***************************************************************
        //***************************************************************

        MFrame{ // Motor6
            width: parent.width * 0.5
            height: parent.height * 0.25
            Grid{
                width: parent.width
                height: parent.height
                columns: 3
                spacing: 0
                Label{
                    width: parent.width * 1/3
                    height: parent.height
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "<b> M6 </b>"
                    color: "#21be2b"
                }

                TextInput {
                     id: mTextField6
                     width: parent.width * 1/3
                     height:parent.height
                     horizontalAlignment: Text.AlignHCenter
                     verticalAlignment: Text.AlignVCenter
                     color: "#21be2b"
                     text: "0"
                 }
                MButton{
                    _width: parent.width * 1/3
                    _height: parent.height
                    _text:"Go"
                    onBtnClick: {
                        positionviewmodel.setPosition( mTextField6.text,5)
                        //positionviewmodel.Positions[5] = mTextField6._text
                        positionviewmodel.Move(5)
                    }

                }
            }
        }

        //***************************************************************
        //***************************************************************



        MButton{
            _width: parent.width * 0.5
            _height:parent.height * 0.25
            _text:"Move All"
            onBtnClick: {
                positionviewmodel.setPosition( mTextField1.text,0)
                positionviewmodel.setPosition( mTextField2.text,1)
                positionviewmodel.setPosition( mTextField3.text,2)
                positionviewmodel.setPosition( mTextField4.text,3)
                positionviewmodel.setPosition( mTextField5.text,4)
                positionviewmodel.setPosition( mTextField6.text,5)

//                positionviewmodel.Positions[0] = mTextField1._text
//                positionviewmodel.Positions[1] = mTextField2._text
//                positionviewmodel.Positions[2] = mTextField3._text
//                positionviewmodel.Positions[3] = mTextField4._text
//                positionviewmodel.Positions[4] = mTextField5._text
//                positionviewmodel.Positions[5] = mTextField6._text
                positionviewmodel.MoveAll()
            }

        }
        MButton{
            _width: parent.width * 0.5
            _height: parent.height * 0.25
            _text:"Go Home"
            onBtnClick: {
                positionviewmodel.GoHome()
            }

        }
    }

}
