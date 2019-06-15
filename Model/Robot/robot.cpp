#include "robot.h"

Robot::Robot()
{

    QString frameName,type,savedStatus,frameMethod,
            teachedFrameName,teachedFrameType="";
    QString TempIndex="0",threePointsStatus="100";
    bool saved,iscurrent=false;

    QList<double> mainpointsList = {0,0,0,0,0,0};

    currentWorldFrame=new frame(TempIndex,type,frameName,saved,iscurrent,mainpointsList,threePointsStatus,mainpointsList,"",mainpointsList,"",mainpointsList,"",frameMethod,teachedFrameName,teachedFrameType);
    currentObjectFrame=new frame(TempIndex,type,frameName,saved,iscurrent,mainpointsList,threePointsStatus,mainpointsList,"",mainpointsList,"",mainpointsList,"",frameMethod,teachedFrameName,teachedFrameType);
    currentTaskFrame=new frame(TempIndex,type,frameName,saved,iscurrent,mainpointsList,threePointsStatus,mainpointsList,"",mainpointsList,"",mainpointsList,"",frameMethod,teachedFrameName,teachedFrameType);
    currentToolFrame=new frame(TempIndex,type,frameName,saved,iscurrent,mainpointsList,threePointsStatus,mainpointsList,"",mainpointsList,"",mainpointsList,"",frameMethod,teachedFrameName,teachedFrameType);
    currentBaseFrame=new frame(TempIndex,type,frameName,saved,iscurrent,mainpointsList,threePointsStatus,mainpointsList,"",mainpointsList,"",mainpointsList,"",frameMethod,teachedFrameName,teachedFrameType);

    jogTempFrame=new frame(TempIndex,type,frameName,saved,iscurrent,mainpointsList,threePointsStatus,mainpointsList,"",mainpointsList,"",mainpointsList,"",frameMethod,teachedFrameName,teachedFrameType);
}
