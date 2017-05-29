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
}

MainWindow::~MainWindow()
{
    delete ui;
}
