/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *open_file;
    QAction *save_file;
    QAction *new_file;
    QAction *copy_text;
    QAction *paste_text;
    QAction *save_as_file;
    QAction *file_exit;
    QAction *revoke_text;
    QAction *find_help;
    QAction *about_window;
    QAction *new_line;
    QAction *font_win;
    QAction *enlarge;
    QAction *narrow;
    QAction *print_dialog;
    QAction *time;
    QAction *find_content;
    QAction *replace_content;
    QAction *select_all;
    QAction *delete_2;
    QAction *cut_content;
    QAction *page_setup;
    QAction *status;
    QAction *bing_search;
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QMenu *menu_6;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        open_file = new QAction(MainWindow);
        open_file->setObjectName(QStringLiteral("open_file"));
        save_file = new QAction(MainWindow);
        save_file->setObjectName(QStringLiteral("save_file"));
        new_file = new QAction(MainWindow);
        new_file->setObjectName(QStringLiteral("new_file"));
        copy_text = new QAction(MainWindow);
        copy_text->setObjectName(QStringLiteral("copy_text"));
        paste_text = new QAction(MainWindow);
        paste_text->setObjectName(QStringLiteral("paste_text"));
        save_as_file = new QAction(MainWindow);
        save_as_file->setObjectName(QStringLiteral("save_as_file"));
        file_exit = new QAction(MainWindow);
        file_exit->setObjectName(QStringLiteral("file_exit"));
        revoke_text = new QAction(MainWindow);
        revoke_text->setObjectName(QStringLiteral("revoke_text"));
        find_help = new QAction(MainWindow);
        find_help->setObjectName(QStringLiteral("find_help"));
        about_window = new QAction(MainWindow);
        about_window->setObjectName(QStringLiteral("about_window"));
        new_line = new QAction(MainWindow);
        new_line->setObjectName(QStringLiteral("new_line"));
        new_line->setCheckable(true);
        new_line->setChecked(true);
        font_win = new QAction(MainWindow);
        font_win->setObjectName(QStringLiteral("font_win"));
        enlarge = new QAction(MainWindow);
        enlarge->setObjectName(QStringLiteral("enlarge"));
        narrow = new QAction(MainWindow);
        narrow->setObjectName(QStringLiteral("narrow"));
        print_dialog = new QAction(MainWindow);
        print_dialog->setObjectName(QStringLiteral("print_dialog"));
        time = new QAction(MainWindow);
        time->setObjectName(QStringLiteral("time"));
        find_content = new QAction(MainWindow);
        find_content->setObjectName(QStringLiteral("find_content"));
        replace_content = new QAction(MainWindow);
        replace_content->setObjectName(QStringLiteral("replace_content"));
        select_all = new QAction(MainWindow);
        select_all->setObjectName(QStringLiteral("select_all"));
        delete_2 = new QAction(MainWindow);
        delete_2->setObjectName(QStringLiteral("delete_2"));
        cut_content = new QAction(MainWindow);
        cut_content->setObjectName(QStringLiteral("cut_content"));
        page_setup = new QAction(MainWindow);
        page_setup->setObjectName(QStringLiteral("page_setup"));
        status = new QAction(MainWindow);
        status->setObjectName(QStringLiteral("status"));
        status->setCheckable(true);
        status->setChecked(false);
        bing_search = new QAction(MainWindow);
        bing_search->setObjectName(QStringLiteral("bing_search"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(0, 0, 801, 571));
        QFont font;
        font.setFamily(QStringLiteral("SimSun-ExtB"));
        font.setPointSize(12);
        textEdit->setFont(font);
        textEdit->setFrameShape(QFrame::NoFrame);
        textEdit->setLineWrapMode(QTextEdit::WidgetWidth);
        textEdit->setOverwriteMode(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        menu_5 = new QMenu(menubar);
        menu_5->setObjectName(QStringLiteral("menu_5"));
        menu_6 = new QMenu(menu_5);
        menu_6->setObjectName(QStringLiteral("menu_6"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_4->menuAction());
        menubar->addAction(menu_5->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(open_file);
        menu->addAction(save_file);
        menu->addAction(new_file);
        menu->addAction(save_as_file);
        menu->addSeparator();
        menu->addAction(page_setup);
        menu->addAction(print_dialog);
        menu->addSeparator();
        menu->addAction(file_exit);
        menu_2->addAction(revoke_text);
        menu_2->addSeparator();
        menu_2->addAction(cut_content);
        menu_2->addAction(copy_text);
        menu_2->addAction(paste_text);
        menu_2->addAction(delete_2);
        menu_2->addSeparator();
        menu_2->addAction(bing_search);
        menu_2->addAction(find_content);
        menu_2->addAction(replace_content);
        menu_2->addSeparator();
        menu_2->addAction(time);
        menu_2->addAction(select_all);
        menu_3->addAction(find_help);
        menu_3->addAction(about_window);
        menu_4->addAction(new_line);
        menu_4->addAction(font_win);
        menu_5->addAction(menu_6->menuAction());
        menu_5->addAction(status);
        menu_6->addAction(enlarge);
        menu_6->addAction(narrow);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        open_file->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", Q_NULLPTR));
        save_file->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", Q_NULLPTR));
        new_file->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272", Q_NULLPTR));
        copy_text->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266", Q_NULLPTR));
        paste_text->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264", Q_NULLPTR));
        save_as_file->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", Q_NULLPTR));
        file_exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        revoke_text->setText(QApplication::translate("MainWindow", "\346\222\244\346\266\210", Q_NULLPTR));
        find_help->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\345\270\256\345\212\251", Q_NULLPTR));
        about_window->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
        new_line->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\346\215\242\350\241\214", Q_NULLPTR));
        font_win->setText(QApplication::translate("MainWindow", "\345\255\227\344\275\223...", Q_NULLPTR));
        enlarge->setText(QApplication::translate("MainWindow", "\346\224\276\345\244\247", Q_NULLPTR));
        narrow->setText(QApplication::translate("MainWindow", "\347\274\251\345\260\217", Q_NULLPTR));
        print_dialog->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260", Q_NULLPTR));
        time->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264/\346\227\245\346\234\237", Q_NULLPTR));
        find_content->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276", Q_NULLPTR));
        replace_content->setText(QApplication::translate("MainWindow", "\346\233\277\346\215\242", Q_NULLPTR));
        select_all->setText(QApplication::translate("MainWindow", "\345\205\250\351\200\211", Q_NULLPTR));
        delete_2->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", Q_NULLPTR));
        cut_content->setText(QApplication::translate("MainWindow", "\345\211\252\345\210\207", Q_NULLPTR));
        page_setup->setText(QApplication::translate("MainWindow", "\351\241\265\351\235\242\350\256\276\347\275\256", Q_NULLPTR));
        status->setText(QApplication::translate("MainWindow", "\347\212\266\346\200\201\346\240\217", Q_NULLPTR));
        bing_search->setText(QApplication::translate("MainWindow", "\344\275\277\347\224\250 Bing \346\220\234\347\264\242...", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", Q_NULLPTR));
        menu_4->setTitle(QApplication::translate("MainWindow", "\346\240\274\345\274\217", Q_NULLPTR));
        menu_5->setTitle(QApplication::translate("MainWindow", "\346\237\245\347\234\213", Q_NULLPTR));
        menu_6->setTitle(QApplication::translate("MainWindow", "\347\274\251\346\224\276", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
