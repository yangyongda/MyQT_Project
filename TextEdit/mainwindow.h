#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mymdi.h"

class QMdiSubWindow;//加入一个类相当于加入一个头文件
class QSignalMapper;//这是个跟信号发射相关的类

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QAction *actionSeparator;
    QSignalMapper *window_mapper;
    MyMdi *GetActiveWindow();
    void readSettings();
    void writeSettings();
    void initWindow();
    QMdiSubWindow *FindMdiChild(const QString &file_name);//查找子窗口


private slots:
    void UpdateMenus();  //更新Menu中的按钮状态
    void UpdateWindowMenu();
    void setActiveSubWindow(QWidget *window); //设置当前窗口为活动窗口
    void closeEvent(QCloseEvent *event);
    void ShowTextRowCol();
    MyMdi *CreateMyMdi();


    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAS_triggered();
    void on_actionExit_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionCut_triggered();
    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    void on_actionClose_triggered();
    void on_actionCloseAll_triggered();
    void on_actionTile_triggered();
    void on_actionCascade_triggered();
    void on_actionPrevious_triggered();
    void on_actionNext_triggered();
    void on_actionAbout_triggered();
};

#endif // MAINWINDOW_H
