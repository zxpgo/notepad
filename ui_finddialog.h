/********************************************************************************
** Form generated from reading UI file 'finddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_FindDialog
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *find_next;
    QPushButton *cancel;
    QGroupBox *groupBox;
    QRadioButton *up;
    QRadioButton *down;
    QCheckBox *case_2;
    QCheckBox *cycle;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *FindDialog)
    {
        if (FindDialog->objectName().isEmpty())
            FindDialog->setObjectName(QStringLiteral("FindDialog"));
        FindDialog->resize(500, 180);
        FindDialog->setMinimumSize(QSize(500, 180));
        FindDialog->setMaximumSize(QSize(500, 180));
        label = new QLabel(FindDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 40, 54, 12));
        lineEdit = new QLineEdit(FindDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 30, 281, 31));
        find_next = new QPushButton(FindDialog);
        find_next->setObjectName(QStringLiteral("find_next"));
        find_next->setGeometry(QRect(410, 20, 81, 41));
        cancel = new QPushButton(FindDialog);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(410, 80, 81, 41));
        groupBox = new QGroupBox(FindDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(200, 80, 191, 61));
        up = new QRadioButton(groupBox);
        buttonGroup = new QButtonGroup(FindDialog);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(up);
        up->setObjectName(QStringLiteral("up"));
        up->setGeometry(QRect(20, 20, 89, 16));
        down = new QRadioButton(groupBox);
        buttonGroup->addButton(down);
        down->setObjectName(QStringLiteral("down"));
        down->setGeometry(QRect(100, 20, 89, 16));
        down->setChecked(true);
        case_2 = new QCheckBox(FindDialog);
        case_2->setObjectName(QStringLiteral("case_2"));
        case_2->setGeometry(QRect(30, 80, 100, 23));
        case_2->setMaximumSize(QSize(100, 16777215));
        cycle = new QCheckBox(FindDialog);
        cycle->setObjectName(QStringLiteral("cycle"));
        cycle->setGeometry(QRect(30, 110, 71, 16));

        retranslateUi(FindDialog);

        QMetaObject::connectSlotsByName(FindDialog);
    } // setupUi

    void retranslateUi(QDialog *FindDialog)
    {
        FindDialog->setWindowTitle(QApplication::translate("FindDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("FindDialog", "\346\237\245\346\211\276\345\206\205\345\256\271", Q_NULLPTR));
        find_next->setText(QApplication::translate("FindDialog", "\346\237\245\346\211\276\344\270\213\344\270\200\344\270\252", Q_NULLPTR));
        cancel->setText(QApplication::translate("FindDialog", "\345\217\226\346\266\210", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("FindDialog", "\346\226\271\345\220\221", Q_NULLPTR));
        up->setText(QApplication::translate("FindDialog", "\345\220\221\344\270\212", Q_NULLPTR));
        down->setText(QApplication::translate("FindDialog", "\345\220\221\344\270\213", Q_NULLPTR));
        case_2->setText(QApplication::translate("FindDialog", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231", Q_NULLPTR));
        cycle->setText(QApplication::translate("FindDialog", "\345\276\252\347\216\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FindDialog: public Ui_FindDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H
