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

    //General Robots Parameter
    int NumberOfRobotMotors = 6; // for 6r robot
    uint16_t *StatusWord;
   // int *preStatusWord;
//    enum mode{
//        nothing = 0,
//        position = 1,
//        trajectory = 2,
//        jog = 3
//    };

signals:



public slots:
    //get
    bool getStoppingJog();
    bool *getMSelect();
    int getJogAcceleration();
    int getJogMaxSpeed();
    int *getJogDirection();
    uint8_t getGUIManager();


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

    //jog
    bool _stoppingJog;
    bool *_mSelect;
    int _jogAcceleration;
    int _jogMaxSpeed;
    int *_jogDirection;

    //connection
    long _port;
    AmsAddr _server;
};

#endif // BECKHOFF_H
