/****************************************************************************
** Meta object code from reading C++ file 'CalculatorDialog.h'
**
** Created: Mon Jan 18 10:31:09 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CalculatorDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CalculatorDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CalculatorDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      37,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CalculatorDialog[] = {
    "CalculatorDialog\0\0enableCalcButton()\0"
    "calClicked()\0"
};

void CalculatorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CalculatorDialog *_t = static_cast<CalculatorDialog *>(_o);
        switch (_id) {
        case 0: _t->enableCalcButton(); break;
        case 1: _t->calClicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CalculatorDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CalculatorDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CalculatorDialog,
      qt_meta_data_CalculatorDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CalculatorDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CalculatorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CalculatorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CalculatorDialog))
        return static_cast<void*>(const_cast< CalculatorDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CalculatorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
