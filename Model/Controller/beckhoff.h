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


    //MRR
   // double getTargetPosition(int index);


    void CurrentLineSetValue(int newLine);
    void RobotCurrentLineSetValue(int robotNewLine);
    void FinishCurrentProject();
    void StartCurrentProject();
    //General Robots Parameter
    int NumberOfRobotMotors = 6; // for 6r robot
    int runFromLineNumber=-1;
    bool IsEnableMovement = true;
    bool IsEnableIO = false;
    int currentLine = 0;
    int robotCurrentLine=0;
    bool doNextLine=true;
    bool runAll=true;
    bool stopAnltrRun=false;
    uint16_t *StatusWord;
    QString tempJointTargetPoints[6] = {"0","0","0","0","0","0"};
    QString tempCartTargetPoints[6] = {"0","0","0","0","0","0"};

    bool MovementStop;

    int32_t *ActualPositions;// = {1.1,1.1,1.1,1.1,1.1,1.1};
   // int *preStatusWord;
//    enum mode{
//        nothing = 0,
//        position = 1,
//        trajectory = 2,
//        jog = 3
//    };

    unsigned char recarr[4];
    unsigned char recarr2[56];
    int IndexOfGuiBuff = 0;
    //****************************************
    //hokmabadi

    int NumberOfInputOutput=16;
    bool _input_iomonitoring[16];

    //*****************************************

Q_SIGNALS:
    void CurrentLineChangedB();
    void FinishedCurrentProject();
    void StartedCurrentProject();
    void AlarmDetected();
    void MovementStopDetected();



public Q_SLOTS:
    //get
    bool getStoppingJog();
    bool *getMSelect();
    double getJogAcceleration();
    double getJogVelocity();
    double getJogDeceleration();
    double getJogAccelerationCart();
    double getJogVelocityCart();
    double getJogDecelerationCart();
    int *getJogDirection();
    uint8_t getGUIManager();
    char getNextCommandSign();
    uint16_t* getErrorCode();
    void setConfJ(bool value);
    void setConfData(int value);
    void setSingulPTP(bool value);
    void setSingulCP(bool value);
    bool getSingulCP();
    void setMaxVelocityPTP(double value);
    void setJerkPTP(double value);
    void setAccelerationPTP(double value);
    void setMaxVelocityCP(double value);
    void setJerkCP(double value);
    void setAccelerationCP(double value);
    void setGuiBuff(double value, int index);
    void setIsLin(bool value);
    void setIsPTP(bool value);
    void setNextCommandSign(int value);


    void ReadInfoFromRobot();


    //***************************
    //hokmabadi
    bool getIoOutput(int index);
    //***************************


    //set
    void setControlWord(uint16_t* value);
    void setTargetPosition(double value, int index);
    void setTargetPosition2(double* value);
    void setTargetVelocity(int value, int index);
    void setJogCartCurrentFrame(int value);
    void setStoppingJog(bool value);
    void setMSelect(bool value, int index);
    void setJogAcceleration(double value);
    void setJogVelocity(double value);
    void setJogDeceleration(double value);
    void setJogAccelerationCart(double value);
    void setJogAbcRatio(double value);
    void setJogVelocityCart(double value);
    void setJogDecelerationCart(double value);
    //void setJogDirection(int value, int index);
    void setGUIManager(uint8_t value);
    void setFeedOverRide(double value);

    //servoprm gain
//        const QVector<uint8_t>* getAbsoluteEncoderReset();
        void resetAbsoluteEncoder(int motorNo);
          uint16_t * getIRS();
        void setIRS(int motorNo, uint16_t val);
         uint16_t * getPPG1();
        void setPPG1(int motorNo, uint16_t val);
         uint16_t * getPPG2();
        void setPPG2(int motorNo, uint16_t val);
         uint16_t * getPFCTC();
        void setPFCTC(int motorNo, uint16_t val);
         uint16_t * getPFFG();
        void setPFFG(int motorNo, uint16_t val);
         uint16_t * getNFU();
        void setNFU(int motorNo, uint16_t val);
         uint16_t * getNFF();
        void setNFF(int motorNo, uint16_t val);
         uint16_t * getNFB();
        void setNFB(int motorNo, uint16_t val);

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
    char *read2(std::string handleName, long _port);

    void write(std::string handleName, unsigned char *value);
    void write1(std::string handleName, long _port);
    void write2(std::string handleName, unsigned char *value, long _port);
    void write3(std::string handleName, long _port);

    //void StatusWordNotify();
    //static void StatusWordNotifyCallBack(const AmsAddr* pAddr, const AdsNotificationHeader* pNotification, uint32_t hUser);
    //***************************
    //hokmabadi
    //void InputIoMonitoringNotify();
    //static void InputIoMonitoringNotifyCallBack(const AmsAddr* pAddr, const AdsNotificationHeader* pNotification, uint32_t hUser);
    //***************************

    //void OutputIoMonitoringNotify();
    //static void OutputIoMonitoringNotifyCallBack(const AmsAddr* pAddr, const AdsNotificationHeader* pNotification, uint32_t hUser);

    //void ActualPositionNotify();
    //static void ActualPositionNotifyCallBack(const AmsAddr* pAddr, const AdsNotificationHeader* pNotification, uint32_t hUser);

    //void MovementStopNotify();
    //static void MovementStopNotifyCallBack(const AmsAddr* pAddr, const AdsNotificationHeader* pNotification, uint32_t hUser);

    void ReadActualPositionInfo();
    void ReadStatusWordInfo();
    void ReadInputInfo();
    void ReadOutputInfo();
    void ReadMovementStopInfo();

private:
    //functions
    uint32_t getHandleByName(const std::string handleName, long _port);
    uint32_t getSymbolSize(const std::string handleName, long _port);
    void releaseHandleExample(uint32_t handle, long _port);

    //controller
    uint16_t *_controlWord;
    double _feedOverRide;
    uint16_t *_errorcode;
    double * _targetPosition;
    double * _guiBuff;
    int* _targetVelocity;
    uint8_t _guiManager;
    char _getNextCommandSign = 0;


    //jog
    bool _stoppingJog;
    bool *_mSelect;
    double _jogAcceleration;
    double _jogVelocity;
    double _jogDeceleration;
    int *_jogDirection;
    double _jogAccelerationCart;
    double _jogVelocityCart;
    double _jogDecelerationCart;
    double _abcRatio;
    bool _confJ;
    int _confData;
    bool _singulPTP;
    bool _singulCP;

    //connection
    long _port;
    AmsAddr _server;



    //****************************************
    //hokmabadi
    // io_monitoring

    bool _output_iomonitoring[16];

    //*****************************************

    //servoprm
//         uint8_t *_absoluteEncoderReset;
         uint16_t *_inertiaRatioSetting;
         uint16_t *_positionProportionalGain1;
         uint16_t *_positionProportionalGain2;
         uint16_t *_positionFilterCommandTimeConstant;
         uint16_t *_positionFeedForwardGain;
         uint16_t *_notchFilterUse;
         uint16_t *_notchFilterFrequency;
         uint16_t *_notchFilterBandwidth;
};

#endif // BECKHOFF_H
