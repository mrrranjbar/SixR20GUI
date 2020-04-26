import QtQuick 2.12
import QtQuick.Controls 2.12
import VelocityAccelerationViewModel 1.0;
Item {
    property int jogMaxVelocity: velaccviewmodel.JogMaxVelocity
    property int jogMaxAcceleration: velaccviewmodel.JogMaxAcceleration
    property int jogMaxDeceleration: velaccviewmodel.JogMaxDeceleration
    VelocityAccelerationViewModel
    {
        id: velaccviewmodel
    }

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
                            height: parent.height * 0.15
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            text: "<b> JOG </b>"
                            color: "#EFECCA"
                        }
                        Grid
                        {
                            width: parent.width
                            height: parent.height * 0.85
                            columns: 3
                            spacing: 2

                            //*************************************************
                            // row 1
                            Rectangle{
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                color: "transparent"
                            }
                            Label{
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Joint </b>"
                                color: "#EFECCA"
                            }
                            Label{
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Lin </b>"
                                color: "#EFECCA"
                            }
                            //*************************************************
                            // row 2
                            Label{
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Max Velocity: </b>"
                                color: "#EFECCA"
                            }

                            TextInput {
                                id: txtvelocity_joint
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: jogMaxVelocity
                            }
                            TextInput {
                                id: txtvelocity_lin
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: jogMaxVelocity
                            }
                            //*************************************************
                            // row 3
                            Label{
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Max Acceleration: </b>"
                                color: "#EFECCA"
                            }

                            TextInput {
                                id: txtacceleration_joint
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: jogMaxAcceleration
                            }

                            TextInput {
                                id: txtacceleration_lin
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: jogMaxAcceleration
                            }
                            //*************************************************
                            // row 4
                            Label{
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Max Deceleration: </b>"
                                color: "#EFECCA"
                            }

                            TextInput {
                                id: txtdeceleration_joint
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: jogMaxDeceleration
                            }
                            TextInput {
                                id: txtdeceleration_lin
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: jogMaxDeceleration
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
                            height: parent.height * 0.15
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            text: "<b> All Moving Functions </b>"
                            color: "#EFECCA"
                        }
                        Grid
                        {
                            width: parent.width
                            height: parent.height * 0.85
                            columns: 3
                            spacing: 2
                            //*************************************************
                            // row 1
                            Rectangle{
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                color: "transparent"
                            }
                            Label{
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Joint </b>"
                                color: "#EFECCA"
                            }
                            Label{
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Lin </b>"
                                color: "#EFECCA"
                            }
                            //*************************************************
                            // row 2
                            Label{
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Max Velocity: </b>"
                                color: "#EFECCA"
                            }

                            TextInput {
                                id: txtvelocityall_joint
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: "123"
                            }
                            TextInput {
                                id: txtvelocityall_lin
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: "123"
                            }
                            //*************************************************
                            // row 3
                            Label{
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Jerk: </b>"
                                color: "#EFECCA"
                            }

                            TextInput {
                                id: txtjerk_joint
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: "123"
                            }
                            TextInput {
                                id: txtjerk_lin
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: "123"
                            }
                            //*************************************************
                            // row 4
                            Label{
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Acceleration: </b>"
                                color: "#EFECCA"
                            }

                            TextInput {
                                id: txtaccelerationall_joint
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: "123"
                            }

                            TextInput {
                                id: txtaccelerationall_lin
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
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
                            color: "#EFECCA"
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
                                color: "#EFECCA"
                            }

                            TextInput {
                                id: txtvelocityhome
                                width: parent.width * 0.5
                                height: parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
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
                            color: "#EFECCA"
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
                                color: "#EFECCA"
                            }

                            TextInput {
                                id: txtvelocitygoto
                                width: parent.width * 0.5
                                height: parent.height * 0.33
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
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
                        velaccviewmodel.JogMaxVelocity = jogMaxVelocity
                        velaccviewmodel.JogMaxAcceleration = jogMaxAcceleration
                        velaccviewmodel.JogMaxDeceleration = jogMaxDeceleration
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
