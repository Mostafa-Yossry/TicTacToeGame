/****************************************************************************
** Meta object code from reading C++ file 'tictactoewidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../tictactoewidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tictactoewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSTicTacToeWidgetENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSTicTacToeWidgetENDCLASS = QtMocHelpers::stringData(
    "TicTacToeWidget",
    "finishgame",
    "",
    "changeplayer",
    "sendaimoves",
    "triggerAi",
    "startaimovecalculation",
    "restartgame",
    "setaimode",
    "setTwoplayermode",
    "handleclicksonboard",
    "handleendofgame",
    "triggeraimodecalculation",
    "calculateaimove",
    "transmitaimove"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTicTacToeWidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x06,    1 /* Public */,
       3,    0,   93,    2, 0x06,    2 /* Public */,
       4,    1,   94,    2, 0x06,    3 /* Public */,
       5,    0,   97,    2, 0x06,    5 /* Public */,
       6,    0,   98,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   99,    2, 0x0a,    7 /* Public */,
       8,    0,  100,    2, 0x0a,    8 /* Public */,
       9,    0,  101,    2, 0x0a,    9 /* Public */,
      10,    1,  102,    2, 0x0a,   10 /* Public */,
      11,    0,  105,    2, 0x0a,   12 /* Public */,
      12,    0,  106,    2, 0x0a,   13 /* Public */,
      13,    0,  107,    2, 0x0a,   14 /* Public */,
      14,    1,  108,    2, 0x0a,   15 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject TicTacToeWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSTicTacToeWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTicTacToeWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTicTacToeWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TicTacToeWidget, std::true_type>,
        // method 'finishgame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changeplayer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendaimoves'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'triggerAi'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'startaimovecalculation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'restartgame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setaimode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setTwoplayermode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleclicksonboard'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'handleendofgame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'triggeraimodecalculation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'calculateaimove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'transmitaimove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void TicTacToeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TicTacToeWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->finishgame(); break;
        case 1: _t->changeplayer(); break;
        case 2: _t->sendaimoves((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->triggerAi(); break;
        case 4: _t->startaimovecalculation(); break;
        case 5: _t->restartgame(); break;
        case 6: _t->setaimode(); break;
        case 7: _t->setTwoplayermode(); break;
        case 8: _t->handleclicksonboard((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->handleendofgame(); break;
        case 10: _t->triggeraimodecalculation(); break;
        case 11: _t->calculateaimove(); break;
        case 12: _t->transmitaimove((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TicTacToeWidget::*)();
            if (_t _q_method = &TicTacToeWidget::finishgame; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TicTacToeWidget::*)();
            if (_t _q_method = &TicTacToeWidget::changeplayer; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TicTacToeWidget::*)(int );
            if (_t _q_method = &TicTacToeWidget::sendaimoves; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TicTacToeWidget::*)();
            if (_t _q_method = &TicTacToeWidget::triggerAi; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TicTacToeWidget::*)();
            if (_t _q_method = &TicTacToeWidget::startaimovecalculation; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject *TicTacToeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TicTacToeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTicTacToeWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TicTacToeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void TicTacToeWidget::finishgame()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TicTacToeWidget::changeplayer()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TicTacToeWidget::sendaimoves(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TicTacToeWidget::triggerAi()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void TicTacToeWidget::startaimovecalculation()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
