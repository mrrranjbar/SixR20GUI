/****************************************************************************
** Meta object code from reading C++ file 'iohandlingviewmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Model/ViewModel/iohandlingviewmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'iohandlingviewmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_iohandlingviewmodel_t {
    QByteArrayData data[10];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_iohandlingviewmodel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_iohandlingviewmodel_t qt_meta_stringdata_iohandlingviewmodel = {
    {
QT_MOC_LITERAL(0, 0, 19), // "iohandlingviewmodel"
QT_MOC_LITERAL(1, 20, 9), // "IoChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8), // "IoOutput"
QT_MOC_LITERAL(4, 40, 11), // "QList<bool>"
QT_MOC_LITERAL(5, 52, 16), // "setOutputAtIndex"
QT_MOC_LITERAL(6, 69, 5), // "value"
QT_MOC_LITERAL(7, 75, 5), // "index"
QT_MOC_LITERAL(8, 81, 9), // "setOutput"
QT_MOC_LITERAL(9, 91, 8) // "updateIO"

    },
    "iohandlingviewmodel\0IoChanged\0\0IoOutput\0"
    "QList<bool>\0setOutputAtIndex\0value\0"
    "index\0setOutput\0updateIO"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_iohandlingviewmodel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       1,   50, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x0a /* Public */,
       5,    2,   41,    2, 0x0a /* Public */,
       8,    1,   46,    2, 0x0a /* Public */,
       9,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    0x80000000 | 4,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    6,    7,
    QMetaType::Void, 0x80000000 | 4,    6,
    QMetaType::Void,

 // properties: name, type, flags
       3, 0x80000000 | 4, 0x0049500b,

 // properties: notify_signal_id
       0,

       0        // eod
};

void iohandlingviewmodel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        iohandlingviewmodel *_t = static_cast<iohandlingviewmodel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->IoChanged(); break;
        case 1: { QList<bool> _r = _t->IoOutput();
            if (_a[0]) *reinterpret_cast< QList<bool>*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->setOutputAtIndex((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->setOutput((*reinterpret_cast< QList<bool>(*)>(_a[1]))); break;
        case 4: _t->updateIO(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<bool> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (iohandlingviewmodel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&iohandlingviewmodel::IoChanged)) {
                *result = 0;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<bool> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        iohandlingviewmodel *_t = static_cast<iohandlingviewmodel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<bool>*>(_v) = _t->IoOutput(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        iohandlingviewmodel *_t = static_cast<iohandlingviewmodel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setOutput(*reinterpret_cast< QList<bool>*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject iohandlingviewmodel::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_iohandlingviewmodel.data,
    qt_meta_data_iohandlingviewmodel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *iohandlingviewmodel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *iohandlingviewmodel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_iohandlingviewmodel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int iohandlingviewmodel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void iohandlingviewmodel::IoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
