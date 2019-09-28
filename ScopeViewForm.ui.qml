import QtQuick 2.4
import QtQuick.Controls 2.2
import ScopeViewModel 1.0
import CustomPlot 1.0
import QCustomPlot 1.0
import JogViewModel 1.0

Item {

    ScopeViewModel {
        id: scopeViewModel
    }
    Grid {
        width: parent.width
        height: parent.height
        rows: 2
        spacing: 4
        MFrame {

            width: parent.width
            height: parent.height * 0.15

            Grid // top Grid
            {
                width: parent.width
                height: parent.height
                columns: 7
                spacing: 1

                //                rightPadding: 3
                MButton {
                    id: btn_motor1
                    _text: "motor 1"
                    _height: parent.height * 0.5
                    _width: parent.width * 1 / 7
                    _isActive: true
                    onBtnClick: {
                        _title = "motor 1"
                        //************************
                        _isActive = true
                        btn_motor2._isActive = false
                        btn_motor3._isActive = false
                        btn_motor4._isActive = false
                        btn_motor5._isActive = false
                        btn_motor6._isActive = false
                        btn_all._isActive = false
                        //************************
                        //                            stackView1.pop()
                        //                            stackView1.push("JogViewForm.ui.qml")
                        scopeViewModel.setMotorNum(0)
                        customPlot.setMotorNum(0)
                        customPlot.motorNumChanged(0)
                    }
                }
                MButton {
                    id: btn_motor2
                    _text: "motor 2"
                    _height: parent.height * 0.5
                    _width: parent.width * 1 / 7
                    onBtnClick: {
                        _title = "motor 2"
                        //************************
                        _isActive = true
                        btn_motor1._isActive = false
                        btn_motor3._isActive = false
                        btn_motor4._isActive = false
                        btn_motor5._isActive = false
                        btn_motor6._isActive = false
                        btn_all._isActive = false
                        scopeViewModel.setMotorNum(1)
                        customPlot.setMotorNum(1)
                        customPlot.motorNumChanged(1)
                    }
                }
                MButton {
                    id: btn_motor3
                    _text: "motor 3"
                    _height: parent.height * 0.5
                    _width: parent.width * 1 / 7
                    onBtnClick: {
                        _title = "motor 3"
                        //************************
                        _isActive = true
                        btn_motor2._isActive = false
                        btn_motor1._isActive = false
                        btn_motor4._isActive = false
                        btn_motor5._isActive = false
                        btn_motor6._isActive = false
                        btn_all._isActive = false
                        scopeViewModel.setMotorNum(2)
                        customPlot.setMotorNum(2)
                        customPlot.motorNumChanged(2)
                    }
                }
                MButton {
                    id: btn_motor4
                    _text: "motor 4"
                    _height: parent.height * 0.5
                    _width: parent.width * 1 / 7
                    onBtnClick: {
                        _title = "motor 4"
                        //************************
                        _isActive = true
                        btn_motor2._isActive = false
                        btn_motor3._isActive = false
                        btn_motor1._isActive = false
                        btn_motor5._isActive = false
                        btn_motor6._isActive = false
                        btn_all._isActive = false
                        scopeViewModel.setMotorNum(3)
                        customPlot.setMotorNum(3)
                        customPlot.motorNumChanged(3)
                    }
                }

                MButton {
                    id: btn_motor5
                    _text: "motor 5"
                    _height: parent.height * 0.5
                    _width: parent.width * 1 / 7
                    onBtnClick: {
                        _title = "motor 5"
                        //************************
                        _isActive = true
                        btn_motor2._isActive = false
                        btn_motor3._isActive = false
                        btn_motor4._isActive = false
                        btn_motor1._isActive = false
                        btn_motor6._isActive = false
                        btn_all._isActive = false
                        scopeViewModel.setMotorNum(4)
                        customPlot.setMotorNum(4)
                        customPlot.motorNumChanged(4)
                    }
                }
                MButton {
                    id: btn_motor6
                    _text: "motor 6"
                    _height: parent.height * 0.5
                    _width: parent.width * 1 / 7
                    onBtnClick: {
                        _title = "motor 6"
                        //************************
                        _isActive = true
                        btn_motor2._isActive = false
                        btn_motor3._isActive = false
                        btn_motor4._isActive = false
                        btn_motor5._isActive = false
                        btn_motor1._isActive = false
                        btn_all._isActive = false
                        scopeViewModel.setMotorNum(5)
                        customPlot.setMotorNum(5)
                        customPlot.motorNumChanged(5)

                    }
                }
                MButton {
                    id: btn_all
                    _text: "all"
                    _height: parent.height * 0.5
                    _width: parent.width * 1 / 7
                    onBtnClick: {
                        _title = "all"
                        //************************
                        _isActive = true
                        btn_motor2._isActive = false
                        btn_motor3._isActive = false
                        btn_motor4._isActive = false
                        btn_motor5._isActive = false
                        btn_motor1._isActive = false
                        btn_motor6._isActive = false
//                        scopeViewModel.setMotorNum(5)
//                        customPlot.setMotorNum(5)
//                        customPlot.motorNumChanged(5)

                    }
                }
            }
        }
        MFrame {

            width: parent.width
            height: parent.height * 0.84
            Grid {
                // bottom Grid
                width: parent.width
                height: parent.height
                columns: 1
                rows: 3

                CustomPlotItem {
                    visible: !btn_all._isActive
                    id: customPlot
                    width: parent.width
                    height: parent.height * .85
                    Component.onCompleted: initCustomPlot()
                }
                Grid{

                    width: parent.width
                    height: parent.height * .85
                    visible: btn_all._isActive
                    columns: 3
                    rows: 2

                    CustomPlotItem {

                        id: customPlot1
                        width: parent.width /3
                        height: parent.height /2
                        Component.onCompleted: initCustomPlotall(0)
                    }
                    CustomPlotItem {

                        id: customPlot2
                        width: parent.width /3
                        height: parent.height /2
                        Component.onCompleted: initCustomPlotall(1)
                    }
                    CustomPlotItem {

                        id: customPlot3
                        width: parent.width /3
                        height: parent.height /2
                        Component.onCompleted: initCustomPlotall(2)
                    }
                    CustomPlotItem {

                        id: customPlot4
                        width: parent.width /3
                        height: parent.height /2
                        Component.onCompleted: initCustomPlotall(3)
                    }
                    CustomPlotItem {

                        id: customPlot5
                        width: parent.width /3
                        height: parent.height /2
                        Component.onCompleted: initCustomPlotall(4)
                    }
                    CustomPlotItem {

                        id: customPlot6
                        width: parent.width /3
                        height: parent.height /2
                        Component.onCompleted: initCustomPlotall(5)
                    }

                }
                Grid {
                    width: parent.width
                    height: parent.height * 0.10
                    columns: 2
                    Label {
                        id: actual
                        //                    width:actual.text.length +20;
                        width: parent.width / 2
                        height: parent.height
                        color: "#5c5cff"
                        text: "Actual Position"
                        verticalAlignment: "AlignVCenter"
                        horizontalAlignment: "AlignHCenter"
                    }
                    Label {
                        id: ideal
                        width: parent.width / 2
                        //                    width:ideal.text.length+20;
                        height: parent.height
                        color: "#ff5c5c"
                        text: "Desired Position"
                        verticalAlignment: "AlignVCenter"
                        horizontalAlignment: "AlignHCenter"
                    }
                    //                    MButton{
                    //                        _width: parent.width * 0.15
                    //                        _height: 25
                    //                        _text:"-"
                    //                        onBtnPress: {
                    //                            //jogviewmodel.jogJoint(0,5,1)
                    //                            customPlot.stop = true
                    //                        }
                    //                        onBtnReleased: {
                    //                            //jogviewmodel.jogJoint(0,5,0)
                    //                            customPlot.stop = false
                    //                        }
                    //                    }
                }
                MFrame {

                    width: parent.width
                    height: parent.height * 0.15
                    anchors.bottom: parent.bottom
                    topPadding: 3
                    bottomPadding: 3
                    Grid {
                        width: parent.width
                        height: parent.height
                        columns: 5
                        spacing: 6
                        ComboBox {
                            id: mode
//                            width: parent.width / 5
                            height: parent.height
//                            anchors.margins : 0
                            model: ListModel {
                                ListElement {
                                    text: "PTP Cartesian"
                                }
                                ListElement {
                                    text: "Linear"
                                }

//                                ListElement {
//                                    text: "PTP Joint"
//                                }
//                                ListElement {
//                                    text: "Circle"
//                                }
                            }
                        }
                        ComboBox {
                            id: teachpoint
//                            Component.onCompleted: scopeViewModel.intializeTeachPoint()
//                            width: parent.width / 5
                            height: parent.height
                            model: TeachPointModel
                            delegate: ItemDelegate {
                                width: parent.width
                                text: model.name
                            }
                            displayText: TeachPointModel[currentIndex].name
                        }
                        MButton {
//                            width: 50
                            height: parent.height * .85
//                            anchors.horizontalCenter: parent
                            _text: "start"
                            onBtnClick: {
                                scopeViewModel.run(mode.currentText,
                                                   teachpoint.currentIndex)
                                customPlot.startCustomPlot()
                                customPlot1.startCustomPlot()
                                customPlot2.startCustomPlot()
                                customPlot3.startCustomPlot()
                                customPlot4.startCustomPlot()
                                customPlot5.startCustomPlot()
                                customPlot6.startCustomPlot()
                            }
                        }
                        MButton {
//                            width: 50
//                            anchors.horizontalCenter: parent.horizontalCenter
                            height: parent.height * .85
                            _text: "stop"
                            onBtnClick: {
                                customPlot.stopCustomPlot()

                                customPlot1.stopCustomPlot()
                                customPlot2.stopCustomPlot()
                                customPlot3.stopCustomPlot()
                                customPlot4.stopCustomPlot()
                                customPlot5.stopCustomPlot()
                                customPlot6.stopCustomPlot()
                            }
                        }
                        ComboBox {
//                            Component.onCompleted: scopeViewModel.intializeTeachPoint()
//                            width: parent.width / 5
                            height: parent.height
                            id:type
                            model: ListModel {
                                ListElement {
                                    text: "Position"
                                }
                                ListElement {
                                    text: "Velocity"
                                }
                                ListElement {
                                    text: "Acceleration"
                                }
                            }
                            onCurrentIndexChanged:customPlot.setShowType(type.currentIndex)
                        }
                    }
                }
            }
        }
    }
}










/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
