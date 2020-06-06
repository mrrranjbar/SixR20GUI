#include "beckhoff.h"
#include <QObject>
#include "Model/Controller/controller.h"
#include <cmath>
#include <QDebug>
#include <string>
using namespace std;




Beckhoff::Beckhoff(QObject *parent) : QObject(parent)
{
    //controller
    _controlWord = new uint16_t[NumberOfRobotMotors];
    StatusWord = new uint16_t[NumberOfRobotMotors];
    ActualPositions = new int32_t[NumberOfRobotMotors];



    //******************************************************
    //hokmabadi

    //     for(size_t i = 0; i < 16; i++){
    //        _input_iomonitoring[i]=true;
    //        _output_iomonitoring[i]=false;
    //     }


    //******************************************************


    //    preStatusWord = new int[NumberOfRobotMotors];
    //    _positionActualValue = new long int[NumberOfRobotMotors];

    StatusWord = new uint16_t[NumberOfRobotMotors];
    _errorcode = new uint16_t[NumberOfRobotMotors];
    //    preStatusWord = new int[NumberOfRobotMotors];
    //    _positionActualValue = new long int[NumberOfRobotMotors];

    _targetPosition = new double[NumberOfRobotMotors + 8];
    _guiBuff = new double[NumberOfRobotMotors];
    _targetVelocity = new int[NumberOfRobotMotors];

    _guiManager = 0;

    //jog
    _mSelect = new bool[NumberOfRobotMotors];
    _jogDirection = new int[NumberOfRobotMotors];

    //servoprm gain
    //        _absoluteEncoderReset = new uint8_t(6);
    _inertiaRatioSetting = new uint16_t(6);
    _positionProportionalGain1= new uint16_t(6);
    _positionProportionalGain2= new uint16_t(6);
    _positionFilterCommandTimeConstant= new uint16_t(6);
    _positionFeedForwardGain = new uint16_t(6);
    _notchFilterUse = new uint16_t(6);
    _notchFilterFrequency = new uint16_t(6);
    _notchFilterBandwidth = new uint16_t(6);

}

void Beckhoff::RobotCurrentLineSetValue(int robotNewLine)
{
    robotCurrentLine = robotNewLine;
    Q_EMIT CurrentLineChangedB();
}

void Beckhoff::FinishCurrentProject()
{
    Q_EMIT FinishedCurrentProject();
}

void Beckhoff::StartCurrentProject()
{
    Q_EMIT StartedCurrentProject();
}

void Beckhoff::CurrentLineSetValue(int newLine)
{
    currentLine=newLine;
    Q_EMIT CurrentLineChangedB();
}

//get
//controller
//uint16_t* Beckhoff::getControlWord()
//{
//    for(int i=0; i<NumberOfRobotMotors; i++)
//    {
//        char *result1 = read("GVL.ControlWord[" + std::to_string(i) + "]");
//        _controlWord[i] = (uint16_t)((unsigned char)result1[1] << 8 | (unsigned char)result1[0]);
//    }
//    return _controlWord;
//}
//int32_t *Beckhoff::getTargetPosition(){
//    for(int i=0; i<NumberOfRobotMotors; i++)
//    {
//        char *result1 = read("GVL.TargetPosition[" + std::to_string(i) + "]");
//       _targetPosition[i] = (int32_t)((unsigned char)result1[3] << 24 | (unsigned char)result1[2] << 16 | (unsigned char)result1[1] << 8 | (unsigned char)result1[0]);
//    }
//return _targetPosition;
//}


//Jog
bool Beckhoff::getStoppingJog()
{
    return _stoppingJog;
}

bool *Beckhoff::getMSelect()
{
    return _mSelect;
}

double Beckhoff::getJogAcceleration()
{
    char *result = read("Controller_Obj1 (Main).Inputs.GUI_Jog_Joint_Acc");
    _jogAcceleration = (uint32_t)((unsigned char)result[3] << 24 |(unsigned char)result[2] << 16 |(unsigned char)result[1] << 8 | (unsigned char)result[0]);
    return _jogAcceleration;
}

double Beckhoff::getJogVelocity()
{
    char *result = read("Controller_Obj1 (Main).Inputs.GUI_Jog_Joint_Max_Vel");
    _jogVelocity = (uint32_t)((unsigned char)result[3] << 24 |(unsigned char)result[2] << 16 |(unsigned char)result[1] << 8 | (unsigned char)result[0]);
    return _jogVelocity;
}

double Beckhoff::getJogDeceleration()
{
    char *result = read("Controller_Obj1 (Main).Inputs.GUI_Jog_Joint_Dcc");
    _jogDeceleration = (uint32_t)((unsigned char)result[3] << 24 |(unsigned char)result[2] << 16 |(unsigned char)result[1] << 8 | (unsigned char)result[0]);
    return _jogDeceleration;
}

double Beckhoff::getJogAccelerationCart()
{
    char *result = read("Controller_Obj1 (Main).Inputs.GUI_Jog_Cart_Acc");
    _jogAccelerationCart = (uint32_t)((unsigned char)result[3] << 24 |(unsigned char)result[2] << 16 |(unsigned char)result[1] << 8 | (unsigned char)result[0]);
    return _jogAccelerationCart;
}

double Beckhoff::getJogVelocityCart()
{
    char *result = read("Controller_Obj1 (Main).Inputs.GUI_Jog_Cart_Max_Vel");
    _jogVelocityCart = (uint32_t)((unsigned char)result[3] << 24 |(unsigned char)result[2] << 16 |(unsigned char)result[1] << 8 | (unsigned char)result[0]);
    return _jogVelocityCart;
}

double Beckhoff::getJogDecelerationCart()
{
    char *result = read("Controller_Obj1 (Main).Inputs.GUI_Jog_Cart_Dcc");
    _jogDecelerationCart = (uint32_t)((unsigned char)result[3] << 24 |(unsigned char)result[2] << 16 |(unsigned char)result[1] << 8 | (unsigned char)result[0]);
    return _jogDecelerationCart;
}


int *Beckhoff::getJogDirection()
{
    return _jogDirection;
}

//***********************************
//hokmabadi
bool Beckhoff::getIoOutput(int index)
{
    //char * result = read("Controller_Obj1 (Main).Outputs.GUI_Outs[" + std::to_string(index) + "]");
    //     if(result[0] == 1)
    //         _output_iomonitoring[index] = true;
    //     else if(result[0] == 0)
    //         _output_iomonitoring[index] = false;
    //_output_iomonitoring[index] = (bool)result[0];
    return _output_iomonitoring[index];
}
void Beckhoff::setIoOutput(bool value, int index)
{
    //Controller_Obj1 (Main).Inputs.GUI_Ins[0]
    //Controller_Obj1 (Main).Outputs.GUI_Outs[0]
    write("Controller_Obj1 (Main).Outputs.GUI_Outs[" + std::to_string(index) + "]",static_cast<unsigned char*>(static_cast<void*>(&value)));
    _output_iomonitoring[index]=value;
}

uint8_t Beckhoff::getGUIManager()
{
    long port = AdsPortOpenEx();
    char * result = read2("Controller_Obj1 (Main).Inputs.GUI_Manager",port);
    AdsPortCloseEx(port);
    _guiManager =  (uint8_t)result[0];
    return _guiManager;
}

char Beckhoff::getNextCommandSign()
{
    long port = AdsPortOpenEx();
    char * result = read2("Controller_Obj1 (Main).Outputs.GUI_GetNextCMD",port);
    _getNextCommandSign =  (char)result[0];
    AdsPortCloseEx(port);
    return _getNextCommandSign;
}
void Beckhoff::setNextCommandSign(int value)
{
    write("Controller_Obj1 (Main).Outputs.GUI_GetNextCMD",static_cast<unsigned char*>(static_cast<void*>(&value)));
}

void Beckhoff::ReadInfoFromRobot()
{
    ReadActualPositionInfo();
    ReadStatusWordInfo();
    ReadOutputInfo();
    ReadInputInfo();
    ReadMovementStopInfo();
}




uint16_t* Beckhoff::getErrorCode()
{
    int index = 0;
    char * data = read("Controller_Obj1 (Main).Inputs.ErrorCodes");
    for(int i=0; i< 12; i+=2)
    {
        _errorcode[index++] =  (uint16_t)( (unsigned char)data[i+1] << 8 | (unsigned char)data[i]);
    }
    return _errorcode;
}

void Beckhoff::setConfJ(bool value)
{
    write("Controller_Obj1 (Main).Inputs.GUI_ConfJ",static_cast<unsigned char*>(static_cast<void*>(&value)));
    _confJ = value;
}

void Beckhoff::setConfData(int value)
{
    write("Controller_Obj1 (Main).Inputs.GUI_ConfData",static_cast<unsigned char*>(static_cast<void*>(&value)));
    _confData = value;
}

void Beckhoff::setSingulPTP(bool value)
{
    write("Controller_Obj1 (Main).Inputs.GUI_SingulPTP",static_cast<unsigned char*>(static_cast<void*>(&value)));
    _singulPTP = value;
}

void Beckhoff::setSingulCP(bool value)
{
    write("Controller_Obj1 (Main).Inputs.GUI_SingulCP",static_cast<unsigned char*>(static_cast<void*>(&value)));
    _singulCP = value;
}
bool Beckhoff::getSingulCP()
{
    return _singulCP;
}

void Beckhoff::setMaxVelocityPTP(double value)
{

}

void Beckhoff::setJerkPTP(double value)
{

}

void Beckhoff::setAccelerationPTP(double value)
{

}

void Beckhoff::setMaxVelocityCP(double value)
{

}

void Beckhoff::setJerkCP(double value)
{

}

void Beckhoff::setAccelerationCP(double value)
{

}

void Beckhoff::setGuiBuff(double value, int index)
{
    //    float val = (float)value;
    //    unsigned char *ptr = (unsigned char*) &val;


    //    for(int i=0;i<4;i++)
    //    {
    //        recarr[i]=ptr[i];
    //    }
    //    write1("Controller_Obj1 (Main).Outputs.Gui_Buff[" + std::to_string(index) + "]");
    _guiBuff[index]=value;
}

void Beckhoff::setIsLin(bool value)
{
    write("Controller_Obj1 (Main).Inputs.GUI_Is_Lin",static_cast<unsigned char*>(static_cast<void*>(&value)));
}
void Beckhoff::setIsPTP(bool value)
{
    write("Controller_Obj1 (Main).Inputs.GUI_Is_PTP",static_cast<unsigned char*>(static_cast<void*>(&value)));
}




//set
//controller
void Beckhoff::setControlWord(uint16_t *value)
{
    //    for(int i=0; i<NumberOfRobotMotors; i++)
    //    {
    //        write("GVL.ControlWord[" + std::to_string(i+1) + "]",static_cast<unsigned char*>(static_cast<void*>(&value[i])));
    //        _controlWord[i]=value[i];
    //    }
}


void Beckhoff::setTargetPosition(double value, int index)
{

    float val = (float)value;
    unsigned char *ptr = (unsigned char*) &val;


    for(int i=0;i<4;i++)
    {
        recarr[i]=ptr[i];
    }
    long port = AdsPortOpenEx();
    write1("Controller_Obj1 (Main).Inputs.GUI_TargetPosition[" + std::to_string(index) + "]",port);
    AdsPortCloseEx(port);
    _targetPosition[index]=value;
}
void Beckhoff::setTargetPosition2(double value[])
{

    int count =0;
    for(int j =0; j < 14; j++)
    {
        float val = (float)value[j];
        unsigned char *ptr = (unsigned char*) &val;


        for(int i=0;i<4;i++)
        {
            recarr2[count]=ptr[i];
            count++;
        }
    }

    long port = AdsPortOpenEx();
    write3("Controller_Obj1 (Main).Inputs.GUI_TargetPosition",port);
    AdsPortCloseEx(port);
    for(int i=0; i< 14; i++)
    {
        _targetPosition[i]=value[i];
    }
}
//double Beckhoff::getTargetPosition(int index)
//{
//    char * result = read("Controller_Obj1 (Main).Inputs.GUI_TargetPosition[" + std::to_string(index) + "]");
//    _targetPosition[index] = (float)( (unsigned char)result[3] << 24 |(unsigned char)result[2] << 16 |(unsigned char)result[1] << 8 | (unsigned char)result[0]);
//   return  _targetPosition[index];
//}

void Beckhoff::setTargetVelocity(int value, int index)
{
    _targetVelocity[index]=value;
}

void Beckhoff::setJogCartCurrentFrame(int value)
{
    write("Controller_Obj1 (Main).Inputs.GUI_Jog_Cart_Frame",static_cast<unsigned char*>(static_cast<void*>(&value)));
}

//Jog
void Beckhoff::setStoppingJog(bool value)
{
    _stoppingJog = value;
    write("Controller_Obj1 (Main).Inputs.GUI_StopingJog",static_cast<unsigned char*>(static_cast<void*>(&value)));
}

void Beckhoff::setMSelect(bool value, int idx)
{
    _mSelect[idx]=value;
    write("Controller_Obj1 (Main).Inputs.GUI_MSelect[" + std::to_string(idx) + "]",static_cast<unsigned char*>(static_cast<void*>(&value)));

}

void Beckhoff::setJogAcceleration(double value)
{
    float val = (float)value;
    unsigned char *ptr = (unsigned char*) &val;


    for(int i=0;i<4;i++)
    {
        recarr[i]=ptr[i];
    }
    long port = AdsPortOpenEx();
    write1("Controller_Obj1 (Main).Inputs.GUI_Jog_Joint_Acc",port);
    AdsPortCloseEx(port);
    _jogAcceleration = value;
}



void Beckhoff::setJogVelocity(double value)
{
    float val = (float)value;
    unsigned char *ptr = (unsigned char*) &val;


    for(int i=0;i<4;i++)
    {
        recarr[i]=ptr[i];
    }
    long port = AdsPortOpenEx();
    write1("Controller_Obj1 (Main).Inputs.GUI_Jog_Joint_Max_Vel",port);
    AdsPortCloseEx(port);
    _jogVelocity = value;
}



void Beckhoff::setJogDeceleration(double value)
{
    float val = (float)value;
    unsigned char *ptr = (unsigned char*) &val;


    for(int i=0;i<4;i++)
    {
        recarr[i]=ptr[i];
    }
    long port = AdsPortOpenEx();
    write1("Controller_Obj1 (Main).Inputs.GUI_Jog_Joint_Dcc",port);
    AdsPortCloseEx(port);
    _jogDeceleration = value;
}

void Beckhoff::setJogAccelerationCart(double value)
{
    float val = (float)value;
    unsigned char *ptr = (unsigned char*) &val;


    for(int i=0;i<4;i++)
    {
        recarr[i]=ptr[i];
    }
    long port = AdsPortOpenEx();
    write1("Controller_Obj1 (Main).Inputs.GUI_Jog_Cart_Acc",port);
    AdsPortCloseEx(port);
    _jogAccelerationCart = value;
}

void Beckhoff::setJogAbcRatio(double value)
{
    float val = (float)value;
    unsigned char *ptr = (unsigned char*) &val;


    for(int i=0;i<4;i++)
    {
        recarr[i]=ptr[i];
    }
    long port = AdsPortOpenEx();
    write1("Controller_Obj1 (Main).Inputs.GUI_ABC_Ratio",port);
    AdsPortCloseEx(port);
    _abcRatio = value;
}

void Beckhoff::setJogVelocityCart(double value)
{
    float val = (float)value;
    unsigned char *ptr = (unsigned char*) &val;


    for(int i=0;i<4;i++)
    {
        recarr[i]=ptr[i];
    }
    long port = AdsPortOpenEx();
    write1("Controller_Obj1 (Main).Inputs.GUI_Jog_Cart_Max_Vel",port);
    AdsPortCloseEx(port);
    _jogVelocityCart = value;
}

void Beckhoff::setJogDecelerationCart(double value)
{
    float val = (float)value;
    unsigned char *ptr = (unsigned char*) &val;


    for(int i=0;i<4;i++)
    {
        recarr[i]=ptr[i];
    }
    long port = AdsPortOpenEx();
    write1("Controller_Obj1 (Main).Inputs.GUI_Jog_Cart_Dcc",port);
    AdsPortCloseEx(port);
    _jogDecelerationCart = value;
}





//void Beckhoff::setJogDirection(int value, int index)
//{
//    _jogDirection[index]=value;

//}

void Beckhoff::setGUIManager(uint8_t value)
{
    long port = AdsPortOpenEx();
    write2("Controller_Obj1 (Main).Inputs.GUI_Manager",static_cast<unsigned char*>(static_cast<void*>(&value)),port);
    _guiManager=value;
    AdsPortCloseEx(port);
}

void Beckhoff::setFeedOverRide(double value)
{
    float val = (float)value;
    unsigned char *ptr = (unsigned char*) &val;


    for(int i=0;i<4;i++)
    {
        recarr[i]=ptr[i];
    }
    long port = AdsPortOpenEx();
    write1("Controller_Obj1 (Main).Inputs.FeedOverride",port);
    AdsPortCloseEx(port);
    _feedOverRide = value;
}

//***********************************
//hokmabadi



void Beckhoff::setGUIStopingJog(bool value){
    write("Controller_Obj1 (Main).Inputs.GUI_StopingJog",static_cast<unsigned char*>(static_cast<void*>(&value)));
}
void Beckhoff::setGUIJogDirection(int value){
    write("Controller_Obj1 (Main).Inputs.GUI_JogDirection",static_cast<unsigned char*>(static_cast<void*>(&value)));
}
void Beckhoff::setGUIM_Select(int* value, int idx){
    write("Controller_Obj1 (Main).Inputs.GUI_MSelect[" + std::to_string(idx) + "]",static_cast<unsigned char*>(static_cast<void*>(&value)));
}


int Beckhoff::connectToServer()
{
    static const AmsNetId remoteNetId {5,58,222,132,1,1};
    //static const AmsNetId remoteNetId {172,21,50,104,1,1};
    static const char remoteIpV4[] = "169.254.19.180";

    // uncomment and adjust if automatic AmsNetId deduction is not working as expected
    //AdsSetLocalAddress({192,168,211,1,1,1});
    //AdsSetLocalAddress({172,21,50,104,1,1});
    AdsSetLocalAddress({192,168,56,1,1,1});

    // add local route to your EtherCAT Master
    if (AdsAddRoute(remoteNetId, remoteIpV4)) {
        // out << "Adding ADS route failed, did you specified valid addresses?\n";
        return 2;
    }

    // open a new ADS port
    _port = AdsPortOpenEx();
    if (!_port) {
        //out << "Open ADS port failed\n";
        return 3;
    }

    AmsAddr remote { remoteNetId, 350};
    _server = remote;
    return 1;
}

int Beckhoff::Disconnect()
{
    AdsPortCloseEx(_port);
    return 1;
}

char *Beckhoff::read(std::string handleName)
{
    //static const char handleName[] = name; //"MAIN.byByte[4]";
    uint32_t bytesRead;

    //std::clog << __FUNCTION__ << "():\n";
    const uint32_t handle = getHandleByName(handleName,_port);
    const uint32_t bufferSize = getSymbolSize(handleName,_port);
    const auto buffer = std::unique_ptr<uint8_t>(new uint8_t[bufferSize]);
    const long status = AdsSyncReadReqEx2(_port,
                                          &_server,
                                          ADSIGRP_SYM_VALBYHND,
                                          handle,
                                          bufferSize,
                                          buffer.get(),
                                          &bytesRead);
    releaseHandleExample(handle,_port);
    if (status) {
        std::clog << "ADS read failed with: " << std::dec << status << '\n';
    }
    //    std::clog << "ADS read " << std::dec << bytesRead << " bytes:" << std::hex;
    // unsigned char temp[bytesRead];
    char *Buffer = new char [bytesRead+1];
    size_t i;
    for (i = 0; i < bytesRead; ++i) {
        Buffer[i] = (char)buffer.get()[i];
    }
    return Buffer;
}

char *Beckhoff::read2(string handleName, long _port)
{
    //static const char handleName[] = name; //"MAIN.byByte[4]";
    uint32_t bytesRead;

    //std::clog << __FUNCTION__ << "():\n";
    const uint32_t handle = getHandleByName(handleName,_port);
    const uint32_t bufferSize = getSymbolSize(handleName,_port);
    const auto buffer = std::unique_ptr<uint8_t>(new uint8_t[bufferSize]);
    const long status = AdsSyncReadReqEx2(_port,
                                          &_server,
                                          ADSIGRP_SYM_VALBYHND,
                                          handle,
                                          bufferSize,
                                          buffer.get(),
                                          &bytesRead);
    releaseHandleExample(handle,_port);
    if (status) {
        std::clog << "ADS read failed with: " << std::dec << status << '\n';
    }
    //    std::clog << "ADS read " << std::dec << bytesRead << " bytes:" << std::hex;
    // unsigned char temp[bytesRead];
    char *Buffer = new char [bytesRead+1];
    size_t i;
    for (i = 0; i < bytesRead; ++i) {
        Buffer[i] = (char)buffer.get()[i];
    }
    return Buffer;
}
void Beckhoff::write1(std::string handleName, long _port)
{
    //    _port1 = AdsPortOpenEx();
    const uint32_t handle = getHandleByName(handleName,_port);
    const uint32_t bufferSize = getSymbolSize(handleName,_port);
    //auto buffer = std::unique_ptr<uint8_t>(new uint8_t[bufferSize]);
    unsigned char buffer[bufferSize];
    for (int i = 0; i < bufferSize ; ++i) {
        buffer[i] = recarr[i];
    }
    const long status = AdsSyncWriteReqEx(_port,
                                          &_server,
                                          ADSIGRP_SYM_VALBYHND, // warning
                                          handle,
                                          bufferSize,
                                          buffer
                                          );
    releaseHandleExample(handle, _port);
    if (status) {
        std::clog << "ADS write failed with: " << std::dec << status << '\n';
    }
}
void Beckhoff::write3(std::string handleName, long _port)
{
    //    _port1 = AdsPortOpenEx();
    const uint32_t handle = getHandleByName(handleName,_port);
    const uint32_t bufferSize = getSymbolSize(handleName,_port);
    //auto buffer = std::unique_ptr<uint8_t>(new uint8_t[bufferSize]);
    unsigned char buffer[bufferSize];
    for (int i = 0; i < bufferSize ; ++i) {
        buffer[i] = recarr2[i];
    }
    const long status = AdsSyncWriteReqEx(_port,
                                          &_server,
                                          ADSIGRP_SYM_VALBYHND, // warning
                                          handle,
                                          bufferSize,
                                          buffer
                                          );
    releaseHandleExample(handle, _port);
    if (status) {
        std::clog << "ADS write failed with: " << std::dec << status << '\n';
    }
}
void Beckhoff::write(std::string handleName, unsigned char *value)
{
    const uint32_t handle = getHandleByName(handleName, _port);
    const uint32_t bufferSize = getSymbolSize(handleName, _port);
    //auto buffer = std::unique_ptr<uint8_t>(new uint8_t[bufferSize]);
    unsigned char buffer[bufferSize];
    for (int i = 0; i < bufferSize ; ++i) {
        buffer[i] = value[i];
    }
    const long status = AdsSyncWriteReqEx(_port,
                                          &_server,
                                          ADSIGRP_SYM_VALBYHND, // warning
                                          handle,
                                          bufferSize,
                                          buffer
                                          );
    releaseHandleExample(handle,_port);
    if (status) {
        std::clog << "ADS write failed with: " << std::dec << status << '\n';
    }
}

void Beckhoff::write2(string handleName, unsigned char *value, long _port)
{
    const uint32_t handle = getHandleByName(handleName, _port);
    const uint32_t bufferSize = getSymbolSize(handleName, _port);
    //auto buffer = std::unique_ptr<uint8_t>(new uint8_t[bufferSize]);
    unsigned char buffer[bufferSize];
    for (int i = 0; i < bufferSize ; ++i) {
        buffer[i] = value[i];
    }
    const long status = AdsSyncWriteReqEx(_port,
                                          &_server,
                                          ADSIGRP_SYM_VALBYHND, // warning
                                          handle,
                                          bufferSize,
                                          buffer
                                          );
    releaseHandleExample(handle,_port);
    if (status) {
        std::clog << "ADS write failed with: " << std::dec << status << '\n';
    }
}

//    releaseHandleExample(handle);
uint32_t Beckhoff::getHandleByName(const std::string handleName, long _port)
{
    uint32_t handle = 0;
    const long handleStatus = AdsSyncReadWriteReqEx2(_port,
                                                     &_server,
                                                     ADSIGRP_SYM_HNDBYNAME,
                                                     0,
                                                     sizeof(handle),
                                                     &handle,
                                                     handleName.size(),
                                                     handleName.c_str(),
                                                     nullptr);
    if (handleStatus) {
        std::clog << "Create handle for '" << handleName << "' failed with: " << std::dec << handleStatus << '\n';
    }
    return handle;
}

uint32_t Beckhoff::getSymbolSize(const std::string handleName, long _port)
{
    AdsSymbolEntry symbolEntry;
    uint32_t bytesRead;

    const long status = AdsSyncReadWriteReqEx2(_port,
                                               &_server,
                                               ADSIGRP_SYM_INFOBYNAMEEX,
                                               0,
                                               sizeof(symbolEntry),
                                               &symbolEntry,
                                               handleName.size(),
                                               handleName.c_str(),
                                               &bytesRead);
    if (status) {
        throw std::runtime_error("Unable to determine symbol size, reading ADS symbol information failed with: " + std::to_string(
                                     status));
    }
    return symbolEntry.size;
}

void Beckhoff::releaseHandleExample(uint32_t handle, long _port)
{
    const long releaseHandle = AdsSyncWriteReqEx(_port, &_server, ADSIGRP_SYM_RELEASEHND, 0, sizeof(handle), &handle);
    if (releaseHandle) {
        //out << "Release handle 0x" << std::hex << handle << "' failed with: 0x" << releaseHandle << '\n';
    }
}

//void Beckhoff::StatusWordNotify()
//{
//    const AdsNotificationAttrib attrib = {
//        12,
//        ADSTRANS_SERVERONCHA,
//        0,
//        {4000000}
//    };
//    uint32_t hNotify;
//    uint32_t handle;
//    uint32_t hUser = 0;
//    handle = getHandleByName("Controller_Obj1 (Main).Inputs.StatusWord",_port);
//    AdsSyncAddDeviceNotificationReqEx(_port,
//                                      &_server,
//                                      ADSIGRP_SYM_VALBYHND,
//                                      handle,
//                                      &attrib,
//                                      &StatusWordNotifyCallBack,
//                                      hUser,
//                                      &hNotify);
//    releaseHandleExample(handle,_port);
//}


//void Beckhoff::StatusWordNotifyCallBack(const AmsAddr *pAddr, const AdsNotificationHeader *pNotification, uint32_t hUser)
//{
//    const uint8_t* data = reinterpret_cast<const uint8_t*>(pNotification + 1);
//    // Controller::getInstance()->beckhoff->StatusWord[1] = (int16_t)((unsigned char)data[1] << 8 | (unsigned char)data[0]);
//    int index = 0;
//    for (size_t i = 0; i < pNotification->cbSampleSize; i+=2) {
//        Controller::getInstance()->beckhoff->StatusWord[index] = (uint16_t)((unsigned char)data[i+1] << 8 | (unsigned char)data[i]);
//        index++;
//    }

//    //    for (int i = 0; i < 6; ++i) {
//    //      if(Controller::getInstance()->beckhoff->preStatusWord[i] != Controller::getInstance()->beckhoff->StatusWord[i])
//    //      {
//    //          // notify change statusword
//    //      }
//    //    }
//    //    for (int i = 0; i < 6; ++i) {
//    //       Controller::getInstance()->beckhoff->preStatusWord[i] = Controller::getInstance()->beckhoff->StatusWord[i];
//    //    }
//}


//***********************************
//hokmabadi

//void Beckhoff::InputIoMonitoringNotify()
//{
//    const AdsNotificationAttrib attrib = {
//        2,
//        ADSTRANS_SERVERONCHA,
//        0,
//        {4000000}
//    };
//    uint32_t hNotify;
//    uint32_t handle;
//    uint32_t hUser = 0;
//    handle = getHandleByName("Controller_Obj1 (Main).Inputs.GUI_Ins",_port);
//    AdsSyncAddDeviceNotificationReqEx(_port,
//                                      &_server,
//                                      ADSIGRP_SYM_VALBYHND,
//                                      handle,
//                                      &attrib,
//                                      &InputIoMonitoringNotifyCallBack,
//                                      hUser,
//                                      &hNotify);
//    releaseHandleExample(handle,_port);
//}
//void Beckhoff::OutputIoMonitoringNotify()
//{
//    const AdsNotificationAttrib attrib = {
//        2,
//        ADSTRANS_SERVERONCHA,
//        0,
//        {4000000}
//    };
//    uint32_t hNotify;
//    uint32_t handle;
//    uint32_t hUser = 0;
//    handle = getHandleByName("Controller_Obj1 (Main).Outputs.GUI_Outs",_port);
//    AdsSyncAddDeviceNotificationReqEx(_port,
//                                      &_server,
//                                      ADSIGRP_SYM_VALBYHND,
//                                      handle,
//                                      &attrib,
//                                      &OutputIoMonitoringNotifyCallBack,
//                                      hUser,
//                                      &hNotify);
//    releaseHandleExample(handle,_port);
//}
//void Beckhoff::OutputIoMonitoringNotifyCallBack(const AmsAddr *pAddr, const AdsNotificationHeader *pNotification, uint32_t hUser)
//{
//    const uint8_t* data = reinterpret_cast<const uint8_t*>(pNotification + 1);
//    for(int i=0; i< 8; i++)
//    {
//        Controller::getInstance()->beckhoff->_output_iomonitoring[i] = (data[0] >> i) & 1;
//    }
//    for(int i=0; i< 8; i++)
//    {
//        Controller::getInstance()->beckhoff->_output_iomonitoring[i+8] = (data[1] >> i) & 1;
//    }
//}

//***********************************
//hokmabadi
//void Beckhoff::InputIoMonitoringNotifyCallBack(const AmsAddr *pAddr, const AdsNotificationHeader *pNotification, uint32_t hUser)
//{
//    const uint8_t* data = reinterpret_cast<const uint8_t*>(pNotification + 1);
//    for(int i=0; i< 8; i++)
//    {
//        Controller::getInstance()->beckhoff->_input_iomonitoring[i] = (data[0] >> i) & 1;
//    }
//    for(int i=0; i< 8; i++)
//    {
//        Controller::getInstance()->beckhoff->_input_iomonitoring[i+8] = (data[1] >> i) & 1;
//    }
//}

//void Beckhoff::ActualPositionNotify()
//{
//    const AdsNotificationAttrib attrib = {
//        24,
//        ADSTRANS_SERVERONCHA,
//        0,
//        {4000000}
//    };
//    uint32_t hNotify;
//    uint32_t handle;
//    uint32_t hUser = 0;
//    handle = getHandleByName("Controller_Obj1 (Main).Inputs.ActualPosition",_port);
//    AdsSyncAddDeviceNotificationReqEx(_port,
//                                      &_server,
//                                      ADSIGRP_SYM_VALBYHND,
//                                      handle,
//                                      &attrib,
//                                      &ActualPositionNotifyCallBack,
//                                      hUser,
//                                      &hNotify);
//    releaseHandleExample(handle,_port);
//}

//void Beckhoff::ActualPositionNotifyCallBack(const AmsAddr *pAddr, const AdsNotificationHeader *pNotification, uint32_t hUser)
//{
//    const uint8_t* data = reinterpret_cast<const uint8_t*>(pNotification + 1);
//    int index =0;
//    for(int i=0; i< pNotification->cbSampleSize; i+=4)
//    {
//        Controller::getInstance()->beckhoff->ActualPositions[index] = (int32_t)((unsigned char)data[i+3] << 24 |(unsigned char)data[i+2] << 16 | (unsigned char)data[i+1] << 8 | (unsigned char)data[i]);
//        index++;
//    }
//}

//void Beckhoff::MovementStopNotify()
//{
//    const AdsNotificationAttrib attrib = {
//        1,
//        ADSTRANS_SERVERONCHA,
//        0,
//        {4000000}
//    };
//    uint32_t hNotify;
//    uint32_t handle;
//    uint32_t hUser = 0;
//    handle = getHandleByName("Controller_Obj1 (Main).Inputs.GUI_MovementStop",_port);
//    AdsSyncAddDeviceNotificationReqEx(_port,
//                                      &_server,
//                                      ADSIGRP_SYM_VALBYHND,
//                                      handle,
//                                      &attrib,
//                                      &MovementStopNotifyCallBack,
//                                      hUser,
//                                      &hNotify);
//    releaseHandleExample(handle,_port);
//}

//void Beckhoff::MovementStopNotifyCallBack(const AmsAddr *pAddr, const AdsNotificationHeader *pNotification, uint32_t hUser)
//{
//    const uint8_t* data = reinterpret_cast<const uint8_t*>(pNotification + 1);
//    Controller::getInstance()->beckhoff->MovementStop = (data[0] >> 0) & 1;
//}

void Beckhoff::ReadActualPositionInfo()
{
    long port = AdsPortOpenEx();
    const char* data = read2("Controller_Obj1 (Main).Inputs.ActualPosition",port);
    int index =0;
    for(int i=0; i<24; i+=4)
    {
        Controller::getInstance()->beckhoff->ActualPositions[index] = (int32_t)((unsigned char)data[i+3] << 24 |(unsigned char)data[i+2] << 16 | (unsigned char)data[i+1] << 8 | (unsigned char)data[i]);
        index++;
    }
    AdsPortCloseEx(port);
}

void Beckhoff::ReadStatusWordInfo()
{
    long port = AdsPortOpenEx();
    const char* data = read2("Controller_Obj1 (Main).Inputs.StatusWord",port);
    int index = 0;
    for (size_t i = 0; i < 12; i+=2) {
        Controller::getInstance()->beckhoff->StatusWord[index] = (uint16_t)((unsigned char)data[i+1] << 8 | (unsigned char)data[i]);
        index++;
    }
    AdsPortCloseEx(port);
}

void Beckhoff::ReadInputInfo()
{

    long port = AdsPortOpenEx();
    const char* data = read2("Controller_Obj1 (Main).Inputs.GUI_Ins",port);
    for(int i=0; i< 8; i++)
    {
        Controller::getInstance()->beckhoff->_input_iomonitoring[i] = (data[0] >> i) & 1;
    }
    for(int i=0; i< 8; i++)
    {
        Controller::getInstance()->beckhoff->_input_iomonitoring[i+8] = (data[1] >> i) & 1;
    }
    AdsPortCloseEx(port);
}

void Beckhoff::ReadOutputInfo()
{
    long port = AdsPortOpenEx();
    const char* data = read2("Controller_Obj1 (Main).Outputs.GUI_Outs",port);
    for(int i=0; i< 8; i++)
    {
        Controller::getInstance()->beckhoff->_output_iomonitoring[i] = (data[0] >> i) & 1;
    }
    for(int i=0; i< 8; i++)
    {
        Controller::getInstance()->beckhoff->_output_iomonitoring[i+8] = (data[1] >> i) & 1;
    }
    AdsPortCloseEx(port);
}

void Beckhoff::ReadMovementStopInfo()
{
    long port = AdsPortOpenEx();
    const char* data = read2("Controller_Obj1 (Main).Inputs.GUI_MovementStop",port);
    Controller::getInstance()->beckhoff->MovementStop = (data[0] >> 0) & 1;
    AdsPortCloseEx(port);
}
//servoprm gain
//const QVector<uint8_t>* Beckhoff::getAbsoluteEncoderReset()
//{
//    return _absoluteEncoderReset;

//}

void Beckhoff::resetAbsoluteEncoder(int motorNo)
{
    //  _absoluteEncoderReset.insert(motorNo,val);
    //    if(motorNo<_absoluteEncoderReset->size())
    //        (*_absoluteEncoderReset)[motorNo] = 0x27;
}

uint16_t * Beckhoff::getIRS()
{
    //     _inertiaRatioSetting[0] = 0;
    return _inertiaRatioSetting;
}

void Beckhoff::setIRS(int motorNo, uint16_t val)
{
    _inertiaRatioSetting[motorNo] = val;
}

uint16_t * Beckhoff::getPPG1()
{

    return _positionProportionalGain1;

}

void Beckhoff::setPPG1(int motorNo, uint16_t val)
{
    _positionProportionalGain1[motorNo] = val;

}

uint16_t * Beckhoff::getPPG2()
{
    return _positionProportionalGain2;
}

void Beckhoff::setPPG2(int motorNo, uint16_t val)
{
    _positionProportionalGain2[motorNo] = val;

}

uint16_t * Beckhoff::getPFCTC()
{
    return _positionFilterCommandTimeConstant;

}

void Beckhoff::setPFCTC(int motorNo, uint16_t val)
{
    _positionFilterCommandTimeConstant[motorNo] = val;
}

uint16_t * Beckhoff::getPFFG()
{
    return _positionFeedForwardGain;

}

void Beckhoff::setPFFG(int motorNo, uint16_t val)
{
    _positionFeedForwardGain[motorNo] = val;

}

uint16_t * Beckhoff::getNFU()
{
    return _notchFilterUse;
}

void Beckhoff::setNFU(int motorNo, uint16_t val)
{
    _notchFilterUse[motorNo] = val;
}

uint16_t * Beckhoff::getNFF()
{
    return _notchFilterFrequency;

}

void Beckhoff::setNFF(int motorNo, uint16_t val)
{
    _notchFilterFrequency[motorNo] = val;
}

uint16_t * Beckhoff::getNFB()
{
    return _notchFilterBandwidth;

}

void Beckhoff::setNFB(int motorNo, uint16_t val)
{
    _notchFilterBandwidth[motorNo] = val;
}


