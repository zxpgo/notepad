#include "finddialog.h"
#include "ui_finddialog.h"
#include <QMessageBox>
#include <QTextCursor>
#include <QDebug>

FindDialog::FindDialog(QWidget *parent, QTextEdit * mText) :
    QDialog(parent),
    ui(new Ui::FindDialog)
{
    text = mText;
    count = 0;
    flag = false; //false表示当前是向下
    cursor = text->textCursor().position();

    ui->setupUi(this);
    setWindowTitle("查找");
    this->setWindowIcon(QIcon(":/images/notepadicon.png"));
    connect(ui->cancel, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(ui->find_next, SIGNAL(clicked()), this, SLOT(findNext()));
}

FindDialog::~FindDialog()
{
    delete ui;
}

void FindDialog::cancel()
{
    this->close();
}

void FindDialog::findNext()
{
    QString findText = ui->lineEdit->text();
    Qt::CaseSensitivity cs = ui->case_2->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;
    QString str = text->toPlainText();

    //qDebug()<< findText << endl;
    //qDebug() << str << endl;
    int pos = -1;
    if (text != nullptr){
        if (ui->down->isChecked()){
            pos = str.indexOf(findText, cursor, cs);
        }
        else if (ui->up->isChecked()){
            if (count == 0)
                cursor = -1;
            pos = str.lastIndexOf(findText, cursor, cs);
        }
    }

    //qDebug() <<pos << endl;
    if (pos != -1){
        qDebug() << cursor << endl;
        QTextCursor cur = text->textCursor();
        count++;
        if (ui->down->isChecked()){
            if (flag == true){
                count = 1;
                flag = false;
            }
            qDebug() << "pos: " << pos << endl;
            cur.setPosition(pos);
            cur.setPosition(pos+findText.length(), QTextCursor::KeepAnchor);
            cursor = pos+findText.length();

        }else{
            if (flag == false){
                count = 1;
                flag = true;
            }
            qDebug() << "pos: " << pos << endl;
            cur.setPosition(pos+findText.length());
            cur.setPosition(pos, QTextCursor::KeepAnchor);
            cursor = pos-findText.length();
        }
        text->setTextCursor(cur);

    }
    if (count > 0 && pos == -1){
        QMessageBox::information(this, "记事本", QString("一共找到%1个，目前是最后一个").arg(count), QMessageBox::Ok);
    }else if (count == 0)
    {
        QMessageBox::information(this, "记事本", QString("未找到%1").arg(findText), QMessageBox::Ok);
    }
    if (ui->cycle->isChecked()){
        qDebug() << "hello" << endl;
        if (ui->down->isChecked()){
            if (count > 0 && pos == -1){
                cursor = 0;
                count = 0;
            }
        }else if(ui->up->isChecked()){
            if (count > 0 && pos == -1){
                cursor = -1;
                count = 0;
            }
        }
    }

}
