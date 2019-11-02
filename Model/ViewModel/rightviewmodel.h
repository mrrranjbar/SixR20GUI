#ifndef RIGHTVIEWMODEL_H
#define RIGHTVIEWMODEL_H

#include <QObject>
#include "Model/Controller/controller.h"

class RightViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString StatusWordStr READ StatusWordStr WRITE setStatusWordStr NOTIFY StatusWordStrChanged)
    Q_PROPERTY(QList<QString> StatusWord READ StatusWord WRITE setStatusWord NOTIFY StatusWordChanged)
    Q_PROPERTY(QList<double> ActualPosition READ ActualPosition WRITE setActualPosition NOTIFY ActualPositionChanged)
public:
    explicit RightViewModel(QObject *parent = nullptr);

signals:
    void StatusWordChanged();
    void StatusWordStrChanged();
    void ActualPositionChanged();

public slots:
    QList<QString> StatusWord();
    QString StatusWordStr();
    QList<double> ActualPosition();
    void setStatusWord(QList<QString> value);
    void UpdateStatusWord();
    void setActualPosition(QList<double> value);
    void setStatusWordStr(QString value);
    void UpdateActualPosition(bool _joint, int cmb_frame_currentIndex);

private:
    QList<QString> *_statusWord;
    QList<double> *_actualPosition;
    Controller *controller;
    QString _statusWordStr;
};


#endif // RIGHTVIEWMODEL_H
