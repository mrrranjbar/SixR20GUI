import QtQuick 2.9
import ServoPRMViewModel 1.0
import QtQuick.Controls 1.4

Item {
    id: element
    property var titleNames: ["Motor", "Absolute Encoder", "Inertia Ratio Setting", "Position P Gain1", "Position P Gain2", "Pos Filter Command Time Constant", "Position Feed-Forward Gain", "Notch Filter
Use", "Notch Filter Frequency", "Notch Filter Bandwidth"]
    ServoPRMViewModel {
        id: servoprmviewmodel
    }
    ScrollView {
        anchors.fill: parent

        Flickable {
            contentHeight: topGrid.height
            contentWidth: topGrid.width
            height: 390
            Grid {
                //main grid for both gain and
                width: 690
                height: 550
                id: topGrid
                rows: 12
                columns: 8
                flow: Grid.LeftToRight
                spacing: 4
                MFrame {
                    id: titles
                    width: topGrid.width / 7 +12
                    height: topGrid.height
                    Grid {
                        //titles
                        x: -5
                        y: 0
                        width: topGrid.width / 7
                        height: titles.height
                        verticalItemAlignment: Grid.AlignTop
                        horizontalItemAlignment: Grid.AlignHCenter
                        rows: 12
                        spacing: 1
                        Repeater {
                            width: titles.width
                            height: titles.height
                            model: 10
                            Label {
                                width: titles.width // 12+3
                                height: titles.height / 10 - 5
                                text: "<b>" + titleNames[index] + "<\b>"
                                wrapMode: Label.WordWrap
                                color: "#EFECCA"
                                font.pointSize: 10
                            }
                        }
                    }
                }

                Repeater {

                    model: 6
                    MFrame {
                        id: motorFrame
                        width: topGrid.width / 7 - 2
                        height: topGrid.height
                        property int mIndex: index
                        property var mParam: ({

                                              })
                        Grid {
                            id: r4g
                            rows: 13
                            width: topGrid.width / 7 -2
                            height: topGrid.height
                            flow: Grid.TopToBottom
                            horizontalItemAlignment: Grid.AlignHCenter
                            verticalItemAlignment: Grid.AlignVCenter
                            spacing: 1
                            Label {
                                width: topGrid.width
                                height: topGrid.height / 10
                                text: "<b>  " + (mIndex + 1) + "<\b>"
                                color: "#EFECCA"
                            }
                            MButton {

                                width: topGrid.width
                                height: topGrid.height / 10
                                _text: "Reset"
                                _width: topGrid.width / 11
                                _height: topGrid.height / 24 // 12
                                onBtnClick: {

                                    servoprmviewmodel.resetAbsoluteEncoder()
                                }
                            }

                            TextInput{
                                id:mytext0
                                height: topGrid.height / 10 -8
                                width: topGrid.width
                                text: ""+servoprmviewmodel.InertiaRatioSetting[mIndex]//Parameters[mIndex][index]
                                color: "#EFECCA"
                                validator: IntValidator {
                                    bottom: 0
                                    top: 65535
                                }
                                onEditingFinished:{
                                    mParam[0] = parseInt(mytext0.text)
                                }
                            }
                            TextInput{
                                id:mytext1

                                height: topGrid.height / 10 -8
                                width: topGrid.width
                                text: ""+servoprmviewmodel.PositionProportionalGain1[mIndex]//Parameters[mIndex][index]
                                color: "#EFECCA"
                                validator: IntValidator {
                                    bottom: 0
                                    top: 65535
                                }
                                onEditingFinished: mParam[1] = parseInt(mytext1.text)
                            }
                            TextInput{
                                id:mytext2
                                height: topGrid.height / 10 -8
                                width: topGrid.width
                                text: ""+servoprmviewmodel.PositionProportionalGain2[mIndex]
                                color: "#EFECCA"
                                validator: IntValidator {
                                    bottom: 0
                                    top: 65535
                                }
                                onEditingFinished: mParam[2] = parseInt(mytext2.text)
                            }
                            TextInput{
                                id:mytext3
                                height: topGrid.height / 10 -8
                                width: topGrid.width
                                text: ""+servoprmviewmodel.PositionFilterCommandTimeConstant[mIndex]
                                color: "#EFECCA"
                                validator: IntValidator {
                                    bottom: 0
                                    top: 65535
                                }
                                onEditingFinished: mParam[3] = parseInt(mytext3.text)
                            }
                            TextInput{
                                id:mytext4
                                height: topGrid.height / 10 -8
                                width: topGrid.width
                                text: ""+servoprmviewmodel.PositionFeedForwardGain[mIndex]
                                color: "#EFECCA"
                                validator: IntValidator {
                                    bottom: 0
                                    top: 65535
                                }
                                onEditingFinished: mParam[4] = parseInt(mytext4.text)
                            }
                            TextInput{
                                id:mytext5
                                height: topGrid.height / 10 -8
                                width: topGrid.width
                                text: ""+servoprmviewmodel.NotchFilterUse[mIndex]
                                color: "#EFECCA"
                                validator: IntValidator {
                                    bottom: 0
                                    top: 65535
                                }
                                onEditingFinished: mParam[5] = parseInt(mytext5.text)
                            }
                            TextInput{
                                id:mytext6
                                height: topGrid.height / 10 -8
                                width: topGrid.width
                                text: ""+servoprmviewmodel.NotchFilterFrequency[mIndex]
                                color: "#EFECCA"
                                validator: IntValidator {
                                    bottom: 0
                                    top: 65535
                                }
                                onEditingFinished: mParam[6] = parseInt(mytext6.text)
                            }
                            TextInput{
                                id:mytext7
                                height: topGrid.height / 10 -8
                                width: topGrid.width
                                text: ""+servoprmviewmodel.NotchFilterBandwidth[mIndex]//Parameters[mIndex][index]
                                color: "#EFECCA"
                                validator: IntValidator {
                                    bottom: 0
                                    top: 65535
                                }
                                onEditingFinished: mParam[7] = parseInt(mytext7.text)
                            }

                            MButton {
                                //                                anchors.topMargin:
                                id: setBtn
                                _text: "Set"
                                _width: topGrid.width / 11 //- 5 // 11 - 15
                                _height: motorFrame.height / 24
                                width: topGrid.width


                                onBtnClick: {
                                    setBtn.visible = true
                                    servoprmviewmodel.INDEX=index
                                    servoprmviewmodel.InertiaRatioSetting[mIndex]=mParam[0]
                                    servoprmviewmodel.PositionProportionalGain1[mIndex]=mParam[1]
                                    servoprmviewmodel.PositionProportionalGain2[mIndex]=mParam[2]
                                    servoprmviewmodel.PositionFilterCommandTimeConstant[mIndex]=mParam[3]
                                    servoprmviewmodel.PositionFeedForwardGain[mIndex]=mParam[4]
                                    servoprmviewmodel.NotchFilterUse[mIndex]=mParam[5]
                                    servoprmviewmodel.NotchFilterFrequency[mIndex]=mParam[6]
                                    servoprmviewmodel.NotchFilterBandwidth[mIndex]=mParam[7]

                                    //absolute encoder ham reset she?
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
