/****************************************************************************
** Meta object code from reading C++ file 'modifiercontact.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ProjetLOGEROT-GIE/modifiercontact.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modifiercontact.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModifierContact_t {
    QByteArrayData data[12];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModifierContact_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModifierContact_t qt_meta_stringdata_ModifierContact = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ModifierContact"
QT_MOC_LITERAL(1, 16, 10), // "envoiModif"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "Contact"
QT_MOC_LITERAL(4, 36, 1), // "c"
QT_MOC_LITERAL(5, 38, 5), // "modif"
QT_MOC_LITERAL(6, 44, 19), // "on_NomE_textChanged"
QT_MOC_LITERAL(7, 64, 4), // "arg1"
QT_MOC_LITERAL(8, 69, 22), // "on_PrenomE_textChanged"
QT_MOC_LITERAL(9, 92, 18), // "on_Annuler_clicked"
QT_MOC_LITERAL(10, 111, 19), // "on_Modifier_clicked"
QT_MOC_LITERAL(11, 131, 21) // "on_EPhoto_textChanged"

    },
    "ModifierContact\0envoiModif\0\0Contact\0"
    "c\0modif\0on_NomE_textChanged\0arg1\0"
    "on_PrenomE_textChanged\0on_Annuler_clicked\0"
    "on_Modifier_clicked\0on_EPhoto_textChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModifierContact[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   49,    2, 0x08 /* Private */,
       8,    1,   52,    2, 0x08 /* Private */,
       9,    0,   55,    2, 0x08 /* Private */,
      10,    0,   56,    2, 0x08 /* Private */,
      11,    1,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void ModifierContact::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ModifierContact *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->envoiModif((*reinterpret_cast< Contact(*)>(_a[1])),(*reinterpret_cast< Contact(*)>(_a[2]))); break;
        case 1: _t->on_NomE_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_PrenomE_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_Annuler_clicked(); break;
        case 4: _t->on_Modifier_clicked(); break;
        case 5: _t->on_EPhoto_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ModifierContact::*)(Contact , Contact );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModifierContact::envoiModif)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ModifierContact::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ModifierContact.data,
    qt_meta_data_ModifierContact,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ModifierContact::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModifierContact::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModifierContact.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ModifierContact::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ModifierContact::envoiModif(Contact _t1, Contact _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
