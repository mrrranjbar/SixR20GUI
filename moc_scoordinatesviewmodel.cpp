/****************************************************************************
** Meta object code from reading C++ file 'scoordinatesviewmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Model/ViewModel/scoordinatesviewmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scoordinatesviewmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_scoordinatesviewmodel_t {
    QByteArrayData data[12];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_scoordinatesviewmodel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_scoordinatesviewmodel_t qt_meta_stringdata_scoordinatesviewmodel = {
    {
QT_MOC_LITERAL(0, 0, 21), // "scoordinatesviewmodel"
QT_MOC_LITERAL(1, 22, 9), // "saveFrame"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 2), // "id"
QT_MOC_LITERAL(4, 36, 4), // "name"
QT_MOC_LITERAL(5, 41, 1), // "x"
QT_MOC_LITERAL(6, 43, 1), // "y"
QT_MOC_LITERAL(7, 45, 1), // "z"
QT_MOC_LITERAL(8, 47, 1), // "a"
QT_MOC_LITERAL(9, 49, 1), // "b"
QT_MOC_LITERAL(10, 51, 1), // "c"
QT_MOC_LITERAL(11, 53, 9) // "readFrame"

    },
    "scoordinatesviewmodel\0saveFrame\0\0id\0"
    "name\0x\0y\0z\0a\0b\0c\0readFrame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_scoordinatesviewmodel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    8,   24,    2, 0x0a /* Public */,
      11,    0,   41,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,    7,    8,    9,   10,
    QMetaType::Void,

       0        // eod
};

void scoordinatesviewmodel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        scoordinatesviewmodel *_t = static_cast<scoordinatesviewmodel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->saveFrame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8]))); break;
        case 1: _t->readFrame(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject scoordinatesviewmodel::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_scoordinatesviewmodel.data,
    qt_meta_data_scoordinatesviewmodel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *scoordinatesviewmodel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *scoordinatesviewmodel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_scoordinatesviewmodel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int scoordinatesviewmodel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
