#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openFile();  //打开文件
    bool saveFile(); //保存文件
    void newFile();  //新建文件
    bool saveToNewFile(); //另存为
    void findHelp(); //帮助
    void newAboutWin(); //关于页面
    void fontWin(); //设置字体
    void setNewLine(); //设置自动换行
    void setFontLarger(); //放大字体
    void setFontSmaller(); //缩小字体
    void printDialog(); //打印
    void exitHelp(); //退出
    void appendTime(); //时间
    void copyText(); //复制
    void pasteText();  //拷贝
    void undoText(); //撤销
    void findDialog(); //查找页面
    void replaceDialog(); //替换页面
    void selectAll();
    void deleteText();
    void cutText();
    void pageSetup();
    void setStatus();
    void bingSearch();
    void on_textEdit_textChanged();

    void on_textEdit_copyAvailable(bool b);
  //  void keyPressEvent(QKeyEvent * event);
   // void keyReleaseEvent(QKeyEvent *event);
    void on_textEdit_cursorPositionChanged();
    void closeEvent(QCloseEvent * event);

private:
    void setWinTitle(const char * title);
    bool compareText(); //判断当前输入框中文件是否被修改
    void getFileName(QString path);
    const char * title;
    bool newLine;
    bool oneClose;
    QString fileName;
    Ui::MainWindow *ui;
    int percent;
    QLabel *statusLabelRowColumn;
    QLabel *statusLabelPercent;


};
#endif // MAINWINDOW_H
