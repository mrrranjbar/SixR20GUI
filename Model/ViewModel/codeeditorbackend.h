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
public:
    CodeEditorBackend();
    QString text() const;
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
        CIRC=8
    };
signals:
    void textChanged(QString text);
    int cursorPos();
    void fileUrlChanged(QUrl fileUrl);
    void fileNameChanged(QString fileName);

public slots:
    void setText(QString text);
    void setFileUrl(QUrl fileUrl);
    void setFileName(QString fileName);
private:
    QString m_text;
    QUrl m_fileUrl;
    QString m_fileName;


    /// Antlr Part
    /// this part is only for interpreter and is separated from GUI and file managment
public:
    QThread *th;
    BeginInterpreter *Am;
Q_SIGNALS:
    void AntlrStart();
    void lineSelect(int start, int end);
public Q_SLOTS:
    void play();
    void changedRunningLine();
    QString addCommandToCurrentLine(int cmd, QString targetP1,QString targetP2,QString targetP3,QString frameType, QString frameTargetPoint);
    void setCursorPos(int pos);
private:
    Controller *controller;
};

#endif // CODEEDITORBACKEND_H
