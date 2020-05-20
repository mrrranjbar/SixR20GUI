import QtQuick 2.0

Item {

    property string _writen_txt: ""
    property int _width: 200
    property int _height: 300

    width: _width
    height: _height
    Column
    {
        height: parent.height
        width: parent.width
        spacing: 10

        MFrame
        {

            width: parent.width + 6
            height: parent.height * 1/7

            TextInput
            {
                id: final_txt
                width: parent.width
                height:parent.height
                readOnly: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#9E9E9E"
                text: _writen_txt
            }
        }


        //**********************************************
        // first row
        Row
        {
            width: parent.width
            height:parent.height * 1/7
            spacing: 3
            MButton
            {
                _text: "7"
                _width: parent.width * 1/3
                height:parent.height
                onBtnClick:
                {
                    _writen_txt+="7";
                }
            }
            MButton
            {
                _text: "8"
                _width: parent.width * 1/3
                height:parent.height
                onBtnClick:
                {
                    _writen_txt+="8";
                }
            }
            MButton
            {
                _text: "9"
                _width: parent.width * 1/3
                height:parent.height
                onBtnClick:
                {
                    _writen_txt+="9";
                }
            }
        }

        //**********************************************
        // second row
        Row
        {
            width: parent.width
            height:parent.height * 1/7
            spacing: 3
            MButton
            {
                _text: "4"
                _width: parent.width * 1/3
                height:parent.height
                onBtnClick:
                {
                    _writen_txt+="4";
                }
            }
            MButton
            {
                _text: "5"
                _width: parent.width * 1/3
                height:parent.height
                onBtnClick:
                {
                    _writen_txt+="5";
                }
            }
            MButton
            {
                _text: "6"
                _width: parent.width * 1/3
                height:parent.height
                onBtnClick:
                {
                    _writen_txt+="6";
                }
            }
        }

        //**********************************************
        // Third row
        Row
        {
            width: parent.width
            height:parent.height * 1/7
            spacing: 3
            MButton
            {
                _text: "1"
                _width: parent.width * 1/3
                height:parent.height
                onBtnClick:
                {
                    _writen_txt+="1";
                }
            }
            MButton
            {
                _text: "2"
                _width: parent.width * 1/3
                height:parent.height
                onBtnClick:
                {
                    _writen_txt+="2";
                }
            }
            MButton
            {
                _text: "3"
                _width: parent.width * 1/3
                height:parent.height
                onBtnClick:
                {
                    _writen_txt+="3";
                }
            }
        }


        //**********************************************
        // fourth row
        Row
        {
            width: parent.width
            height:parent.height * 1/7
            spacing: 3
            MButton
            {
                _text: "."
                _width: parent.width * 1/3
                height:parent.height
                onBtnClick:
                {
                    _writen_txt+=".";
                }
            }
            MButton
            {
                _text: "0"
                _width: parent.width * 1/3
                height:parent.height
                onBtnClick:
                {
                    _writen_txt+="0";
                }
            }
            MButton
            {
                _text: "-"
                _width: parent.width * 1/3
                height:parent.height
                onBtnClick:
                {
                    _writen_txt+="-";
                }
            }
        }

        //**********************************************
        // fifth row
        MButton
        {
            _text: "<-"
            _width: parent.width + 4
            height:parent.height * 1/7
            onBtnClick:
            {
                _writen_txt=_writen_txt.substring(0, _writen_txt.length - 1);
            }
        }

        //**********************************************

    }

}
