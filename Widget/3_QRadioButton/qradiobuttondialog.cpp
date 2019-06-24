#include "qradiobuttondialog.h"
#include "ui_qradiobuttondialog.h"

QRadioButtonDialog::QRadioButtonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QRadioButtonDialog)
{
    ui->setupUi(this);

    //设置第一个单选按钮被选中
    ui->radioButton->setChecked(true);
    //绑定信号和槽，选择单选按钮改变答案中的文本
    connect(ui->radioButton, SIGNAL(clicked(bool)), this, SLOT(changeText()));
    connect(ui->radioButton_2, SIGNAL(clicked(bool)), this, SLOT(changeText()));
    connect(ui->radioButton_3, SIGNAL(clicked(bool)), this, SLOT(changeText()));

    //绑定提交答案的信号和槽
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(isCorrect()));
}

QRadioButtonDialog::~QRadioButtonDialog()
{
    delete ui;
}

void QRadioButtonDialog::changeText()
{
    //根据信号的发送者来改变文本框中选择的答案
    if(sender() == ui->radioButton)
    {
        ui->answer->setText("牛顿");
    }
    else if(sender() == ui->radioButton_2)
    {
        ui->answer->setText("爱因斯坦");
    }
    else if(sender() == ui->radioButton_3)
    {
        ui->answer->setText("伽利略");
    }
}

void QRadioButtonDialog::isCorrect()
{
    if(ui->radioButton->isChecked())
    {
        QMessageBox::about(this, "正确答案", "答案正确！");
    }
    else if(ui->radioButton_2->isChecked())
    {
        QMessageBox::about(this, "正确答案", "答案错误！");
    }
    else if(ui->radioButton_3->isChecked())
    {
        QMessageBox::about(this, "正确答案", "答案错误！");
    }
}
