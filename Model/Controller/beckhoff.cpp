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
    //    preStatusWord = new int[NumberOfRobotMotors];
    //    _positionActualValue = new long int[NumberOfRobotMotors];

    _targetPosition = new double[NumberOfRobotMotors + 2];
    _targetVelocity = new int[NumberOfRobotMotors];

    _guiManager = 0;

    //jog
    _mSelect = new bool[NumberOfRobotMotors];
    _jogDirection = new int[NumberOfRobotMotors];

}

void Beckhoff::CurrentLineSetValue()
{
    currentLine++;
    emit CurrentLineChangedB();
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

int Beckhoff::getJogAcceleration()
{
    return _jogAcceleration;
}

int Beckhoff::getJogMaxSpeed()
{
    return _jogMaxSpeed;
}

int *Beckhoff::getJogDirection()
{
    return _jogDirection;
}

//***********************************
//hokmabadi
bool Beckhoff::getIoOutput(int index)
{
     char * result = read("Controller_Obj1 (Main).Outputs.GUI_Outs[" + std::to_string(index) + "]");
//     if(result[0] == 1)
//         _output_iomonitoring[index] = true;
//     else if(result[0] == 0)
//         _output_iomonitoring[index] = false;
     _output_iomonitoring[index] = (bool)result[0];
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
    char * result = read("Controller_Obj1 (Main).Inputs.GUI_Manager");
    _guiManager =  (uint8_t)result[0];
    return _guiManager;
}

char Beckhoff::getNextCommandSign()
{
    char * result = read("Controller_Obj1 (Main).Outputs.GUI_GetNextCMD");
    _getNextCommandSign =  (char)result[0];
    return _getNextCommandSign;
}




//set
//controller
void Beckhoff::setControlWord(uint16_t *value)
{
    for(int i=0; i<NumberOfRobotMotors; i++)
    {
        write("GVL.ControlWord[" + std::to_string(i+1) + "]",static_cast<unsigned char*>(static_cast<void*>(&value[i])));
        _controlWord[i]=value[i];
    }
}
unsigned char recarr[4];
void Beckhoff::setTargetPosition(double value, int index)
{

    float val = (float)value;
    unsigned char *ptr = (unsigned char*) &val;


    for(int i=0;i<4;i++)
    {
        recarr[i]=ptr[i];
    }
    write1("Controller_Obj1 (Main).Inputs.GUI_TargetPosition[" + std::to_string(index) + "]");
    _targetPosition[index]=value;
}

void Beckhoff::setTargetVelocity(int value, int index)
{
    _targetVelocity[index]=value;
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

void Beckhoff::setJogAcceleration(int value)
{
    _jogAcceleration = value;
}

void Beckhoff::setJogMaxSpeed(int value)
{
    _jogMaxSpeed = value;
}

//void Beckhoff::setJogDirection(int value, int index)
//{
//    _jogDirection[index]=value;

//}

void Beckhoff::setGUIManager(uint8_t value)
{
    write("Controller_Obj1 (Main).Inputs.GUI_Manager",static_cast<unsigned char*>(static_cast<void*>(&value)));
    _guiManager=value;
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
    AdsSetLocalAddress({172,21,50,104,1,1});

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
    const uint32_t handle = getHandleByName(handleName);
    const uint32_t bufferSize = getSymbolSize(handleName);
    const auto buffer = std::unique_ptr<uint8_t>(new uint8_t[bufferSize]);
    const long status = AdsSyncReadReqEx2(_port,
                                          &_server,
                                          ADSIGRP_SYM_VALBYHND,
                                          handle,
                                          bufferSize,
                                          buffer.get(),
                                          &bytesRead);
    releaseHandleExample(handle);
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
void Beckhoff::write1(std::string handleName)
{
    const uint32_t handle = getHandleByName(handleName);
   const uint32_t bufferSize = getSymbolSize(handleName);
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
    releaseHandleExample(handle);
    if (status) {
        std::clog << "ADS write failed with: " << std::dec << status << '\n';
    }
}
void Beckhoff::write(std::string handleName, unsigned char *value)
{
    const uint32_t handle = getHandleByName(handleName);
   const uint32_t bufferSize = getSymbolSize(handleName);
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
    releaseHandleExample(handle);
    if (status) {
        std::clog << "ADS write failed with: " << std::dec << status << '\n';
    }
}

//    releaseHandleExample(handle);
uint32_t Beckhoff::getHandleByName(const std::string handleName)
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

uint32_t Beckhoff::getSymbolSize(const std::string handleName)
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

void Beckhoff::releaseHandleExample(uint32_t handle)
{
    const long releaseHandle = AdsSyncWriteReqEx(_port, &_server, ADSIGRP_SYM_RELEASEHND, 0, sizeof(handle), &handle);
    if (releaseHandle) {
        //out << "Release handle 0x" << std::hex << handle << "' failed with: 0x" << releaseHandle << '\n';
    }
}

void Beckhoff::StatusWordNotify()
{
    const AdsNotificationAttrib attrib = {
        12,
        ADSTRANS_SERVERONCHA,
        0,
        {4000000}
    };
    uint32_t hNotify;
    uint32_t handle;
    uint32_t hUser = 0;
    handle = getHandleByName("GVL.StatusWord");
    AdsSyncAddDeviceNotificationReqEx(_port,
                                      &_server,
                                      ADSIGRP_SYM_VALBYHND,
                                      handle,
                                      &attrib,
                                      &StatusWordNotifyCallBack,
                                      hUser,
                                      &hNotify);
}


void Beckhoff::StatusWordNotifyCallBack(const AmsAddr *pAddr, const AdsNotificationHeader *pNotification, uint32_t hUser)
{
    const uint8_t* data = reinterpret_cast<const uint8_t*>(pNotification + 1);
    // Controller::getInstance()->beckhoff->StatusWord[1] = (int16_t)((unsigned char)data[1] << 8 | (unsigned char)data[0]);
    int index = 0;
    for (size_t i = 0; i < pNotification->cbSampleSize; i+=2) {
        Controller::getInstance()->beckhoff->StatusWord[index] = (uint16_t)((unsigned char)data[i+1] << 8 | (unsigned char)data[i]);
        index++;
    }

//    for (int i = 0; i < 6; ++i) {
//      if(Controller::getInstance()->beckhoff->preStatusWord[i] != Controller::getInstance()->beckhoff->StatusWord[i])
//      {
//          // notify change statusword
//      }
//    }
//    for (int i = 0; i < 6; ++i) {
//       Controller::getInstance()->beckhoff->preStatusWord[i] = Controller::getInstance()->beckhoff->StatusWord[i];
    //    }
}


//***********************************
//hokmabadi

void Beckhoff::InputIoMonitoringNotify()
{
    const AdsNotificationAttrib attrib = {
        2,
        ADSTRANS_SERVERONCHA,
        0,
        {4000000}
    };
    uint32_t hNotify;
    uint32_t handle;
    uint32_t hUser = 0;
    handle = getHandleByName("Controller_Obj1 (Main).Inputs.GUI_Ins");
    AdsSyncAddDeviceNotificationReqEx(_port,
                                     &_server,
                                     ADSIGRP_SYM_VALBYHND,
                                     handle,
                                     &attrib,
                                     &InputIoMonitoringNotifyCallBack,
                                     hUser,
                                     &hNotify);
}

//***********************************
//hokmabadi
void Beckhoff::InputIoMonitoringNotifyCallBack(const AmsAddr *pAddr, const AdsNotificationHeader *pNotification, uint32_t hUser)
{
    const uint8_t* data = reinterpret_cast<const uint8_t*>(pNotification + 1);
    for(int i=0; i< 8; i++)
    {
      Controller::getInstance()->beckhoff->_input_iomonitoring[i] = (data[0] >> i) & 1;
    }
    for(int i=0; i< 8; i++)
    {
      Controller::getInstance()->beckhoff->_input_iomonitoring[i+8] = (data[1] >> i) & 1;
    }
}

void Beckhoff::ActualPositionNotify()
{
    const AdsNotificationAttrib attrib = {
        24,
        ADSTRANS_SERVERONCHA,
        0,
        {4000000}
    };
    uint32_t hNotify;
    uint32_t handle;
    uint32_t hUser = 0;
    handle = getHandleByName("Controller_Obj1 (Main).Inputs.ActualPosition");
    AdsSyncAddDeviceNotificationReqEx(_port,
                                     &_server,
                                     ADSIGRP_SYM_VALBYHND,
                                     handle,
                                     &attrib,
                                     &ActualPositionNotifyCallBack,
                                     hUser,
                                     &hNotify);
}

void Beckhoff::ActualPositionNotifyCallBack(const AmsAddr *pAddr, const AdsNotificationHeader *pNotification, uint32_t hUser)
{
    const uint8_t* data = reinterpret_cast<const uint8_t*>(pNotification + 1);
    int index =0;
    for(int i=0; i< pNotification->cbSampleSize; i+=4)
    {
      Controller::getInstance()->beckhoff->ActualPositions[index] = (int32_t)((unsigned char)data[i+3] << 24 |(unsigned char)data[i+2] << 16 | (unsigned char)data[i+1] << 8 | (unsigned char)data[i]);
      index++;
    }
}


