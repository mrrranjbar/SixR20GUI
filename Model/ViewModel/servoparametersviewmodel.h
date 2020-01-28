#ifndef SERVOPRMVIEWMODEL_H
#define SERVOPRMVIEWMODEL_H
#include <QObject>
#include "Model/Controller/controller.h"

class ServoPRMViewModel;

class ServoPRMViewModel : public QObject{
    Q_OBJECT
    Q_PROPERTY(QList<int> InertiaRatioSetting READ InertiaRatioSetting WRITE setIRS NOTIFY IRSChanged)
    Q_PROPERTY(QList<int> PositionProportionalGain1 READ PositionProportionalGain1 WRITE setPPG1 NOTIFY PPG1Changed)
    Q_PROPERTY(QList<int> PositionProportionalGain2 READ PositionProportionalGain2 WRITE setPPG2 NOTIFY PPG2Changed)
    Q_PROPERTY(QList<int> PositionFilterCommandTimeConstant READ PositionFilterCommandTimeConstant WRITE setPFCTC NOTIFY PFCTCChanged)
    Q_PROPERTY(QList<int> PositionFeedForwardGain READ PositionFeedForwardGain WRITE setPFFG NOTIFY PFFGChanged)
    Q_PROPERTY(QList<int> NotchFilterUse READ NotchFilterUse WRITE setNFU NOTIFY NFUChanged)
    Q_PROPERTY(QList<int> NotchFilterFrequency READ NotchFilterFrequency WRITE setNFF NOTIFY NFFChanged)
    Q_PROPERTY(QList<int> NotchFilterBandwidth READ NotchFilterBandwidth WRITE setNFB NOTIFY NFBChanged)
    Q_PROPERTY(int INDEX READ INDEX WRITE setINDEX NOTIFY INDEXChanged)


public:
    explicit ServoPRMViewModel(QObject *parent = nullptr);

signals:
    void IRSChanged( );
    void PPG1Changed( );
    void PPG2Changed();
    void PFCTCChanged( );
    void PFFGChanged( );
    void NFUChanged( );
    void NFFChanged( );
    void NFBChanged();
    void INDEXChanged();
public slots:
    void resetAbsoluteEncoder();
    QList<int> InertiaRatioSetting();
    void setIRS(QList<int> InertiaRatioSetting);
    QList<int> PositionProportionalGain1();
    void setPPG1(QList<int> PositionProportionalGain1);
    QList<int> PositionProportionalGain2();
    void setPPG2(QList<int> PositionProportionalGain2);
    QList<int> PositionFilterCommandTimeConstant();
    void setPFCTC(QList<int> PositionFilterCommandTimeConstant);
    QList<int> PositionFeedForwardGain();
    void setPFFG(QList<int> PositionFeedForwardGain);
    QList<int> NotchFilterUse();
    void setNFU(QList<int> NotchFilterUse);
    QList<int> NotchFilterFrequency();
    void setNFF(QList<int> NotchFilterFrequency);
    QList<int> NotchFilterBandwidth();
    void setNFB(QList<int> NotchFilterBandwidth);

    void setINDEX(int index);
    int INDEX();

private:
    Controller *controller;
    QList<uint8_t> _absoluteEncoder;
    QList<int> _inertiaRatioSetting;
    QList<int> _positionProportionalGain1=QList<int>();
    QList<int> m_PositionProportionalGain2;
    QList<int> m_PositionFilterCommandTimeConstant;
    QList<int> m_PositionFeedForwardGain;
    QList<int> m_NotchFilterUse;
    QList<int> m_NotchFilterFrequency;
    QList<int> m_NotchFilterBandwidth;
    int _index;
};


#endif // SERVOPRMVIEWMODEL_H
