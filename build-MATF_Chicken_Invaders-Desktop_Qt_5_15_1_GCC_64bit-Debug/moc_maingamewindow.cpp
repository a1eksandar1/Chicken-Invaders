/****************************************************************************
** Meta object code from reading C++ file 'maingamewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../MATF_Chicken_Invaders/headers/maingamewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maingamewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AnimatedGraphicsItem_t {
    QByteArrayData data[2];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AnimatedGraphicsItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AnimatedGraphicsItem_t qt_meta_stringdata_AnimatedGraphicsItem = {
    {
QT_MOC_LITERAL(0, 0, 20), // "AnimatedGraphicsItem"
QT_MOC_LITERAL(1, 21, 3) // "pos"

    },
    "AnimatedGraphicsItem\0pos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AnimatedGraphicsItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       1,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QPointF, 0x00095103,

       0        // eod
};

void AnimatedGraphicsItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<AnimatedGraphicsItem *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QPointF*>(_v) = _t->pos(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<AnimatedGraphicsItem *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPos(*reinterpret_cast< QPointF*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject AnimatedGraphicsItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AnimatedGraphicsItem.data,
    qt_meta_data_AnimatedGraphicsItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AnimatedGraphicsItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnimatedGraphicsItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AnimatedGraphicsItem.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(this);
    return QObject::qt_metacast(_clname);
}

int AnimatedGraphicsItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
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
struct qt_meta_stringdata_MainGameWindow_t {
    QByteArrayData data[24];
    char stringdata0[283];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainGameWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainGameWindow_t qt_meta_stringdata_MainGameWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MainGameWindow"
QT_MOC_LITERAL(1, 15, 9), // "gameStart"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 3), // "esc"
QT_MOC_LITERAL(4, 30, 13), // "removeMessage"
QT_MOC_LITERAL(5, 44, 11), // "slot_level1"
QT_MOC_LITERAL(6, 56, 11), // "slot_level2"
QT_MOC_LITERAL(7, 68, 11), // "slot_level3"
QT_MOC_LITERAL(8, 80, 11), // "slot_level4"
QT_MOC_LITERAL(9, 92, 11), // "slot_level5"
QT_MOC_LITERAL(10, 104, 11), // "slot_level6"
QT_MOC_LITERAL(11, 116, 11), // "slot_level7"
QT_MOC_LITERAL(12, 128, 11), // "slot_level8"
QT_MOC_LITERAL(13, 140, 11), // "slot_level9"
QT_MOC_LITERAL(14, 152, 16), // "stopPrepareMusic"
QT_MOC_LITERAL(15, 169, 16), // "playPrepareMusic"
QT_MOC_LITERAL(16, 186, 14), // "setUserMessage"
QT_MOC_LITERAL(17, 201, 9), // "endOfGame"
QT_MOC_LITERAL(18, 211, 12), // "continueGame"
QT_MOC_LITERAL(19, 224, 7), // "victory"
QT_MOC_LITERAL(20, 232, 13), // "increaseScore"
QT_MOC_LITERAL(21, 246, 4), // "step"
QT_MOC_LITERAL(22, 251, 12), // "updatePlayer"
QT_MOC_LITERAL(23, 264, 18) // "current_high_score"

    },
    "MainGameWindow\0gameStart\0\0esc\0"
    "removeMessage\0slot_level1\0slot_level2\0"
    "slot_level3\0slot_level4\0slot_level5\0"
    "slot_level6\0slot_level7\0slot_level8\0"
    "slot_level9\0stopPrepareMusic\0"
    "playPrepareMusic\0setUserMessage\0"
    "endOfGame\0continueGame\0victory\0"
    "increaseScore\0step\0updatePlayer\0"
    "current_high_score"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainGameWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x06 /* Public */,
       3,    0,  115,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  116,    2, 0x0a /* Public */,
       5,    0,  117,    2, 0x0a /* Public */,
       6,    0,  118,    2, 0x0a /* Public */,
       7,    0,  119,    2, 0x0a /* Public */,
       8,    0,  120,    2, 0x0a /* Public */,
       9,    0,  121,    2, 0x0a /* Public */,
      10,    0,  122,    2, 0x0a /* Public */,
      11,    0,  123,    2, 0x0a /* Public */,
      12,    0,  124,    2, 0x0a /* Public */,
      13,    0,  125,    2, 0x0a /* Public */,
      14,    0,  126,    2, 0x0a /* Public */,
      15,    0,  127,    2, 0x0a /* Public */,
      16,    0,  128,    2, 0x0a /* Public */,
      17,    0,  129,    2, 0x0a /* Public */,
      18,    0,  130,    2, 0x0a /* Public */,
      19,    0,  131,    2, 0x0a /* Public */,
      20,    1,  132,    2, 0x0a /* Public */,
      22,    1,  135,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Int,   23,

       0        // eod
};

void MainGameWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainGameWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gameStart(); break;
        case 1: _t->esc(); break;
        case 2: _t->removeMessage(); break;
        case 3: _t->slot_level1(); break;
        case 4: _t->slot_level2(); break;
        case 5: _t->slot_level3(); break;
        case 6: _t->slot_level4(); break;
        case 7: _t->slot_level5(); break;
        case 8: _t->slot_level6(); break;
        case 9: _t->slot_level7(); break;
        case 10: _t->slot_level8(); break;
        case 11: _t->slot_level9(); break;
        case 12: _t->stopPrepareMusic(); break;
        case 13: _t->playPrepareMusic(); break;
        case 14: _t->setUserMessage(); break;
        case 15: _t->endOfGame(); break;
        case 16: _t->continueGame(); break;
        case 17: _t->victory(); break;
        case 18: _t->increaseScore((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->updatePlayer((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainGameWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainGameWindow::gameStart)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainGameWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainGameWindow::esc)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainGameWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MainGameWindow.data,
    qt_meta_data_MainGameWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainGameWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainGameWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainGameWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MainGameWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void MainGameWindow::gameStart()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainGameWindow::esc()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
