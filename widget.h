#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTime>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    QTimer timer;
    QTime time;

private slots:
    void on_StartButton_clicked();

    void timeout_Slot();

    void on_StopButton_clicked();

    void on_ResetButton_clicked();

    void on_BitButton_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
