#ifndef BOTTOMVIEWMODEL_H
#define BOTTOMVIEWMODEL_H

#include <QObject>

class BottomViewModel : public QObject
{
    Q_OBJECT
public:
    explicit BottomViewModel(QObject *parent = nullptr);

Q_SIGNALS:

public Q_SLOTS:
};

#endif // BOTTOMVIEWMODEL_H