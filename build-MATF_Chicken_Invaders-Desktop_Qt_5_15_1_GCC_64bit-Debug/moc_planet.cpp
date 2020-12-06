/****************************************************************************
** Meta object code from reading C++ file 'planet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../MATF_Chicken_Invaders/headers/planet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'planet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Planet_t {
    QByteArrayData data[11];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Planet_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Planet_t qt_meta_stringdata_Planet = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Planet"
QT_MOC_LITERAL(1, 7, 14), // "neptuneClicked"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "plutoClicked"
QT_MOC_LITERAL(4, 36, 13), // "uranusClicked"
QT_MOC_LITERAL(5, 50, 13), // "saturnClicked"
QT_MOC_LITERAL(6, 64, 14), // "jupiterClicked"
QT_MOC_LITERAL(7, 79, 11), // "marsClicked"
QT_MOC_LITERAL(8, 91, 12), // "earthClicked"
QT_MOC_LITERAL(9, 104, 12), // "venusClicked"
QT_MOC_LITERAL(10, 117, 14) // "mercuryClicked"

    },
    "Planet\0neptuneClicked\0\0plutoClicked\0"
    "uranusClicked\0saturnClicked\0jupiterClicked\0"
    "marsClicked\0earthClicked\0venusClicked\0"
    "mercuryClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Planet[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x06 /* Public */,
       7,    0,   64,    2, 0x06 /* Public */,
       8,    0,   65,    2, 0x06 /* Public */,
       9,    0,   66,    2, 0x06 /* Public */,
      10,    0,   67,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Planet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Planet *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->neptuneClicked(); break;
        case 1: _t->plutoClicked(); break;
        case 2: _t->uranusClicked(); break;
        case 3: _t->saturnClicked(); break;
        case 4: _t->jupiterClicked(); break;
        case 5: _t->marsClicked(); break;
        case 6: _t->earthClicked(); break;
        case 7: _t->venusClicked(); break;
        case 8: _t->mercuryClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Planet::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Planet::neptuneClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Planet::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Planet::plutoClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Planet::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Planet::uranusClicked)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Planet::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Planet::saturnClicked)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Planet::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Planet::jupiterClicked)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Planet::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Planet::marsClicked)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Planet::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Planet::earthClicked)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Planet::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Planet::venusClicked)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Planet::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Planet::mercuryClicked)) {
                *result = 8;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Planet::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Planet.data,
    qt_meta_data_Planet,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Planet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Planet::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Planet.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(this);
    return QObject::qt_metacast(_clname);
}

int Planet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Planet::neptuneClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Planet::plutoClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Planet::uranusClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Planet::saturnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Planet::jupiterClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Planet::marsClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Planet::earthClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Planet::venusClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Planet::mercuryClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
