#ifndef FILEIO_H
#define FILEIO_H

#include <QtCore>

class FileIO : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(FileIO)
    Q_PROPERTY(QUrl source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QString homeAddress READ getHomeAddress)
public:
    FileIO(QObject *parent = 0);
    QString getHomeAddress();
    ~FileIO();

    Q_INVOKABLE void read();
    Q_INVOKABLE void write();
    QUrl source() const;
    QString text() const;
public slots:
    void setSource(QUrl source);
    void setText(QString text);
    QString getExistProjectList(QString path);
signals:
    void sourceChanged(QUrl arg);
    void textChanged(QString arg);
private:
    QUrl m_source;
    QString m_text;
    QString _home_address;
};

#endif // FILEIO_H
