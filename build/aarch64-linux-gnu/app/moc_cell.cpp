/****************************************************************************
** Meta object code from reading C++ file 'cell.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../cpp/cell.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cell.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Cell_t {
    QByteArrayData data[16];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cell_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cell_t qt_meta_stringdata_Cell = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Cell"
QT_MOC_LITERAL(1, 5, 11), // "cellChanged"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 15), // "rotationChanged"
QT_MOC_LITERAL(4, 34, 14), // "flowingChanged"
QT_MOC_LITERAL(5, 49, 11), // "typeChanged"
QT_MOC_LITERAL(6, 61, 9), // "TYPE_WIRE"
QT_MOC_LITERAL(7, 71, 11), // "TYPE_SOURCE"
QT_MOC_LITERAL(8, 83, 16), // "TYPE_DESTINATION"
QT_MOC_LITERAL(9, 100, 8), // "cellType"
QT_MOC_LITERAL(10, 109, 5), // "north"
QT_MOC_LITERAL(11, 115, 4), // "east"
QT_MOC_LITERAL(12, 120, 5), // "south"
QT_MOC_LITERAL(13, 126, 4), // "west"
QT_MOC_LITERAL(14, 131, 12), // "cellRotation"
QT_MOC_LITERAL(15, 144, 7) // "flowing"

    },
    "Cell\0cellChanged\0\0rotationChanged\0"
    "flowingChanged\0typeChanged\0TYPE_WIRE\0"
    "TYPE_SOURCE\0TYPE_DESTINATION\0cellType\0"
    "north\0east\0south\0west\0cellRotation\0"
    "flowing"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cell[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
      10,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,
       5,    0,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       6, QMetaType::Int, 0x00095401,
       7, QMetaType::Int, 0x00095401,
       8, QMetaType::Int, 0x00095401,
       9, QMetaType::Int, 0x00495001,
      10, QMetaType::Bool, 0x00495001,
      11, QMetaType::Bool, 0x00495001,
      12, QMetaType::Bool, 0x00495001,
      13, QMetaType::Bool, 0x00495001,
      14, QMetaType::Int, 0x00495001,
      15, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       0,
       0,
       0,
       3,
       0,
       0,
       0,
       0,
       1,
       2,

       0        // eod
};

void Cell::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Cell *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cellChanged(); break;
        case 1: _t->rotationChanged(); break;
        case 2: _t->flowingChanged(); break;
        case 3: _t->typeChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Cell::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cell::cellChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Cell::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cell::rotationChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Cell::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cell::flowingChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Cell::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Cell::typeChanged)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Cell *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->TYPE_WIRE(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->TYPE_SOURCE(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->TYPE_DESTINATION(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->getCellType(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->getOriginalNorth(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->getOriginalEast(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->getOriginalSouth(); break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->getOriginalWest(); break;
        case 8: *reinterpret_cast< int*>(_v) = _t->getRotation(); break;
        case 9: *reinterpret_cast< bool*>(_v) = _t->getFlowing(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Cell::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Cell.data,
    qt_meta_data_Cell,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Cell::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cell::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Cell.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Cell::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 10;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Cell::cellChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Cell::rotationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Cell::flowingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Cell::typeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
