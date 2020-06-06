#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model/Robot/robot.h"
#include "beckhoff.h"
#include <qqmlcontext.h>

#include <qqmlcontext.h>
#include "Model/ViewModel/alarm.h"
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QDomDocument>
#include <QtXml>
#include <iostream>


class Controller
{    
    private:
        /* Here will be the instance stored. */
        static Controller* instance;
        QHash<QString,alarm*> *_alarmTable;
        alarm* getAlarm(QString key);
        bool _allow_alarm_detection;
        QString _general_robot_status;
        bool _is_joint;

        /* Private constructor to prevent instancing. */
        Controller();

    public:
        bool IsGoToStart = false;
        QQmlContext *ctxt;
        /* Static access method. */
        static Controller* getInstance();
        Robot *robot;
        Beckhoff *beckhoff;
        QList<QObject*> dataList;
        void Initialize();
//        void editList(int index);
        void InitializePoints();
        void InitializeAlarm();
        void initializeHashTable();
        QString GeneralRobotStatus();
        void SetGeneralRobotStatus(QString value);
        void setIsJoint(bool val);
        bool IsJoint();
        bool IsFirstJogPageLunch = true;
        bool IsFirstPositionPageLunch = true;
         bool IsFirstGeneralSettingPage = true;
        double JogFineVelocity,JogFineAcceleration,JogFineDeceleration,JogFineVelocityCart,JogFineAccelerationCart,JogFineDecelerationCart,JogAbcRatio;
        double JogVelocity,JogAcceleration,JogDeceleration,JogVelocityCart,JogAccelerationCart,JogDecelerationCart;
        int JogCartCurrentFrame;
        bool JogFine;
        int PositionVelocity;
        bool PositionPTP;
        bool IsJogInPositionPage;
        bool IsUpdateButtonClickedFramePage;
        bool IsUpdatePositionCheckedFramePage;

        bool IsMovementStop = false;
        bool IsClearMovementStop = false;

        //*******************************
        // velocity
        bool Confj;
        int ConfData;
        bool SingulPTP;
        bool SingulCP;
        double MaxVelocityPTP;
        double JerkPTP;
        double AccelerationPTP;
        double MaxVelocityCP;
        double JerkCP;
        double AccelerationCP;
        double HomeVelocity = 15;
        double GotoVelocity = 10;

        double FourConfigBtn4[6];

        //*******************************
//        void InitializeChartPoints();

        double homePosition[6] = {0,0,0,0,0,0};


        QList<QObject*> framesList;
        QList<QObject*> alarmList;
//        QList<QObject*> chartpointsList;

        QString _current_project_name="";

        void AlarmDetection();
        void InitializeFrames();
        void writeListToFile();
        bool AllowAlarmDetection();
        void setAllowAlarmDetection(bool value);

        bool IsFirstMovingCommand;

    Q_SIGNALS :

    public Q_SLOTS:

};

#endif // CONTROLLER_H
