#include "qtoolbuttondialog.h"
#include "ui_qtoolbuttondialog.h"


QToolButtonDialog::QToolButtonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QToolButtonDialog)
{
    ui->setupUi(this);
    //使用布局文件生成的QToolButton(很少这样使用)
    //绑定信号和槽，这里的槽是自定义的
    connect(ui->toolButton, SIGNAL(clicked(bool)), this, SLOT(showDialog()));

/************************************************************************/
    //使用代码生成QToolButton
    QVBoxLayout *layout = new QVBoxLayout(this);
    QToolBar *toolbar = new QToolBar(this);
    layout->addWidget(toolbar);
    QToolButton *button = new QToolButton(this);
    button->setIcon(QIcon(tr("://pic//res//icon.jpg")));
    button->setText("Test");
    //文本在图标下面
    button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    //按下工具按钮时显示菜单,无延迟
    //button->setPopupMode(QToolButton::InstantPopup);
    //工具按钮显示一个特殊的箭头以指示菜单是否存在，按下按钮的箭头部分时显示菜单
    button->setPopupMode(QToolButton::MenuButtonPopup);
    //向QToolBar中添加QToolButton
    toolbar->addWidget(button);
    button->setDown(false);
    QMenu *menu = new QMenu;
    menu->addAction("test 1");
    menu->addAction("test 2");
    //设置Menu
    button->setMenu(menu);
    this->setLayout(layout);


    QToolButton *button1 = new QToolButton(this);
    button1->setIcon(QIcon(tr("://pic//res//icon.jpg")));
    button1->setText("Test");
    //文本在图标下面
    button1->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    //按下工具按钮时显示菜单,无延迟
    button1->setPopupMode(QToolButton::InstantPopup);
    //向QToolBar中添加QToolButton
    toolbar->addWidget(button1);
    button1->setDown(false);
    QMenu *menu1 = new QMenu;
    menu1->addAction("test 1");
    menu1->addAction("test 2");
    //设置Menu
    button1->setMenu(menu1);

}

QToolButtonDialog::~QToolButtonDialog()
{
    delete ui;
}

void QToolButtonDialog::showDialog()
{
    QMessageBox::about(this, "QToolButton", "ui文件中拖动生成");
}
