#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mymdi.h"
#include <QFileDialog>
#include <QMdiSubWindow>
#include <QDebug>
#include <QSignalMapper>
#include <QSettings>
#include <QCloseEvent>
#include <QLabel>
#include <QMessageBox>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    actionSeparator = new QAction(this);
    actionSeparator->setSeparator(true);

    UpdateMenus();
    //有子窗口被激活，则更新菜单栏
    connect(ui->mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)), this, SLOT(UpdateMenus()));

    window_mapper = new QSignalMapper(this);//创建信号发生器
    connect(window_mapper, SIGNAL(mapped(QWidget*)), this, SLOT(set_active_sub_window(QWidget*)));//通过信号发生器设置活动窗口

    UpdateWindowMenu();//更新窗口子菜单
    connect(ui->menuWindow_W, SIGNAL(aboutToShow()), this, SLOT(UpdateWindowMenu()));//当窗口子菜单将要出现时，就触发更新窗口子菜单

    readSettings();//因为在退出窗口时，执行了write_settings()函数，即保存了退出窗口时的窗口位置，尺寸等信息。因此下次打开该程序时，其位置尺寸
                    //等信息会保留
    initWindow();//初始化窗口
}

MainWindow::~MainWindow()
{
    delete ui;
}

//获取活动窗口
MyMdi *MainWindow::GetActiveWindow()
{
    QMdiSubWindow *active_sub_window = ui->mdiArea->activeSubWindow();
    if(active_sub_window != 0) //当没有活动窗口时activeSubWindow()返回0
        return qobject_cast<MyMdi*>(active_sub_window->widget());//子窗口转换成MyMdi对象
    else
        return 0;
}

//读取关闭前的状态
void MainWindow::readSettings()
{
    QSettings settings("Qt", "MyMdi");
    //settings.value()第二个参数为默认值，即如果key：“pos”不存在，则返回默认值
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(900, 600)).toSize();
    move(pos); //在构造函数中才调用read_settings()函数，因此这里重新移动窗口位置和设置窗口大小
    resize(size);
}

void MainWindow::writeSettings()
{
    QSettings settings("Qt", "MyMdi");//第一个为公司的名字，第二个为软件的名字
    settings.setValue("pos", pos());//写入该窗口相对于其父窗口的位置信息
    settings.setValue("size", size());//写入窗口大小信息
}

void MainWindow::initWindow()
{
    setWindowTitle(QStringLiteral("多窗口文本编辑器"));
    ui->mainToolBar->setWindowTitle(QStringLiteral("工具栏"));//设置工具栏的标题名称，右击时才可以看到

    //当需要的时候，设置水平垂直滚动条
    ui->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    ui->statusBar->showMessage(QStringLiteral("欢迎使用多文档编辑器"));

    QLabel *label = new QLabel(this);
    label->setFrameStyle(QFrame::Box | QFrame::Sunken);//设置label的形状和阴影模式的,这里采用的box形状和凹陷模式
    label->setText(QStringLiteral("<a href = \"http://blog.csdn.net/u012041204\">我的CSDN，欢迎关注</a>"));//设置文本内容
    label->setTextFormat(Qt::RichText);//设置文本格式为富文本格式，又称多文本格式，用于跨平台使用的
    label->setOpenExternalLinks(true);//运行打开label上的链接

    ui->statusBar->addPermanentWidget(label);//将label附加到状态栏上，永久性的

    ui->actionNew->setStatusTip(QStringLiteral("创建一个文件"));
    ui->actionOpen->setStatusTip(QStringLiteral("打开一个已经存在的文件"));
    ui->actionSave->setStatusTip(QStringLiteral("保存文档到硬盘"));
    ui->actionSaveAS->setStatusTip(QStringLiteral("以新的名称保存文档"));
    ui->actionExit->setStatusTip(QStringLiteral("退出应用程序"));
    ui->actionUndo->setStatusTip(QStringLiteral("撤销先前的操作"));
    ui->actionRedo->setStatusTip(QStringLiteral("恢复先前的操作"));
    ui->actionCut->setStatusTip(QStringLiteral("剪切选中的内容到剪贴板"));
    ui->actionCopy->setStatusTip(QStringLiteral("复制选中的内容到剪贴板"));
    ui->actionPaste->setStatusTip(QStringLiteral("粘贴剪贴板的内容到当前位置"));
    ui->actionClose->setStatusTip(QStringLiteral("关闭活动窗口"));
    ui->actionCloseAll->setStatusTip(QStringLiteral("关闭所有窗口"));
    ui->actionTile->setStatusTip(QStringLiteral("平铺所有窗口"));
    ui->actionCascade->setStatusTip(QStringLiteral("层叠所有窗口"));
    ui->actionNext->setStatusTip(QStringLiteral("将焦点移动到下一个窗口"));
    ui->actionPrevious->setStatusTip(QStringLiteral("将焦点移动到前一个窗口"));
    ui->actionAbout->setStatusTip(QStringLiteral("显示本软件的介绍"));

}

//更新Menu中按钮的状态
void MainWindow::UpdateMenus()
{
    bool has_active_window; //如果有活动窗口，则为true，没有则为false
    if(GetActiveWindow())
       has_active_window = true;
    else
       has_active_window = false;

    //下面是根据是否存在活动窗口来设置各个动作是否可用,没有激活的窗口按钮不能用
    ui->actionSave->setEnabled(has_active_window);
    ui->actionSaveAS->setEnabled(has_active_window);
    ui->actionPaste->setEnabled(has_active_window);
    ui->actionClose->setEnabled(has_active_window);
    ui->actionCloseAll->setEnabled(has_active_window);
    ui->actionTile->setEnabled(has_active_window);
    ui->actionCascade->setEnabled(has_active_window);
    ui->actionNext->setEnabled(has_active_window);
    ui->actionPrevious->setEnabled(has_active_window);

    //只有当有活动窗口，且有文字被选中时，剪切和复制功能才可以使用
    bool has_text_selection;
    has_text_selection = (GetActiveWindow() && GetActiveWindow()->textCursor().hasSelection());
    ui->actionCut->setEnabled(has_text_selection);
    ui->actionCopy->setEnabled(has_text_selection);

    //有活动窗口，且系统判断可以执行撤销操作时才显示撤销可用,判断恢复操作可执行时恢复操作才可用
    ui->actionUndo->setEnabled(GetActiveWindow() && GetActiveWindow()->document()->isUndoAvailable());
    ui->actionRedo->setEnabled(GetActiveWindow() && GetActiveWindow()->document()->isRedoAvailable());

}

//设置活动窗口
void MainWindow::setActiveSubWindow(QWidget *window)
{
    if(!window)
        return;
    //将当前窗口设置为多文档中的活动窗口
    ui->mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow*>(window));
}

void MainWindow::UpdateWindowMenu()
{
    ui->menuWindow_W->clear();//清空所有菜单栏
    /*重新加载已有的菜单*/
    ui->menuWindow_W->addAction(ui->actionClose);
    ui->menuWindow_W->addAction(ui->actionCloseAll);
    ui->menuWindow_W->addSeparator();
    ui->menuWindow_W->addAction(ui->actionTile);
    ui->menuWindow_W->addAction(ui->actionCascade);
    ui->menuWindow_W->addSeparator();
    ui->menuWindow_W->addAction(ui->actionNext);
    ui->menuWindow_W->addAction(ui->actionPrevious);
    //加载间隔器
    ui->menuWindow_W->addAction(actionSeparator);

    QList<QMdiSubWindow *> windows = ui->mdiArea->subWindowList();
    actionSeparator->setVisible(!windows.isEmpty());

    for(int i = 0; i < windows.size(); i++)
    {
        MyMdi *child = qobject_cast<MyMdi*>(windows.at(i)->widget());
        QString text;
        if(i < 1)//这个时候变化数字就是其快捷键
            text = QStringLiteral("&%1 %2").arg(i+1).arg(child->get_current_file_name());//内容前面加了“&”表示可以使用快捷键，为第一个字母或数字
        else
            text = QStringLiteral("%1 %2").arg(i+1).arg(child->get_current_file_name());

        QAction *action = ui->menuWindow_W->addAction(text);//添加新的菜单动作
        action->setCheckable(true);
        action->setChecked(child == GetActiveWindow());//选中当前的活动窗口
        connect(action, SIGNAL(triggered()), window_mapper, SLOT(map()));//选中action会触发槽函数发送mapped()信号
        //该函数的作用是设置一个映射，当在运行action的信号函数map()时，该函数会自动发送信号mapped()，并且会以mapped(windows.at(i))来发送
        //此时会触发在构造函数中设置的连接，其槽函数为设置活动窗口
        window_mapper->setMapping(action, windows.at(i));
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    ui->mdiArea->closeAllSubWindows();
    if(ui->mdiArea->currentSubWindow())//如果还有窗口没关闭，则忽略该事件。应该是上面的语句没有全部关闭成功。
        event->ignore();
    else
    {
        writeSettings();//关闭前写入窗口设置
        event->accept();//关闭
    }
}

//状态栏上显示光标的行号和列号
void MainWindow::ShowTextRowCol()
{
    if(GetActiveWindow())
        {
            ui->statusBar->showMessage(QStringLiteral("%1行 %2列").arg(GetActiveWindow()->textCursor().blockNumber()+1).
                                       arg(GetActiveWindow()->textCursor().columnNumber()+1), 2000);
        }
}
//创建MyMdi对象并关联槽
MyMdi* MainWindow::CreateMyMdi()
{
    MyMdi *child = new MyMdi();
    ui->mdiArea->addSubWindow(child);

    //根据是否可复制来设置剪切复制动作是否可用
    connect(child, SIGNAL(copyAvailable(bool)), ui->actionCopy, SLOT(setEnabled(bool)));
    connect(child, SIGNAL(copyAvailable(bool)), ui->actionCut, SLOT(setEnabled(bool)));

    //根据文档时否可用撤销和恢复来设置相应的撤销恢复动作是否可用
    connect(child->document(), SIGNAL(undoAvailable(bool)), ui->actionUndo, SLOT(setEnabled(bool)));
    connect(child->document(), SIGNAL(redoAvailable(bool)), ui->actionRedo, SLOT(setEnabled(bool)));
    //光标位置改变在状态栏显示行号和列号
    connect(child, SIGNAL(cursorPositionChanged()), this, SLOT(ShowTextRowCol()));
    return child;
}

QMdiSubWindow* MainWindow::FindMdiChild(const QString &file_name)
{
    QString canonical_file_path = QFileInfo(file_name).canonicalFilePath();//解释过后的绝对路径
    foreach(QMdiSubWindow *window, ui->mdiArea->subWindowList())
        {
            MyMdi *my_mdi = qobject_cast<MyMdi *>(window->widget());//qobject_cast为进行强制类型转换
            if(my_mdi->CurrentFilePath() == canonical_file_path)//如果已经存在该窗口，则返回。比较的是绝对路径名+文件名
                return window;
        }
    return 0;//没找到，则返回0
}

void MainWindow::on_actionNew_triggered()
{
    MyMdi *new_mdi = CreateMyMdi();
    new_mdi->NewFile();//新建文件
    new_mdi->show();
}

void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this);//通过文件选择对话框来选择文件，返回选择的文件名
    if(!file_name.isEmpty()) //文件名不为空
    {
        QMdiSubWindow *existing_window = FindMdiChild(file_name);
        if(existing_window) //如果该文件对应窗口已经打开
        {
            setActiveSubWindow(existing_window);//设置该窗口为活动窗口
            return ;
        }
        MyMdi *open_window = CreateMyMdi();//否则新建子窗口,且加入到多文档容器中
        if(open_window->LoadFile(file_name))
        {
            ui->statusBar->showMessage(QStringLiteral("打开文件成功"), 2000);//状态栏显示打开文件成功，持续2秒
            open_window->show();
        }
        else
        {
            open_window->close();//打不开该文件时，则销毁新建的窗口
        }
    }
}

void MainWindow::on_actionSave_triggered()
{
    if(GetActiveWindow() && GetActiveWindow()->Save())
        ui->statusBar->showMessage(QStringLiteral("保存文件成功"), 2000);//状态栏显示保存成功字样2秒
}

void MainWindow::on_actionSaveAS_triggered()
{
    if(GetActiveWindow() && GetActiveWindow()->SaveAs())
        ui->statusBar->showMessage(QStringLiteral("保存文件成功"), 2000);//状态栏显示保存成功字样2秒
}

void MainWindow::on_actionExit_triggered()
{
    qApp->closeAllWindows();//qApp为全局指针，关闭所有窗口
}

void MainWindow::on_actionUndo_triggered()
{
    if(GetActiveWindow())
        GetActiveWindow()->undo();//撤销
}

void MainWindow::on_actionRedo_triggered()
{
    if(GetActiveWindow())
        GetActiveWindow()->redo(); //恢复
}


void MainWindow::on_actionCut_triggered()
{
    if(GetActiveWindow())
        GetActiveWindow()->cut(); //剪切
}

void MainWindow::on_actionCopy_triggered()
{
    if(GetActiveWindow())
        GetActiveWindow()->copy(); //拷贝
}

void MainWindow::on_actionPaste_triggered()
{
    if(GetActiveWindow())
        GetActiveWindow()->paste(); //粘帖
}

void MainWindow::on_actionClose_triggered()
{
    ui->mdiArea->closeActiveSubWindow();//关闭当前活动窗口
}


void MainWindow::on_actionCloseAll_triggered()
{
    ui->mdiArea->closeAllSubWindows(); //关闭所有子窗口
}

void MainWindow::on_actionTile_triggered()
{
    ui->mdiArea->tileSubWindows(); //平铺
}


void MainWindow::on_actionCascade_triggered()
{
    ui->mdiArea->cascadeSubWindows(); //重叠
}


void MainWindow::on_actionPrevious_triggered()
{
    ui->mdiArea->activatePreviousSubWindow();//上一个窗口
}

void MainWindow::on_actionNext_triggered()
{
    ui->mdiArea->activateNextSubWindow();//下一个窗口
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, QStringLiteral("关于本软件"), QStringLiteral("这是个多窗口文本编辑器\n 感谢yiminyangguang520的帮助!\n欢迎关注我的CSDN：http://blog.csdn.net/u012041204\n"
                                                                     "Github:https://github.com/yangyongda\n"));
}
