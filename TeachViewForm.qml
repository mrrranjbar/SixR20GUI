import QtQuick 2.7
import QtQuick.Controls 2.2
//123
Item {
    Grid{
        width: parent.width
        height: parent.height
        rows: 2
        spacing: 4


        MFrame{

            width: parent.width
            height: parent.height * 0.15


            Grid // top Grid
            {
                width: parent.width
                height: parent.height
                columns: 4
                spacing: 1
//                rightPadding: 3

                MButton {
                    id: btn_jog
                    _text: "Jog"
                    _height: parent.height * 0.5
                    _width:parent.width * 1/4
                    _isActive:true
                    onBtnClick: {
                        _title = "JogView"
                        //************************
                        _isActive=true
                        btn_position._isActive=false
                        //btn_inching._isActive=false
                        btn_teachpoint._isActive=false
                        btn_scoordinate._isActive = false
                        //************************
                        stackView1.pop()
                        stackView1.push("JogViewForm.qml")
                    }
                }
                MButton {
                    id: btn_position
                    _text: "Position"
                    _height:parent.height * 0.5
                    _width:parent.width * 1/4
                    onBtnClick: {
                        _title = "PositionView"
                        //************************
                        _isActive=true
                        btn_jog._isActive=false
                        //btn_inching._isActive=false
                        btn_teachpoint._isActive=false
                        btn_scoordinate._isActive = false
                        //************************
                        stackView1.pop()
                        stackView1.push("PositionViewForm.qml")
                    }
                }
//                MButton {
//                    id: btn_inching
//                    _text: "Inching"
//                    _height: parent.height * 0.5
//                    _width:parent.width * 1/5
//                    onBtnClick: {
//                        _title = "InchingView"
//                        //************************
//                        _isActive=true
//                        btn_position._isActive=false
//                        btn_jog._isActive=false
//                        btn_teachpoint._isActive=false
//                        btn_scoordinate._isActive = false
//                        //************************
//                        stackView1.pop()
//                        stackView1.push("JogViewForm.qml")
//                    }
//                }
                MButton {
                    id: btn_scoordinate
                    _text: "Frame"
                    _height: parent.height * 0.5
                    _width:parent.width * 1/4
                    onBtnClick: {
                        _title = "TeachFrame"
                        //************************
                        _isActive=true
                        btn_position._isActive=false
                        //btn_inching._isActive=false
                        btn_jog._isActive=false
                        btn_teachpoint._isActive=false
                        //************************
                        stackView1.pop()
                        stackView1.push("ScoordinatesViewForm.qml")
                    }
                }

                MButton {
                    id: btn_teachpoint
                    _text: "Teach Point"
                    _height: parent.height * 0.5
                    _width:parent.width * 1/4
                    onBtnClick: {
                        _title = "TeachPointView"
                        //************************
                        _isActive=true
                        btn_position._isActive=false
                        //btn_inching._isActive=false
                        btn_jog._isActive=false
                        btn_scoordinate._isActive = false
                        //************************
                        stackView1.pop()
                        stackView1.push("TeachPointViewForm.qml")
                    }
                }

            }
        }
        MFrame{

            width: parent.width
            height: parent.height * 0.84

            Grid // bottom Grid
            {
                width: parent.width
                height: parent.height
                columns:1
                StackView {
                    id: stackView1
                    width: parent.width
                    height: parent.height
                    initialItem: "JogViewForm.qml"
                }

            }
        }
    }
}
