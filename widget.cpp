#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QStyle>
#include <QRect>

static int i, isstop = 0;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&timer, SIGNAL(timeout()), this, SLOT(timeout_Slot()));
    setWindowTitle("计时器");

    QDesktopWidget *deskTopWidget = QApplication::desktop();
    QRect deskRect = deskTopWidget->availableGeometry();

    int appH = deskRect.height();
    int appW = deskRect.width();
    this->setFixedSize(appW, appH);
    setGeometry(0, 0, appW, appH);


    time.setHMS(0, 0, 0, 0);
    ui->ShowTimeEdit->setText("00:00:00:000");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timeout_Slot()
{
    //qDebug("1000ms");
    time = time.addMSecs(33);
    ui->ShowTimeEdit->setText(time.toString("hh:mm:ss:zzz"));
}

void Widget::on_StartButton_clicked()
{
    timer.start(30);
    ui->StartButton->setEnabled(false);
    isstop = 0;
}

void Widget::on_StopButton_clicked()
{
    timer.stop();
    ui->StartButton->setEnabled(true);
    isstop = 1;
}

void Widget::on_ResetButton_clicked()
{
    timer.stop();
    time.setHMS(0, 0, 0, 0);
    ui->ShowTimeEdit->setText("00:00:00:000");
    ui->BitEdit->clear();
    i = 0;
    ui->StartButton->setEnabled(true);
    isstop = 1;
}

void Widget::on_BitButton_clicked()
{
    QString temp;

    i = i + 1;
    temp.sprintf("%d", i);
    ui->BitEdit->append(temp);
    ui->BitEdit->append(time.toString("hh:mm:ss:zzz"));

    if (isstop == 1) {
        ui->StartButton->setEnabled(true);
    } else {
        ui->StartButton->setEnabled(false);
    }

}
