/****************************************************************************
** Meta object code from reading C++ file 'logic.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../cpp/logic.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Logic_t {
    QByteArrayData data[23];
    char stringdata0[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Logic_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Logic_t qt_meta_stringdata_Logic = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Logic"
QT_MOC_LITERAL(1, 6, 16), // "gameStateChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "cellsChanged"
QT_MOC_LITERAL(4, 37, 11), // "timeChanged"
QT_MOC_LITERAL(5, 49, 12), // "movesChanged"
QT_MOC_LITERAL(6, 62, 7), // "newGame"
QT_MOC_LITERAL(7, 70, 4), // "rows"
QT_MOC_LITERAL(8, 75, 4), // "cols"
QT_MOC_LITERAL(9, 80, 7), // "sources"
QT_MOC_LITERAL(10, 88, 5), // "moves"
QT_MOC_LITERAL(11, 94, 6), // "rotate"
QT_MOC_LITERAL(12, 101, 5), // "index"
QT_MOC_LITERAL(13, 107, 14), // "isGameFinished"
QT_MOC_LITERAL(14, 122, 12), // "GAME_LOADING"
QT_MOC_LITERAL(15, 135, 10), // "GAME_READY"
QT_MOC_LITERAL(16, 146, 12), // "GAME_RUNNING"
QT_MOC_LITERAL(17, 159, 11), // "GAME_PAUSED"
QT_MOC_LITERAL(18, 171, 13), // "GAME_FINISHED"
QT_MOC_LITERAL(19, 185, 9), // "gameState"
QT_MOC_LITERAL(20, 195, 5), // "cells"
QT_MOC_LITERAL(21, 201, 22), // "QQmlListProperty<Cell>"
QT_MOC_LITERAL(22, 224, 4) // "time"

    },
    "Logic\0gameStateChanged\0\0cellsChanged\0"
    "timeChanged\0movesChanged\0newGame\0rows\0"
    "cols\0sources\0moves\0rotate\0index\0"
    "isGameFinished\0GAME_LOADING\0GAME_READY\0"
    "GAME_RUNNING\0GAME_PAUSED\0GAME_FINISHED\0"
    "gameState\0cells\0QQmlListProperty<Cell>\0"
    "time"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Logic[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
      11,   66, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    0,   52,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       6,    4,   53,    2, 0x02 /* Public */,
      11,    1,   62,    2, 0x02 /* Public */,
      13,    0,   65,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    7,    8,    9,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Bool,

 // properties: name, type, flags
      14, QMetaType::Int, 0x00095401,
      15, QMetaType::Int, 0x00095401,
      16, QMetaType::Int, 0x00095401,
      17, QMetaType::Int, 0x00095401,
      18, QMetaType::Int, 0x00095401,
      19, QMetaType::Int, 0x00495103,
      20, 0x80000000 | 21, 0x00495009,
      10, QMetaType::Int, 0x00495001,
       7, QMetaType::Int, 0x00495001,
       8, QMetaType::Int, 0x00495001,
      22, QMetaType::Float, 0x00495103,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,
       0,
       1,
       3,
       1,
       1,
       2,

       0        // eod
};

void Logic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Logic *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gameStateChanged(); break;
        case 1: _t->cellsChanged(); break;
        case 2: _t->timeChanged(); break;
        case 3: _t->movesChanged(); break;
        case 4: _t->newGame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 5: _t->rotate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: { bool _r = _t->isGameFinished();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Logic::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Logic::gameStateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Logic::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Logic::cellsChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Logic::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Logic::timeChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Logic::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Logic::movesChanged)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Logic *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->GAME_LOADING(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->GAME_READY(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->GAME_RUNNING(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->GAME_PAUSED(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->GAME_FINISHED(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->getGameState(); break;
        case 6: *reinterpret_cast< QQmlListProperty<Cell>*>(_v) = _t->getCells(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->getMoves(); break;
        case 8: *reinterpret_cast< int*>(_v) = _t->getRows(); break;
        case 9: *reinterpret_cast< int*>(_v) = _t->getCols(); break;
        case 10: *reinterpret_cast< float*>(_v) = _t->getTime(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Logic *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 5: _t->setGameState(*reinterpret_cast< int*>(_v)); break;
        case 10: _t->setTime(*reinterpret_cast< float*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Logic::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Logic.data,
    qt_meta_data_Logic,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Logic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Logic::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Logic.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Logic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 11;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Logic::gameStateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Logic::cellsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Logic::timeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Logic::movesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
