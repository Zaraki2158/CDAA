/****************************************************************************
** Meta object code from reading C++ file 'interactionstodo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ProjetLOGEROT-GIE/interactionstodo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'interactionstodo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InteractionsTodo_t {
    QByteArrayData data[12];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InteractionsTodo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InteractionsTodo_t qt_meta_stringdata_InteractionsTodo = {
    {
QT_MOC_LITERAL(0, 0, 16), // "InteractionsTodo"
QT_MOC_LITERAL(1, 17, 13), // "EnvoiInteract"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 7), // "Contact"
QT_MOC_LITERAL(4, 40, 1), // "c"
QT_MOC_LITERAL(5, 42, 11), // "Interaction"
QT_MOC_LITERAL(6, 54, 1), // "i"
QT_MOC_LITERAL(7, 56, 21), // "on_NomE_3_textChanged"
QT_MOC_LITERAL(8, 78, 4), // "arg1"
QT_MOC_LITERAL(9, 83, 24), // "on_PrenomE_3_textChanged"
QT_MOC_LITERAL(10, 108, 20), // "on_AjoutTodo_clicked"
QT_MOC_LITERAL(11, 129, 19) // "on_Interact_clicked"

    },
    "InteractionsTodo\0EnvoiInteract\0\0Contact\0"
    "c\0Interaction\0i\0on_NomE_3_textChanged\0"
    "arg1\0on_PrenomE_3_textChanged\0"
    "on_AjoutTodo_clicked\0on_Interact_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InteractionsTodo[] = {

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
       1,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   44,    2, 0x08 /* Private */,
       9,    1,   47,    2, 0x08 /* Private */,
      10,    0,   50,    2, 0x08 /* Private */,
      11,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void InteractionsTodo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InteractionsTodo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->EnvoiInteract((*reinterpret_cast< Contact(*)>(_a[1])),(*reinterpret_cast< Interaction(*)>(_a[2]))); break;
        case 1: _t->on_NomE_3_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_PrenomE_3_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_AjoutTodo_clicked(); break;
        case 4: _t->on_Interact_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (InteractionsTodo::*)(Contact , Interaction );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InteractionsTodo::EnvoiInteract)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject InteractionsTodo::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_InteractionsTodo.data,
    qt_meta_data_InteractionsTodo,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *InteractionsTodo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InteractionsTodo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InteractionsTodo.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int InteractionsTodo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void InteractionsTodo::EnvoiInteract(Contact _t1, Interaction _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
