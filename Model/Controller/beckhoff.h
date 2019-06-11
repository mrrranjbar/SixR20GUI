#ifndef BECKHOFF_H
#define BECKHOFF_H
#include <QObject>

#include "AdsLib/AdsLib.h"

#include <iostream>
#include <iomanip>


class Beckhoff : public QObject
{
     Q_OBJECT
public:
    explicit Beckhoff(QObject *parent = nullptr);

    void CurrentLineSetValue();
    //General Robots Parameter
    int NumberOfRobotMotors = 6; // for 6r robot
    bool IsEnableMovement = true;
    bool IsEnableIO = true;
    int currentLine = 0;
    bool doNextLine=true;
    bool runAll=true;
    bool stop=false;
    uint16_t *StatusWord;
<<<<<<< HEAD

=======
    QList<double> actualPositions = {133,138.4, 132,34484, 00, 18800};
>>>>>>> c0546f9d3e3b4cb9fd26e9cad3e855c1ae9b713b
   // int *preStatusWord;
//    enum mode{
//        nothing = 0,
//        position = 1,
//        trajectory = 2,
//        jog = 3
//    };


    //****************************************
    //hokmabadi

    int NumberOfInputOutput=16;
    bool _input_iomonitoring[16];

    //*****************************************

signals:
    void CurrentLineChangedB();



public slots:
    //get
    bool getStoppingJog();
    bool *getMSelect();
    int getJogAcceleration();
    int getJogMaxSpeed();
    int *getJogDirection();
    uint8_t getGUIManager();
    char getNextCommandSign();


    //***************************
    //hokmabadi
    bool getIoOutput(int index);
    //***************************


    //set
    void setControlWord(uint16_t* value);
    void setTargetPosition(int32_t value, int index);
    void setTargetVelocity(int value, int index);
    void setStoppingJog(bool value);
    void setMSelect(bool value, int index);
    void setJogAcceleration(int value);
    void setJogMaxSpeed(int value);
    //void setJogDirection(int value, int index);
    void setGUIManager(uint8_t value);

    //***************************
    //hokmabadi
    void setIoOutput(bool value,int index);
    //***************************

    void setGUIStopingJog(bool value);
    void setGUIJogDirection(int value);
    void setGUIM_Select(int* value, int idx);

    //connection
    int connectToServer();
    int Disconnect();
    char *read(std::string handleName);
    void write(std::string handleName, unsigned char value[]);
    void StatusWordNotify();
    static void StatusWordNotifyCallBack(const AmsAddr* pAddr, const AdsNotificationHeader* pNotification, uint32_t hUser);
    //***************************
    //hokmabadi
    void InputIoMonitoringNotify();
    static void InputIoMonitoringNotifyCallBack(const AmsAddr* pAddr, const AdsNotificationHeader* pNotification, uint32_t hUser);
    //***************************


private:
    //functions
    uint32_t getHandleByName(const std::string handleName);
    uint32_t getSymbolSize(const std::string handleName);
    void releaseHandleExample(uint32_t handle);

    //controller
    uint16_t *_controlWord;
    int32_t *_positionActualValue;
    int32_t * _targetPosition;
    int* _targetVelocity;
    uint8_t _guiManager;
    char _getNextCommandSign = 0;

    //jog
    bool _stoppingJog;
    bool *_mSelect;
    int _jogAcceleration;
    int _jogMaxSpeed;
    int *_jogDirection;

    //connection
    long _port;
    AmsAddr _server;

    //****************************************
    //hokmabadi
    // io_monitoring

    bool _output_iomonitoring[16];

    //*****************************************
};

#endif // BECKHOFF_H
