#include "replacedialog.h"
#include "ui_replacedialog.h"
#include <QMessageBox>
#include <QTextCursor>
#include <QDebug>

ReplaceDialog::ReplaceDialog(QWidget *parent, QTextEdit * mText) :
    QDialog(parent),
    ui(new Ui::ReplaceDialog)
{
    text = mText;
    count = 0;
    cursor = 0;

    ui->setupUi(this);
    setWindowTitle("替换");
    if (ui->find_content->text().isEmpty()){
        ui->find_next->setEnabled(false);
        ui->replace_one->setEnabled(false);
        ui->repalce_all->setEnabled(false);
    }

    this->setWindowIcon(QIcon(":/images/notepadicon.png"));
    connect(ui->cancel, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(ui->find_next, SIGNAL(clicked()), this, SLOT(findNext()));
    connect(ui->replace_one, SIGNAL(clicked()), this, SLOT(replaceOne()));
    connect(ui->repalce_all, SIGNAL(clicked()), this, SLOT(replaceAll()));
}

ReplaceDialog::~ReplaceDialog()
{
    delete ui;
}

void ReplaceDialog::cancel()
{
    this->close();
}

void ReplaceDialog::findNext()
{

    QString findText = ui->find_content->text();
    Qt::CaseSensitivity cs = ui->case_2->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;
    QString str = text->toPlainText();

    qDebug()<< findText << endl;
    //qDebug() << str << endl;
    int pos = -1;

    if (text != nullptr){
        pos = str.indexOf(findText, cursor, cs);
    }

    //qDebug() <<pos << endl;
    if (pos != -1){
        qDebug() << cursor << endl;
        QTextCursor cur = text->textCursor();
        count++;

        qDebug() << "pos: " << pos << endl;
        cur.setPosition(pos);
        cur.setPosition(pos+findText.length(), QTextCursor::KeepAnchor);
        cursor = pos+findText.length();

        text->setTextCursor(cur);
    }
    if (ui->cycle->isChecked()){
        if (count > 0 && pos == -1){
            cursor = 0;
            count = 0;
        }else if(pos == -1){
            QMessageBox::information(this, "记事本", QString("未找到%1").arg(findText), QMessageBox::Ok);
        }
    }else{
        if (pos == -1){
            QMessageBox::information(this, "记事本", "已经到达文件末尾", QMessageBox::Ok);
        }
    }

}

void ReplaceDialog::replaceOne()
{
    QString str = ui->repalce_content->text();
    if (text->textCursor().selectedText().isEmpty()){
        findNext();
        if (text->textCursor().selectedText().isEmpty()){
            QMessageBox::information(this, "记事本", QString("未找到%1").arg(ui->find_content->text()), QMessageBox::Ok);
            return ;
        }
    }

    text->textCursor().removeSelectedText();
    text->textCursor().insertHtml(str);
}

void ReplaceDialog::replaceAll()
{
    QString replaceText = ui->repalce_content->text();
    QString str = text->toPlainText();
    QString findText = ui->find_content->text();

    findNext();
    while(!(text->textCursor().selectedText().isEmpty())){
        text->textCursor().removeSelectedText();
        text->textCursor().insertHtml(replaceText);
        findNext();
    }
}

void ReplaceDialog::on_find_content_textChanged(const QString &arg1)
{
    if (ui->find_content->text().isEmpty()){
        ui->find_next->setEnabled(false);
        ui->replace_one->setEnabled(false);
        ui->repalce_all->setEnabled(false);
    }else{
        ui->find_next->setEnabled(true);
        ui->replace_one->setEnabled(true);
        ui->repalce_all->setEnabled(true);
    }
}
