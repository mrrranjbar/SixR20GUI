import QtQuick 2.9
import QtQuick.Controls 2.2
import MainViewModel 1.0


Item {
    property bool _is_prj_started: false
    Resource
    {
        id:rsc
    }
    property CodeWindow codeWindow: myCodeWindow
    //    MFrame{
    //        anchors.fill: parent


    //    }
    Component.onCompleted: {
        poweron._isActive = mainview1.IsPowerOn
    }
    Grid{
        anchors.fill: parent
        rows: 2
        spacing: 5
        leftPadding: 5
        topPadding: 5
        Grid{
            //anchors.fill: parent
            height: parent.height*0.15
            width: parent.width - 10
            columns: 3
            spacing: 5
            MButton {

                            id : poweron
                            _text: "Power On / Off"
                            _width:parent.width * 0.33
                            onBtnClick: {
                                mainview1.PowerOnClicked()
                                if(mainview1.IsPowerOn)
                                {
                                    poweron._isActive = true
                                }
                                else
                                {
                                    poweron._isActive = false
                                }
                            }
            }
            MButton {
                            id : run
                            _text: "Run / Ready"
                            _width:parent.width * 0.33
                            onBtnClick: {
                                mainview1.RunClicked()
                                run._isActive = !run._isActive
                            }
            }
            MButton {
                id : home
                _text: "Home Position"
                _width:parent.width * 0.33
                onBtnClick: {
                    mainview1.HomePositionClicked()
                    //home._isActive = true
                }
            }
        }
        MFrame
        {
            width: parent.width - 9
            height: parent.height*0.85 - 10
            CodeWindow{
                id: myCodeWindow
            }

            //            Label{
            //                width: parent.width
            //                height: parent.height
            //                horizontalAlignment: Text.AlignHCenter
            //                verticalAlignment: Text.AlignVCenter
            //                text: "<b>" + "CODES" + "</b>"
            //                color: "#EFECCA"
            //            }
        }
    }
    MainViewModel {
        id: mainview1
        onStartedPrj:
        {
            //console.log("hiiiiiiiiiiiiiiihihiihihi")
            _is_prj_started=true
        }
        onEndedPrj:
        {
            _is_prj_started=false
        }
    }

}

