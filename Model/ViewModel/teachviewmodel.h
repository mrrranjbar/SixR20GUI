#ifndef TEACHVIEWMODEL_H
#define TEACHVIEWMODEL_H

#include <QObject>

class TeachViewModel : public QObject
{
    Q_OBJECT
public:
    explicit TeachViewModel(QObject *parent = nullptr);


Q_SIGNALS:

public Q_SLOTS:
    void UpdateStatusWord();
};

#endif // TEACHVIEWMODEL_H
