import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    MFrame {
        width: parent.width
        height: parent.height * 0.95
        Grid
        { // main Grid
            id:maingrid
            width: parent.width
            height: parent.height
            columns: 1
            spacing: 8
            Grid
            {
                width: parent.width
                height: parent.height * 0.85
                columns: 2
                spacing: 4
                MFrame
                {
                    width: parent.width * 0.5
                    height: parent.height * 0.5
                    Grid
                    {
                        width:parent.width
                        height: parent.height
                        columns: 1

                        Label{
                            width: parent.width
                            height: parent.height * 0.25
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            text: "<b> JOG </b>"
                            color: "#21be2b"
                        }
                        Grid
                        {
                            width: parent.width
                            height: parent.height * 0.75
                            columns: 2
                            spacing: 2
                            Label{
                                width: parent.width * 0.5
                                height: parent.height * 0.33
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Max Velocity: </b>"
                                color: "#21be2b"
                            }

                            TextInput {
                                id: txtvelocity
                                width: parent.width * 0.5
                                height: parent.height * 0.33
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#21be2b"
                                text: "123"
                            }
                            Label{
                                width: parent.width * 0.5
                                height: parent.height * 0.33
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Max Acceleration: </b>"
                                color: "#21be2b"
                            }

                            TextInput {
                                id: txtacceleration
                                width: parent.width * 0.5
                                height: parent.height * 0.33
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#21be2b"
                                text: "123"
                            }
                            Label{
                                width: parent.width * 0.5
                                height: parent.height * 0.33
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Max Deceleration: </b>"
                                color: "#21be2b"
                            }

                            TextInput {
                                id: txtdeceleration
                                width: parent.width * 0.5
                                height: parent.height * 0.33
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#21be2b"
                                text: "123"
                            }
                        }

                    }
                }
                MFrame
                {
                    width: parent.width * 0.5
                    height: parent.height * 0.5
                    Grid
                    {
                        width:parent.width
                        height: parent.height
                        columns: 1

                        Label{
                            width: parent.width
                            height: parent.height * 0.25
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            text: "<b> All Moving Functions </b>"
                            color: "#21be2b"
                        }
                        Grid
                        {
                            width: parent.width
                            height: parent.height * 0.75
                            columns: 2
                            spacing: 2
                            Label{
                                width: parent.width * 0.5
                                height: parent.height * 0.33
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Max Velocity: </b>"
                                color: "#21be2b"
                            }

                            TextInput {
                                id: txtvelocityall
                                width: parent.width * 0.5
                                height: parent.height * 0.33
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#21be2b"
                                text: "123"
                            }
                            Label{
                                width: parent.width * 0.5
                                height: parent.height * 0.33
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Jerk: </b>"
                                color: "#21be2b"
                            }

                            TextInput {
                                id: txtjerk
                                width: parent.width * 0.5
                                height: parent.height * 0.33
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#21be2b"
                                text: "123"
                            }
                            Label{
                                width: parent.width * 0.5
                                height: parent.height * 0.33
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Acceleration: </b>"
                                color: "#21be2b"
                            }

                            TextInput {
                                id: txtaccelerationall
                                width: parent.width * 0.5
                                height: parent.height * 0.33
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#21be2b"
                                text: "123"
                            }
                        }

                    }
                }
                MFrame
                {
                    width: parent.width * 0.5
                    height: parent.height * 0.5
                    Grid
                    {
                        width:parent.width
                        height: parent.height
                        columns: 1

                        Label{
                            width: parent.width
                            height: parent.height * 0.25
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            text: "<b> HOME </b>"
                            color: "#21be2b"
                        }
                        MButton{
                            id:setpositionbtn
                            _width: parent.width
                            _height: parent.height * 0.25
                            _text:"Set Position"
                            onBtnClick: {

                            }
                        }

                        Grid
                        {
                            width: parent.width
                            height: parent.height * 0.50
                            columns: 2
                            spacing: 2
                            Label{
                                width: parent.width * 0.5
                                height: parent.height
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Velocity: </b>"
                                color: "#21be2b"
                            }

                            TextInput {
                                id: txtvelocityhome
                                width: parent.width * 0.5
                                height: parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#21be2b"
                                text: "123"
                            }

                        }

                    }
                }
                MFrame
                {
                    width: parent.width * 0.5
                    height: parent.height * 0.5
                    Grid
                    {
                        width:parent.width
                        height: parent.height
                        columns: 1

                        Label{
                            width: parent.width
                            height: parent.height * 0.25
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            text: "<b> \"Go To\" In Teach Point </b>"
                            color: "#21be2b"
                        }
                        Grid
                        {
                            width: parent.width
                            height: parent.height * 0.75
                            columns: 2
                            spacing: 2
                            Label{
                                width: parent.width * 0.5
                                height: parent.height * 0.33
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Velocity: </b>"
                                color: "#21be2b"
                            }

                            TextInput {
                                id: txtvelocitygoto
                                width: parent.width * 0.5
                                height: parent.height * 0.33
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#21be2b"
                                text: "123"
                            }

                        }

                    }
                }
            }

            Grid
            {
                width: parent.width
                height: parent.height * 0.15
                columns: 3
                Label // empty space
                {
                    width: parent.width * 0.33
                    height: parent.height
                }

                MButton{
                    id:setconfigbtn
                    _width: parent.width * 0.33
                    _height: parent.height
                    _text:"Set Config"
                    onBtnClick: {

                    }
                }
                Label // empty space
                {
                    width: parent.width * 0.33
                    height: parent.height
                }
            }
        }
    }
}
