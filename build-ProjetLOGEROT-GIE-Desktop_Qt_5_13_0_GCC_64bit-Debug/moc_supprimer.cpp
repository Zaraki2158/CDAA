/****************************************************************************
** Meta object code from reading C++ file 'supprimer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ProjetLOGEROT-GIE/supprimer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'supprimer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Supprimer_t {
    QByteArrayData data[10];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Supprimer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Supprimer_t qt_meta_stringdata_Supprimer = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Supprimer"
QT_MOC_LITERAL(1, 10, 9), // "envoiSupr"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 7), // "Contact"
QT_MOC_LITERAL(4, 29, 1), // "c"
QT_MOC_LITERAL(5, 31, 19), // "on_NomE_textChanged"
QT_MOC_LITERAL(6, 51, 4), // "arg1"
QT_MOC_LITERAL(7, 56, 22), // "on_PrenomE_textChanged"
QT_MOC_LITERAL(8, 79, 22), // "on_Supprimer_2_clicked"
QT_MOC_LITERAL(9, 102, 18) // "on_Annuler_clicked"

    },
    "Supprimer\0envoiSupr\0\0Contact\0c\0"
    "on_NomE_textChanged\0arg1\0"
    "on_PrenomE_textChanged\0on_Supprimer_2_clicked\0"
    "on_Annuler_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Supprimer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   42,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,
       8,    0,   48,    2, 0x08 /* Private */,
       9,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Supprimer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Supprimer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->envoiSupr((*reinterpret_cast< Contact(*)>(_a[1]))); break;
        case 1: _t->on_NomE_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_PrenomE_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_Supprimer_2_clicked(); break;
        case 4: _t->on_Annuler_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Supprimer::*)(Contact );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Supprimer::envoiSupr)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Supprimer::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Supprimer.data,
    qt_meta_data_Supprimer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Supprimer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Supprimer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Supprimer.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Supprimer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Supprimer::envoiSupr(Contact _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
