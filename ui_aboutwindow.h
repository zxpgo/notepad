/********************************************************************************
** Form generated from reading UI file 'aboutwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWINDOW_H
#define UI_ABOUTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_aboutWindow
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *aboutWindow)
    {
        if (aboutWindow->objectName().isEmpty())
            aboutWindow->setObjectName(QStringLiteral("aboutWindow"));
        aboutWindow->resize(520, 530);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(aboutWindow->sizePolicy().hasHeightForWidth());
        aboutWindow->setSizePolicy(sizePolicy);
        aboutWindow->setMinimumSize(QSize(520, 530));
        aboutWindow->setMaximumSize(QSize(520, 530));
        aboutWindow->setAutoFillBackground(false);
        pushButton = new QPushButton(aboutWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(290, 470, 75, 23));

        retranslateUi(aboutWindow);

        QMetaObject::connectSlotsByName(aboutWindow);
    } // setupUi

    void retranslateUi(QWidget *aboutWindow)
    {
        aboutWindow->setWindowTitle(QApplication::translate("aboutWindow", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("aboutWindow", "\347\241\256\350\256\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class aboutWindow: public Ui_aboutWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWINDOW_H
