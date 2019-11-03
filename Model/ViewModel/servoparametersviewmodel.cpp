#include "Model/ViewModel/servoparametersviewmodel.h"


ServoPRMViewModel::ServoPRMViewModel(QObject *parent) : QObject(parent){
    controller = Controller::getInstance();

}
void ServoPRMViewModel::resetAbsoluteEncoder(){
    //
}
//property-tor
QList<int> ServoPRMViewModel::InertiaRatioSetting(){
    uint16_t* tmp= controller->beckhoff->getIRS();
    for(int i=0; i<6; i++)
        _inertiaRatioSetting.append(tmp[i]);
    return _inertiaRatioSetting;
}
void ServoPRMViewModel::setIRS(QList<int> InertiaRatioSetting)
{
    if (_inertiaRatioSetting == InertiaRatioSetting)
        return;

    _inertiaRatioSetting = InertiaRatioSetting;
    controller->beckhoff->setIRS(_index,_inertiaRatioSetting[_index]);
    emit IRSChanged();
}

QList<int> ServoPRMViewModel::PositionProportionalGain1()
{
    uint16_t* tmp= controller->beckhoff->getPPG1();
    for(int i=0; i<6; i++)
        _positionProportionalGain1.append(tmp[i]);
    return _positionProportionalGain1;
}

void ServoPRMViewModel::setPPG1(QList<int> PositionProportionalGain1)
{
    if (_positionProportionalGain1 == PositionProportionalGain1)
        return;

    _positionProportionalGain1 = PositionProportionalGain1;
    emit PPG1Changed();
}

QList<int> ServoPRMViewModel::PositionProportionalGain2()
{
    uint16_t* tmp= controller->beckhoff->getPPG2();
    for(int i=0; i<6; i++)
        m_PositionProportionalGain2.append(tmp[i]);
   return m_PositionProportionalGain2;
}
void  ServoPRMViewModel::setPPG2(QList<int> PositionProportionalGain2)
{
   if (m_PositionProportionalGain2 == PositionProportionalGain2)
       return;

   m_PositionProportionalGain2 = PositionProportionalGain2;
   emit PPG2Changed();
}

QList<int> ServoPRMViewModel::PositionFilterCommandTimeConstant()
{
    uint16_t* tmp= controller->beckhoff->getPFCTC();
    for(int i=0; i<6; i++)
        m_PositionFilterCommandTimeConstant.append(tmp[i]);
   return m_PositionFilterCommandTimeConstant;
}

void ServoPRMViewModel::setPFCTC(QList<int> PositionFilterCommandTimeConstant)
{
    if (m_PositionFilterCommandTimeConstant == PositionFilterCommandTimeConstant)
        return;

    m_PositionFilterCommandTimeConstant = PositionFilterCommandTimeConstant;
    emit PFCTCChanged();
}
QList<int> ServoPRMViewModel::PositionFeedForwardGain()
{
    uint16_t* tmp= controller->beckhoff->getPFFG();
    for(int i=0; i<6; i++)
        m_PositionFeedForwardGain.append(tmp[i]);
   return m_PositionFeedForwardGain;
}
void ServoPRMViewModel::setPFFG(QList<int> PositionFeedForwardGain)
{
    if (m_PositionFeedForwardGain == PositionFeedForwardGain)
        return;

    m_PositionFeedForwardGain = PositionFeedForwardGain;
    emit PFFGChanged();
}

QList<int> ServoPRMViewModel::NotchFilterUse()
{
    uint16_t* tmp= controller->beckhoff->getNFU();
    for(int i=0; i<6; i++)
        m_NotchFilterUse.append(tmp[i]);
   return m_NotchFilterUse;
}
void ServoPRMViewModel::setNFU(QList<int> NotchFilterUse)
{
    if (m_NotchFilterUse == NotchFilterUse)
        return;

    m_NotchFilterUse = NotchFilterUse;
    emit NFUChanged();
}

QList<int> ServoPRMViewModel::NotchFilterFrequency()
{
    uint16_t* tmp= controller->beckhoff->getNFF();
    for(int i=0; i<6; i++)
        m_NotchFilterFrequency.append(tmp[i]);
   return m_NotchFilterFrequency;
}
void ServoPRMViewModel::setNFF(QList<int> NotchFilterFrequency)
{
    if (m_NotchFilterFrequency == NotchFilterFrequency)
        return;

    m_NotchFilterFrequency = NotchFilterFrequency;
    emit NFFChanged();
}
QList<int> ServoPRMViewModel::NotchFilterBandwidth()
{
    uint16_t* tmp= controller->beckhoff->getNFB();
    for(int i=0; i<6; i++)
        m_NotchFilterBandwidth.append(tmp[i]);
   return m_NotchFilterBandwidth;
}
void ServoPRMViewModel::setNFB(QList<int> NotchFilterBandwidth)
{
    if (m_NotchFilterBandwidth == NotchFilterBandwidth)
        return;

    m_NotchFilterBandwidth = NotchFilterBandwidth;
    emit NFBChanged();
}

void ServoPRMViewModel::setINDEX(int index)
{
    _index=index;
    emit INDEXChanged();
}

int ServoPRMViewModel::INDEX()
{
    return _index;
}
