#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QTextCodec>
#include <QDesktopServices>
#include <string>
#include <QFontDialog>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrinterInfo>
#include <QPageSetupDialog>
#include <QDateTime>
#include <QAction>
#include <QShortcut>
#include <QLabel>
#include <QTextLayout>
#include "finddialog.h"
#include "replacedialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    newLine = true;
    oneClose = true;
    this->setWindowIcon(QIcon(":/images/notepadicon.png"));
    title = "无标题  - 记事本";
    setWinTitle(title);
    setCentralWidget(ui->textEdit);

    ui->textEdit->setFont(QFont("微软雅黑",12, QFont::Normal));

    percent = 100;
    ui->statusbar->setHidden(true);
    QString info = QString("         第%1行, 第%2列          ").arg(0).arg(0);
    QLabel * win = new QLabel("Windows (CRLF)");
    ui->statusbar->addPermanentWidget(win);
    statusLabelRowColumn = new QLabel(info, this);
    ui->statusbar->addPermanentWidget(statusLabelRowColumn); //现实永久信息
    statusLabelPercent = new QLabel(QString("100%"));
    ui->statusbar->addPermanentWidget(statusLabelPercent); //现实永久信息

    ui->copy_text->setEnabled(false);
    ui->cut_content->setEnabled(false);
    //设置是否可以粘贴
    if (!(ui->textEdit->canPaste()))
        ui->paste_text->setEnabled(false);
    else
        ui->paste_text->setEnabled(true);

    if (ui->textEdit->toPlainText().isEmpty()){
        ui->find_content->setEnabled(false);
        ui->replace_content->setEnabled(false);
    }

    connect(ui->save_file, SIGNAL(triggered()), this, SLOT(saveFile()));  //保存文件
    connect(ui->open_file, SIGNAL(triggered()), this, SLOT(openFile()));  //打开文件
    connect(ui->new_file, SIGNAL(triggered()), this, SLOT(newFile()));   //创建新文件
    connect(ui->save_as_file, SIGNAL(triggered()), this, SLOT(saveToNewFile()));
    connect(ui->find_help, SIGNAL(triggered()), this, SLOT(findHelp())); //帮助
    connect(ui->font_win, SIGNAL(triggered()), this, SLOT(fontWin())); //设置字体
    connect(ui->new_line, SIGNAL(triggered()), this, SLOT(setNewLine()));  //自动换行
    connect(ui->enlarge, SIGNAL(triggered()), this, SLOT(setFontLarger())); //放大字体
    connect(ui->narrow, SIGNAL(triggered()), this, SLOT(setFontSmaller()));  //缩小字体
    connect(ui->about_window, SIGNAL(triggered()), this, SLOT(newAboutWin())); //关于页面
    connect(ui->print_dialog, SIGNAL(triggered()), this, SLOT(printDialog()));  //打印页面
    connect(ui->file_exit, SIGNAL(triggered()),this, SLOT(exitHelp()));    //退出
    connect(ui->time, SIGNAL(triggered()),this, SLOT(appendTime()));    //时间和日期
    connect(ui->copy_text, SIGNAL(triggered()),this, SLOT(copyText()));    //拷贝
    connect(ui->paste_text, SIGNAL(triggered()),this, SLOT(pasteText()));    //粘贴
    connect(ui->revoke_text, SIGNAL(triggered()),this, SLOT(undoText()));    //撤销
    connect(ui->select_all, SIGNAL(triggered()),this, SLOT(selectAll()));    //全选
    connect(ui->delete_2, SIGNAL(triggered()),this, SLOT(deleteText()));    //全选
    connect(ui->cut_content, SIGNAL(triggered()),this, SLOT(cutText()));     //剪切
    connect(ui->find_content, SIGNAL(triggered()),this, SLOT(findDialog()));    //查找
    connect(ui->replace_content, SIGNAL(triggered()),this, SLOT(replaceDialog()));    //替换
    connect(ui->page_setup, SIGNAL(triggered()),this, SLOT(pageSetup()));    //页面设置
    connect(ui->status, SIGNAL(triggered()), this, SLOT(setStatus()));        //状态栏设置
    connect(ui->bing_search, SIGNAL(triggered()), this, SLOT(bingSearch()));   //bing搜索
    //QAction * action = new QAction(QObject::tr("New"),parent);
    //action->setShortcut(QKeySequence(tr("Alt+V")));
   // ui->find_help->setShortcut(QKeySequence(tr("Ctrl+H")));
    //ui->menu_5->activeAction()->setShortcut(QKeySequence(tr("Alt+V")));
            //grabShortcut(QKeySequence(tr("Ctrl+P")));
    //别忘了头文件<QShortcut>
    //QShortcut *temp = new QShortcut(this);
    //设置键值，也就是设置快捷键.
   // temp->setKey(tr("ctrl+h"));
    //这个成员函数挺关键的，设置是否会自动反复按键.也就是说，当你一直按住键盘ctrl+r时，会一直不停的调用对应的槽函数.
    //temp->setAutoRepeat(false);

    //连接信号与槽，showSlot()是自定义的槽函数!
   // connect(temp, SIGNAL(activated()), this, SLOT(findHelp()));
    //设置快捷键
    ui->new_file->setShortcut(QKeySequence("Ctrl+N"));
    ui->open_file->setShortcut(QKeySequence("Ctrl+O"));
    ui->save_file->setShortcut(QKeySequence("Ctrl+S"));
    ui->print_dialog->setShortcut(QKeySequence("Ctrl+P"));
    ui->revoke_text->setShortcut(QKeySequence("Ctrl+Z"));
    ui->cut_content->setShortcut(QKeySequence("Ctrl+X"));
    ui->copy_text->setShortcut(QKeySequence("Ctrl+C"));
    ui->paste_text->setShortcut(QKeySequence("Ctrl+V"));
    ui->find_content->setShortcut(QKeySequence("Ctrl+F"));
    ui->replace_content->setShortcut(QKeySequence("Ctrl+H"));
    ui->select_all->setShortcut(QKeySequence("Ctrl+A"));
    ui->bing_search->setShortcut(QKeySequence("Ctrl+E"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    QString openFileName  = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      QDir::currentPath(),
                                                      tr("Images (*.png *.xpm *.jpg *.*)"));
    fileName = openFileName;
    if(fileName.isEmpty())
        return;
    qDebug() << fileName << endl;

    //设置窗口名称
    getFileName(fileName);
    setWinTitle(title);

    //打开文件并读取内容
    QFile file;
    file.setFileName(fileName);//设置文件名称
    file.open(QIODevice::ReadWrite);
    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());
    ui->textEdit->document()->setModified(false);
    file.close();
}

bool MainWindow::saveFile()
{
    qDebug() << "saveFile()" << endl;
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    if (fileName.isEmpty()){
        //另存为新文件
        return saveToNewFile();
    }
    else{
        //保存到当前文件
        QFile file;
        file.setFileName(fileName);
        file.open(QIODevice::WriteOnly);
        QString text = ui->textEdit->toPlainText();
        QByteArray byte = text.toUtf8();
        file.write(byte);
        file.close();
    }
    return false;
}

void MainWindow::newFile()
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QString text = ui->textEdit->toPlainText();
    qDebug() << "文件比较" << compareText() << endl;
    if (compareText()){ //输入框中内容发生了变化
        if (!(fileName.isEmpty())){  //文件是打开的文件
            saveFile();
        }else{
            QMessageBox msgBox;
            //msgBox.setText("记事本");
            msgBox.setWindowTitle("记事本");
            oneClose = false;
            msgBox.setInformativeText(QString("是否将更改保存？"));
            msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Save);
            int ret = msgBox.exec();
            switch (ret) {
                case QMessageBox::Save:
                    saveFile();
                    break;
                case QMessageBox::Discard:
                    break;
                case QMessageBox::Cancel:
                    // Cancel was clicked
                    break;
                default:
                    // should never be reached
                    break;
              }
        }
    }
    ui->textEdit->clear();
    title = "新建文本文档.txt  - 记事本";
    setWinTitle(title);
}

bool MainWindow::saveToNewFile()
{
    qDebug() << "saveToNewFile()" << endl;
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QString openFileName = QFileDialog::getSaveFileName(this, "保存", QDir::currentPath(), ".txt");
    fileName = openFileName;

    if (fileName.isEmpty()){
        QMessageBox::warning(this, "警告", "保存失败");
        return false;
    }

    QFile file;
    QString tempName = fileName;
    if (fileName.indexOf(".txt",0) == -1)
           tempName += ".txt";
    file.setFileName(tempName);
    getFileName(tempName);
    setWinTitle(title);
    file.open(QIODevice::WriteOnly);
    QString text = ui->textEdit->toPlainText();
    QByteArray byte = text.toUtf8();
    file.write(byte);
    file.close();
    return false;
}

void MainWindow::findHelp()
{
    QDesktopServices::openUrl(QUrl("https://cn.bing.com/search?q=%E8%8E%B7%E5%8F%96%E6%9C%89%E5%85%B3+windows+10+%E4%B8%AD%E7%9A%84%E8%AE%B0%E4%BA%8B%E6%9C%AC%E7%9A%84%E5%B8%AE%E5%8A%A9&filters=guid:%224466414-zh-hans-dia%22%20lang:%22zh-hans%22&form=T00032&ocid=HelpPane-BingIA"));
}

void MainWindow::newAboutWin()
{
    QMessageBox::about(this, "关于记事本", "测试版本0.1");
}

void MainWindow::fontWin()
{
    bool ok;
    QFont curfont = ui->textEdit->font();
    QFont font = QFontDialog::getFont(&ok, curfont);
    ui->textEdit->setFont(font);
}

void MainWindow::setNewLine()
{
    newLine = !newLine;
    if (newLine == false){
        ui->textEdit->setLineWrapMode(QTextEdit::NoWrap);
    }else{
        ui->textEdit->setLineWrapMode(QTextEdit::WidgetWidth);
    }
}

void MainWindow::setFontLarger()
{
    QFont font = ui->textEdit->font();
    if (font.pointSize() == 72)
        return ;
    else if (font.pointSize() == 71)
        font.setPointSize(font.pointSize()+1);
    else
        font.setPointSize(font.pointSize()+2);
    ui->textEdit->setFont(font);
    percent += 10;
    statusLabelPercent->setText(QString("%1\%").arg(percent));
}

void MainWindow::setFontSmaller()
{
    QFont font = ui->textEdit->font();
    if (font.pointSize() <= 6)
        return ;
    else if (font.pointSize() == 7)
       font.setPointSize(font.pointSize() - 1);
    else
        font.setPointSize(font.pointSize() - 2);
    ui->textEdit->setFont(font);
    if (percent > 10){
        percent -= 10;
        statusLabelPercent->setText(QString("%1\%").arg(percent));
    }
}

void MainWindow::printDialog()
{
    QPrinter * print =new QPrinter();
    QPrintDialog printDialog(print, this);

    if (printDialog.exec() == QDialog::Accepted) {
        QTextDocument doc;
        doc.setHtml(ui->textEdit->toPlainText());
        doc.print(print);
    }
}

void MainWindow::exitHelp()
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QString text = ui->textEdit->toPlainText();
    bool flag = false;
   // qDebug() << "文件比较" << compareText() << endl;
    if (compareText()){ //输入框中内容发生了变化
        if (!(fileName.isEmpty())){  //文件是打开的文件
            flag = saveFile();
            qDebug() << "flag11 = " << flag << fileName << endl;
        }else{
            QMessageBox msgBox;
            msgBox.setText("文件内容被修改");
            msgBox.setWindowTitle("记事本");
            msgBox.setInformativeText("是否将更改保存？");
            msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Save);
            int ret = msgBox.exec();
            qDebug() << "ret:" << ret << endl;
            oneClose = false;
            switch (ret) {
                case QMessageBox::Save:
                    flag = saveFile();
                    break;
                case QMessageBox::Discard:
                    flag = true;
                    break;
                case QMessageBox::Cancel:
                    // Cancel was clicked
                    break;
                default:
                    // should never be reached
                    break;
              }
        }
    }else{
        flag = true;
    }
    qDebug() << flag << endl;
    if (flag)
        this->close();
}

void MainWindow::appendTime()
{
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("hh:mm yyyy/MM/dd");
    ui->textEdit->append(current_date);
}

void MainWindow::copyText()
{
    ui->textEdit->copy();
    ui->paste_text->setEnabled(true);
}

void MainWindow::pasteText()
{
    ui->textEdit->paste();
}

void MainWindow::undoText()
{
    ui->textEdit->undo();
}

void MainWindow::selectAll()
{
    ui->textEdit->selectAll();
}

void MainWindow::deleteText()
{
    ui->textEdit->textCursor().removeSelectedText();
}

void MainWindow::cutText()
{
    ui->textEdit->cut();
}

void MainWindow::pageSetup()
{
    QPrinter * print =new QPrinter();
    QPageSetupDialog pageSetup(print, this);

    if (pageSetup.exec() == QDialog::Accepted) {
        print->setOrientation(QPrinter::Landscape);
    }
}

void MainWindow::setStatus()
{
    if (!(ui->statusbar->isHidden()))
        ui->statusbar->setHidden(true);
    else
        ui->statusbar->setHidden(false);
}

void MainWindow::bingSearch()
{
    QString searchText;
    if (ui->textEdit->textCursor().isNull())
        searchText = QString("https://cn.bing.com/?scope=web");
    else{
        QString str = ui->textEdit->textCursor().selectedText();
        searchText = QString("https://cn.bing.com/search?q=%1&form=NPCTXT").arg(str);
    }
    qDebug() << searchText << endl;
    QDesktopServices::openUrl(searchText);
}

void MainWindow::findDialog()
{
    qDebug() << "findDialog()" << endl;
    QDialog * find = new FindDialog(nullptr, ui->textEdit);
    find->setWindowFlags(Qt::WindowStaysOnTopHint);
    find->show();
}

void MainWindow::replaceDialog()
{
    qDebug() << "rePlaceDialog()" << endl;
    QDialog * replace = new ReplaceDialog(nullptr, ui->textEdit);
    replace->setWindowFlags(Qt::WindowStaysOnTopHint);
    replace->show();
}


bool MainWindow::compareText()  //内容变化返回true
{
    return ui->textEdit->document()->isModified();
}

void MainWindow::getFileName(QString path)
{
    QString str = path.section('/',-1);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QByteArray ba = str.toLocal8Bit();
    title = ba.data();
}

void MainWindow::setWinTitle(const char *title)
{
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    setWindowTitle(codec->toUnicode(title));
}

void MainWindow::on_textEdit_textChanged()
{
    if (ui->textEdit->toPlainText().isEmpty()){
        ui->find_content->setEnabled(false);
        ui->replace_content->setEnabled(false);
        ui->cut_content->setEnabled(false);
    }else{
        ui->find_content->setEnabled(true);
        ui->replace_content->setEnabled(true);

    }
}

void MainWindow::on_textEdit_copyAvailable(bool b)
{
    ui->copy_text->setEnabled(true);
    ui->cut_content->setEnabled(true);
}
/*
void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->modifiers() == Qt::AltModifier){
        // 是否按下M键
        qDebug() << "Qt::AltModifier" << endl;
        if(event->key() == Qt::Key_M){
            // 窗口最大化
            qDebug() << "Qt::key_M" << endl;
            setWindowState(Qt::WindowMaximized);
        }
    }
}
// 按键释放事件
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{

}*/

void MainWindow::on_textEdit_cursorPositionChanged()
{
    int x = ui->textEdit->textCursor().columnNumber();
    int y = ui->textEdit->textCursor().blockNumber()+1;
    statusLabelRowColumn->setText(QString("         第%1行, 第%2列          ").arg(y).arg(x));
    //QLabel *label = new QLabel("Windows (CRLF)", this);
    //ui->statusbar->addPermanentWidget(label); //现实永久信息
    //QLabel * label1 = new QLabel(QString("         第%1行, 第%2列          ").arg(y).arg(x));
    //ui->statusbar->addPermanentWidget(label1);
   // QLabel * label2 = new QLabel(QString("%1%").arg(percent));
    //ui->statusbar->addPermanentWidget(label2);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug() << "oneclose" << oneClose << endl;
    if (oneClose)
        exitHelp();
}
