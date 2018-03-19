/****************************************************************************
** Meta object code from reading C++ file 'Sudoku.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Sudoku_lib/Sudoku.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Sudoku.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Sudoku_t {
    QByteArrayData data[7];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Sudoku_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Sudoku_t qt_meta_stringdata_Sudoku = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Sudoku"
QT_MOC_LITERAL(1, 7, 14), // "puzzleSelected"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "std::string"
QT_MOC_LITERAL(4, 35, 10), // "puzzlePath"
QT_MOC_LITERAL(5, 46, 10), // "selectGame"
QT_MOC_LITERAL(6, 57, 9) // "closeGame"

    },
    "Sudoku\0puzzleSelected\0\0std::string\0"
    "puzzlePath\0selectGame\0closeGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Sudoku[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   32,    2, 0x09 /* Protected */,
       6,    0,   33,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Sudoku::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Sudoku *_t = static_cast<Sudoku *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->puzzleSelected((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->selectGame(); break;
        case 2: _t->closeGame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Sudoku::*_t)(std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Sudoku::puzzleSelected)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Sudoku::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Sudoku.data,
      qt_meta_data_Sudoku,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Sudoku::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Sudoku::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Sudoku.stringdata0))
        return static_cast<void*>(const_cast< Sudoku*>(this));
    return QWidget::qt_metacast(_clname);
}

int Sudoku::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Sudoku::puzzleSelected(std::string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
