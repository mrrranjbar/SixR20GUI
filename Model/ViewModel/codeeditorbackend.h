#ifndef CODEEDITORBACKEND_H
#define CODEEDITORBACKEND_H
#include "Model/Controller/controller.h"
#undef emit
#include "begininterpreter.h"
#define emit
#include <QThread>

#include <QQuickItem>

class CodeEditorBackend : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QUrl fileUrl READ fileUrl WRITE setFileUrl NOTIFY fileUrlChanged)
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName NOTIFY fileNameChanged)
    Q_PROPERTY(QString Errors READ Errors WRITE setErrors NOTIFY ErrorsChanged)

public:
    QString Errors();
    CodeEditorBackend();
    QString text() const;
    void setErrors(QString value);
    QUrl fileUrl() const;
    QString fileName() const;
    Q_INVOKABLE bool load();
    Q_INVOKABLE bool save();
    int cursorPosition;
    enum LanguageCMD{
        IF=0,
        IFELSE=1,
        FOR=2,
        WHILE=3,
        SETFRAME=4,
        INTERRUPT=5,
        PTP=6,
        LIN=7,
        CIRC=8,
        SUBROUTINE=9,
        WAITFOR=10,
        WAITSEC=11,
        INTERRUPT_MAIN=12,
        SUBROUTINE_MAIN=13,
        GOTOSTART=14,
        CONFIG=15,
        SETINPUT=16,
        SETOUTPUT=17,
        PTPDIRECT=18,
        LINDIRECT=19,
        CIRCDIRECT=20
    };
signals:
    void textChanged(QString text);
    int cursorPos();
    void fileUrlChanged(QUrl fileUrl);
    void fileNameChanged(QString fileName);
    void ErrorsChanged();

public slots:
    void setText(QString text);
    void setFileUrl(QUrl fileUrl);
    void setFileName(QString fileName);
    bool createDirectory(QString path);

private:
    QString m_text;
    QUrl m_fileUrl;
    QString m_fileName;
    QString _errors;
    bool _stopMovement;


    /// Antlr Part
    /// this part is only for interpreter and is separated from GUI and file managment
public:
    QThread *th;
    BeginInterpreter *Am;
Q_SIGNALS:
    void AntlrStart();
    void lineSelect(int start, int end);
public Q_SLOTS:
    void play(QString runFromLine);
    void pause();
    void stop();
    void changedRunningLine();
    QString addCommandToCurrentLine(int cmd, QString targetP1,QString targetP2,QString targetP3,QString frameType, QString frameTargetPoint, QString moveParam, QString theta, QString exp1, QString exp2, QString id);
    void setCursorPos(int pos);
private:
    Controller *controller;
};

#endif // CODEEDITORBACKEND_H
