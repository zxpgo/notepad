#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H

#include <QDialog>
#include <QTextEdit>
namespace Ui {
class ReplaceDialog;
}

class ReplaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReplaceDialog(QWidget *parent = nullptr, QTextEdit * mText = nullptr);
    ~ReplaceDialog();

private slots:
    void cancel();
    void findNext();
    void replaceOne();
    void replaceAll();
    void on_find_content_textChanged(const QString &arg1);

private:
    Ui::ReplaceDialog *ui;
    QTextEdit * text;
    int cursor;
    int count;
};

#endif // REPLACEDIALOG_H
