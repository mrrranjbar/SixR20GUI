#pragma once

#include <QtQuick>
#include "qcustomplot.h"
#include "Model/Controller/controller.h"
//#include <vector>
class QCustomPlot;

class CustomPlotItem : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(int showType READ showType WRITE setShowType)
    Q_PROPERTY(QCustomPlot* m_CustomPlot READ customPlot WRITE setCustomPlot)

public:
    CustomPlotItem( QQuickItem* parent = 0);
    virtual ~CustomPlotItem();

    void paint( QPainter* painter );

    Q_INVOKABLE void initCustomPlot();

    Q_INVOKABLE void initCustomPlotall(int n);

protected:
    void routeMouseEvents( QMouseEvent* event );

    virtual void mousePressEvent( QMouseEvent* event );
    virtual void mouseReleaseEvent( QMouseEvent* event );
    virtual void mouseMoveEvent( QMouseEvent* event );
    virtual void mouseDoubleClickEvent( QMouseEvent* event );

    void setupQuadraticDemo( QCustomPlot* customPlot );

    void timerEvent(QTimerEvent *event);
    void routeWheelEvents(QWheelEvent *event);
    void wheelEvent(QWheelEvent *event);
public slots:
    QCustomPlot *getPlot();
    void startCustomPlot();
    void stopCustomPlot();
    void motorNumChanged(int motorNum);
    void setMotorNum(int motorNum);
    int showType();
    void setShowType(int showType);

    QCustomPlot *customPlot() ;
    void setCustomPlot(QCustomPlot *CustomPlot);
private:
    QCustomPlot*         m_CustomPlot;

    static std::vector<QCustomPlot*> *m_CustomPlotall;

    Controller *controller;
    int _timerId;
    int _timerSeconds;
    double _t;
    int _showType;
    bool _isAll = false;

private slots:
    void graphClicked( QCPAbstractPlottable* plottable );
    void onCustomReplot();
    void updateCustomPlotSize();

};
