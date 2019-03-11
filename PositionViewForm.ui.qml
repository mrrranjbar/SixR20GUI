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

        MFrame{ // Motor1
            width: _width
            height: _height
            Grid{
                width: _width
                height: _height
                columns: 3
                spacing: 0
                Label{
                    width: 30
                    height: 50
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "<b> M1 </b>"
                    color: "#21be2b"
                }

               MTextField{
                   id: mTextField1
                   _width:150
                   _height:60
                   _placeholderText: "Enter Position"
                   onTextChanged: {
                    positionviewmodel.Positions[0] = mTextField1._text
                   }
               }
                MButton{
                    _width: 50
                    _height: 50
                    _text:"Go"
                    onBtnClick: {
                        positionviewmodel.Move(0);
                    }

                }
            }
        }
        MFrame{ // Motor2
            width: _width
            height: _height
            Grid{
                width: _width
                height: _height
                columns: 3
                spacing: 0
                Label{
                    width: 30
                    height: 50
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "<b> M2 </b>"
                    color: "#21be2b"
                }

               MTextField{
                   id: mTextField2
                   _width:150
                   _height:60
                   _placeholderText: "Enter Position"
                   onTextChanged: {
                    positionviewmodel.Positions[1] = mTextField2._text
                   }
               }
                MButton{
                    _width: 50
                    _height: 50
                    _text:"Go"
                    onBtnClick: {
                        positionviewmodel.Move(1);
                    }

                }
            }
        }
        MFrame{ // Motor3
            width: _width
            height: _height
            Grid{
                width: _width
                height: _height
                columns: 3
                spacing: 0
                Label{
                    width: 30
                    height: 50
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "<b> M3 </b>"
                    color: "#21be2b"
                }

               MTextField{
                   id: mTextField3
                   _width:150
                   _height:60
                   _placeholderText: "Enter Position"
                   onTextChanged: {
                    positionviewmodel.Positions[2] = mTextField3._text
                   }
               }
                MButton{
                    _width: 50
                    _height: 50
                    _text:"Go"
                    onBtnClick: {
                        positionviewmodel.Move(2);
                    }

                }
            }
        }
        MFrame{ // Motor4
            width: _width
            height: _height
            Grid{
                width: _width
                height: _height
                columns: 3
                spacing: 0
                Label{
                    width: 30
                    height: 50
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "<b> M4 </b>"
                    color: "#21be2b"
                }

               MTextField{
                   id: mTextField4
                   _width:150
                   _height:60
                   _placeholderText: "Enter Position"
                   onTextChanged: {
                    positionviewmodel.Positions[3] = mTextField4._text
                   }
               }
                MButton{
                    _width: 50
                    _height: 50
                    _text:"Go"
                    onBtnClick: {
                        positionviewmodel.Move(3);

                    }

                }
            }
        }
        MFrame{ // Motor5
            width: _width
            height: _height
            Grid{
                width: _width
                height: _height
                columns: 3
                spacing: 0
                Label{
                    width: 30
                    height: 50
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "<b> M5 </b>"
                    color: "#21be2b"
                }

               MTextField{
                   id: mTextField5
                   _width:150
                   _height:60
                   _placeholderText: "Enter Position"
                   onTextChanged: {
                    positionviewmodel.Positions[4] = mTextField5._text
                   }
               }
                MButton{
                    _width: 50
                    _height: 50
                    _text:"Go"
                    onBtnClick: {
                        positionviewmodel.Move(4);

                    }

                }
            }
        }
        MFrame{ // Motor6
            width: _width
            height: _height
            Grid{
                width: _width
                height: _height
                columns: 3
                spacing: 0
                Label{
                    width: 30
                    height: 50
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "<b> M6 </b>"
                    color: "#21be2b"
                }

               MTextField{
                   id: mTextField6
                   _width:150
                   _height:60
                   _placeholderText: "Enter Position"
                   onTextChanged: {
                    positionviewmodel.Positions[5] = mTextField6._text
                   }
               }
                MButton{
                    _width: 50
                    _height: 50
                    _text:"Go"
                    onBtnClick: {
                        positionviewmodel.Move(5);
                    }

                }
            }
        }

        MButton{
            _width: mainitem._width
            _height:50
            _text:"Move All"
            onBtnClick: {
                positionviewmodel.MoveAll()
            }

        }
        MButton{
            _width: mainitem._width
            _height: 50
            _text:"Go Home"
            onBtnClick: {
                positionviewmodel.GoHome()
            }

        }
    }

}
