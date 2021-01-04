/****************************************************************************
** Meta object code from reading C++ file 'spaceship.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../MATF_Chicken_Invaders/headers/spaceship.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spaceship.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Spaceship_t {
    QByteArrayData data[7];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Spaceship_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Spaceship_t qt_meta_stringdata_Spaceship = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Spaceship"
QT_MOC_LITERAL(1, 10, 18), // "spaceshipDestroyed"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "changeScore"
QT_MOC_LITERAL(4, 42, 4), // "step"
QT_MOC_LITERAL(5, 47, 4), // "move"
QT_MOC_LITERAL(6, 52, 30) // "enableSpaceshipAfterDestroying"

    },
    "Spaceship\0spaceshipDestroyed\0\0changeScore\0"
    "step\0move\0enableSpaceshipAfterDestroying"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Spaceship[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   38,    2, 0x0a /* Public */,
       6,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Spaceship::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Spaceship *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->spaceshipDestroyed(); break;
        case 1: _t->changeScore((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->move(); break;
        case 3: _t->enableSpaceshipAfterDestroying(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Spaceship::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Spaceship::spaceshipDestroyed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Spaceship::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Spaceship::changeScore)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Spaceship::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Spaceship.data,
    qt_meta_data_Spaceship,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Spaceship::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Spaceship::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Spaceship.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(this);
    return QObject::qt_metacast(_clname);
}

int Spaceship::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}

// SIGNAL 0
void Spaceship::spaceshipDestroyed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Spaceship::changeScore(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
