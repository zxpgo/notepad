/********************************************************************************
** Form generated from reading UI file 'replacedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLACEDIALOG_H
#define UI_REPLACEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ReplaceDialog
{
public:
    QPushButton *find_next;
    QLabel *label;
    QCheckBox *case_2;
    QLineEdit *find_content;
    QCheckBox *cycle;
    QLineEdit *repalce_content;
    QLabel *label_2;
    QPushButton *replace_one;
    QPushButton *repalce_all;
    QPushButton *cancel;

    void setupUi(QDialog *ReplaceDialog)
    {
        if (ReplaceDialog->objectName().isEmpty())
            ReplaceDialog->setObjectName(QStringLiteral("ReplaceDialog"));
        ReplaceDialog->resize(520, 230);
        ReplaceDialog->setMinimumSize(QSize(520, 230));
        ReplaceDialog->setMaximumSize(QSize(520, 230));
        find_next = new QPushButton(ReplaceDialog);
        find_next->setObjectName(QStringLiteral("find_next"));
        find_next->setGeometry(QRect(390, 20, 101, 31));
        label = new QLabel(ReplaceDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 54, 12));
        case_2 = new QCheckBox(ReplaceDialog);
        case_2->setObjectName(QStringLiteral("case_2"));
        case_2->setGeometry(QRect(10, 130, 80, 23));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(case_2->sizePolicy().hasHeightForWidth());
        case_2->setSizePolicy(sizePolicy);
        case_2->setMinimumSize(QSize(0, 0));
        case_2->setMaximumSize(QSize(80, 16777215));
        find_content = new QLineEdit(ReplaceDialog);
        find_content->setObjectName(QStringLiteral("find_content"));
        find_content->setGeometry(QRect(70, 30, 281, 31));
        cycle = new QCheckBox(ReplaceDialog);
        cycle->setObjectName(QStringLiteral("cycle"));
        cycle->setGeometry(QRect(10, 170, 71, 16));
        repalce_content = new QLineEdit(ReplaceDialog);
        repalce_content->setObjectName(QStringLiteral("repalce_content"));
        repalce_content->setGeometry(QRect(70, 80, 281, 31));
        label_2 = new QLabel(ReplaceDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 90, 54, 12));
        replace_one = new QPushButton(ReplaceDialog);
        replace_one->setObjectName(QStringLiteral("replace_one"));
        replace_one->setGeometry(QRect(390, 60, 101, 31));
        repalce_all = new QPushButton(ReplaceDialog);
        repalce_all->setObjectName(QStringLiteral("repalce_all"));
        repalce_all->setGeometry(QRect(390, 100, 101, 31));
        cancel = new QPushButton(ReplaceDialog);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(390, 140, 101, 31));

        retranslateUi(ReplaceDialog);

        QMetaObject::connectSlotsByName(ReplaceDialog);
    } // setupUi

    void retranslateUi(QDialog *ReplaceDialog)
    {
        ReplaceDialog->setWindowTitle(QApplication::translate("ReplaceDialog", "Dialog", Q_NULLPTR));
        find_next->setText(QApplication::translate("ReplaceDialog", "\346\237\245\346\211\276\344\270\213\344\270\200\344\270\252", Q_NULLPTR));
        label->setText(QApplication::translate("ReplaceDialog", "\346\237\245\346\211\276\345\206\205\345\256\271", Q_NULLPTR));
        case_2->setText(QApplication::translate("ReplaceDialog", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231", Q_NULLPTR));
        cycle->setText(QApplication::translate("ReplaceDialog", "\345\276\252\347\216\257", Q_NULLPTR));
        repalce_content->setText(QString());
        label_2->setText(QApplication::translate("ReplaceDialog", "\346\233\277\346\215\242\345\206\205\345\256\271", Q_NULLPTR));
        replace_one->setText(QApplication::translate("ReplaceDialog", "\346\233\277\346\215\242", Q_NULLPTR));
        repalce_all->setText(QApplication::translate("ReplaceDialog", "\345\205\250\351\203\250\346\233\277\346\215\242", Q_NULLPTR));
        cancel->setText(QApplication::translate("ReplaceDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReplaceDialog: public Ui_ReplaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLACEDIALOG_H
