#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include <QTextEdit>

namespace Ui {
class FindDialog;
}

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindDialog(QWidget *parent = nullptr, QTextEdit * mText = nullptr);
    ~FindDialog();
private slots:
    void cancel();    //取消
    void findNext(); //查找


private:
    Ui::FindDialog *ui;
    bool findDirection; //false向上,true向上
    bool isCase; //大小写，false小写，true大写
    bool isCycle; //是否循环，true循环
    QTextEdit * text;
    int cursor;
    int count;
    int flag;
};

#endif // FINDDIALOG_H
