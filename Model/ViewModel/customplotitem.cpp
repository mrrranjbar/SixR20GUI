#include "customplotitem.h"
#include "qcustomplot.h"
#include <QDebug>

TrajectoryPointList<double> *QCustomPlot::Desired;

CustomPlotItem::CustomPlotItem( QQuickItem* parent ) : QQuickPaintedItem( parent )
    , m_CustomPlot( nullptr )
{
    setFlag( QQuickItem::ItemHasContents, true );
    // setRenderTarget(QQuickPaintedItem::FramebufferObject);
    // setAcceptHoverEvents(true);
    setAcceptedMouseButtons( Qt::AllButtons );

    connect( this, &QQuickPaintedItem::widthChanged, this, &CustomPlotItem::updateCustomPlotSize );
    connect( this, &QQuickPaintedItem::heightChanged, this, &CustomPlotItem::updateCustomPlotSize );
    controller = Controller::getInstance();
//    setStop(false);
}

CustomPlotItem::~CustomPlotItem()
{
    delete m_CustomPlot;
    m_CustomPlot = nullptr;
}

void CustomPlotItem::initCustomPlot()
{
    m_CustomPlot = new QCustomPlot();

    QCPAxisRect* axisRect = m_CustomPlot->axisRect();

    updateCustomPlotSize();
    for (int i = 0; i < 12; ++i) {

        m_CustomPlot->addGraph();
        if (i < 6 ){
            m_CustomPlot->graph( i )->setPen( QPen( Qt::red ) );
        }else if (i <12 ){
            m_CustomPlot->graph( i )->setPen( QPen( Qt::blue ) );
        }
    }
    m_CustomPlot->xAxis->setLabel( "T(0.01 s)" );
    m_CustomPlot->yAxis->setLabel( "S(Degree)" );
    m_CustomPlot->xAxis->setRange( 0, 10 );
    m_CustomPlot->yAxis->setRange( -180, 180 );
    m_CustomPlot ->setInteractions( QCP::iRangeDrag | QCP::iRangeZoom );

    _timerSeconds = 100;
    m_CustomPlot->setMotorNum(0);
    motorNumChanged(0);

    connect( m_CustomPlot, &QCustomPlot::afterReplot, this, &CustomPlotItem::onCustomReplot );

    connect( m_CustomPlot, SIGNAL( plottableClick( QCPAbstractPlottable*, QMouseEvent* ) ), this, SLOT( graphClicked( QCPAbstractPlottable* ) ) );
    m_CustomPlot->replot();
}
void CustomPlotItem::initCustomPlotall(int n)
{

    m_CustomPlot = new QCustomPlot();

    updateCustomPlotSize();

    m_CustomPlot->addGraph();
    m_CustomPlot->addGraph();
    m_CustomPlot->graph( 0 )->setPen( QPen( Qt::red ) );
    m_CustomPlot->graph( 1 )->setPen( QPen( Qt::blue ) );
    m_CustomPlot->xAxis->setLabel( "T(0.01 s)" );
    m_CustomPlot->yAxis->setLabel( "S(Degree)" );
    m_CustomPlot->xAxis->setRange( 0, 4 );
    m_CustomPlot->yAxis->setRange( -180, 180 );
    m_CustomPlot->setInteractions( QCP::iRangeDrag | QCP::iRangeZoom );


    _timerSeconds = 100;
    m_CustomPlot->setMotorNum(n);
    _isAll = true;

    connect( m_CustomPlot, &QCustomPlot::afterReplot, this, &CustomPlotItem::onCustomReplot );

    connect( m_CustomPlot, SIGNAL( plottableClick( QCPAbstractPlottable*, QMouseEvent* ) ), this, SLOT( graphClicked( QCPAbstractPlottable* ) ) );
    m_CustomPlot->replot();
}
void CustomPlotItem::startCustomPlot()
{

    _timerId = startTimer(_timerSeconds);
    _t = 0;

}

void CustomPlotItem::stopCustomPlot()
{
    killTimer(_timerId);
}

void CustomPlotItem::motorNumChanged(int motorNum)
{
    if(!_isAll){
        if(!(motorNum < 6 && motorNum >= 0)) setMotorNum(0);

        for (int i = 0; i < 12; i++) {
            m_CustomPlot->graph(i)->setVisible(false);
        }

        m_CustomPlot->graph(motorNum )->setVisible(true);
        m_CustomPlot->graph(motorNum + 6)->setVisible(true);

        m_CustomPlot->replot();
    }
}

void CustomPlotItem::setMotorNum(int motorNum)
{
    m_CustomPlot->setMotorNum(motorNum);
}

int CustomPlotItem::showType()
{
    return _showType;
}

void CustomPlotItem::setShowType(int showType)
{
    _showType = showType;
//    setMotorNum(m_CustomPlot->motorNum());
}

QCustomPlot *CustomPlotItem::customPlot()
{
    return m_CustomPlot;
}

void CustomPlotItem::setCustomPlot(QCustomPlot *CustomPlot)
{
    m_CustomPlot = CustomPlot;
}

void CustomPlotItem::paint( QPainter* painter )
{
    if (m_CustomPlot)
    {
        QPixmap    picture( boundingRect().size().toSize() );
        QCPPainter qcpPainter( &picture );

        m_CustomPlot->toPainter( &qcpPainter );

        painter->drawPixmap( QPoint(), picture );
    }
}

void CustomPlotItem::mousePressEvent( QMouseEvent* event )
{
    qDebug() << Q_FUNC_INFO;
    routeMouseEvents( event );
}

void CustomPlotItem::mouseReleaseEvent( QMouseEvent* event )
{
    qDebug() << Q_FUNC_INFO;
    routeMouseEvents( event );
}

void CustomPlotItem::mouseMoveEvent( QMouseEvent* event )
{
    routeMouseEvents( event );
}

void CustomPlotItem::mouseDoubleClickEvent( QMouseEvent* event )
{
    qDebug() << Q_FUNC_INFO;
    routeMouseEvents( event );
}

void CustomPlotItem::graphClicked( QCPAbstractPlottable* plottable )
{
    qDebug() << Q_FUNC_INFO << QString( "Clicked on graph '%1 " ).arg( plottable->name() );
}
void CustomPlotItem::timerEvent(QTimerEvent *event)
{
    static double totalTime;

    TrajectoryPointList<double> *desired = QCustomPlot::Desired;
    int ln = desired[0].TrajLength;
    if(_t>(ln/_timerSeconds)){
        stopCustomPlot();
    }else{
        int motorNum = m_CustomPlot->motorNum();
        if(_isAll){
            m_CustomPlot->graph(0)->addData(totalTime, desired[motorNum].getPoint(_t*_timerSeconds));
            m_CustomPlot->graph(1)->addData(totalTime, 0);

        }else{
            for (int i = 0;i < 6;i++) {
//                m_CustomPlot->graph(i+6)->addData(totalTime, controller->beckhoff->ActualPositions[i]*controller->robot->PulsToDegFactor1[i]);
                m_CustomPlot->graph(i)->addData(totalTime, desired[i].getPoint(_t*_timerSeconds));
                m_CustomPlot->graph(i+6)->addData(totalTime, 0);
                qDebug() << Q_FUNC_INFO << QString("Adding dot t = %1, S = %2").arg(totalTime).arg(desired[i].getPoint(_t*_timerSeconds));
            }
        }
        _t++;
        totalTime++;
        m_CustomPlot->xAxis->setRange(qMax(totalTime+1, static_cast<double>(m_CustomPlot->xAxis->range().size())),static_cast<double>(m_CustomPlot->xAxis->range().size()) , Qt::AlignRight);
        m_CustomPlot->replot();
    }
}
void CustomPlotItem::routeWheelEvents( QWheelEvent* event )
{
    if (m_CustomPlot)
    {
        QWheelEvent* newEvent = new QWheelEvent( event->pos(), event->delta(), event->buttons(), event->modifiers(), event->orientation() );
        QCoreApplication::postEvent( m_CustomPlot, newEvent );
    }
}
void CustomPlotItem::wheelEvent( QWheelEvent *event )
{
    routeWheelEvents( event );
}

void CustomPlotItem::routeMouseEvents( QMouseEvent* event )
{
    if (m_CustomPlot)
    {
        QMouseEvent* newEvent = new QMouseEvent( event->type(), event->localPos(), event->button(), event->buttons(), event->modifiers() );
        //QCoreApplication::sendEvent( m_CustomPlot, newEvent );
        QCoreApplication::postEvent( m_CustomPlot, newEvent );
    }
}

QCustomPlot* CustomPlotItem::getPlot()
{
    return m_CustomPlot;
}


void CustomPlotItem::updateCustomPlotSize()
{
    if (m_CustomPlot)
    {
        m_CustomPlot->setGeometry( 0, 0, width(), height() );
    }
}

void CustomPlotItem::onCustomReplot()
{
    qDebug() << Q_FUNC_INFO;
    update();
}

void CustomPlotItem::setupQuadraticDemo( QCustomPlot* customPlot )
{
    // make top right axes clones of bottom left axes:
    QCPAxisRect* axisRect = customPlot->axisRect();

    // generate some data:
    QVector<double> x( 101 ), y( 101 );
    for (int i = 0; i < 101; ++i)
    {
        x[i] = i;              // x goes from -1 to 1
        y[i] = sin(5*3.1415926535898*i/100);               // let's plot a quadratic function
    }
    // create graph and assign data to it:
    customPlot->addGraph();
    customPlot->graph( 0 )->setPen( QPen( Qt::red ) );
//    customPlot->graph( 0 )->setSelectedPen( QPen( Qt::blue, 2 ) );
    customPlot->graph( 0 )->setData( x, y );


    // give the axes some labels:
    customPlot->xAxis->setLabel( "x" );
    customPlot->yAxis->setLabel( "y" );
    // set axes ranges, so we see all data:
    customPlot->xAxis->setRange( 0, 100 );
    customPlot->yAxis->setRange( -1, 1 );

    customPlot ->setInteractions( QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables );
    connect( customPlot, SIGNAL( plottableClick( QCPAbstractPlottable*, QMouseEvent* ) ), this, SLOT( graphClicked( QCPAbstractPlottable* ) ) );
}
