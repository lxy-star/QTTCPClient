#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QMessageBox>
#include "secondwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_2_clicked();
    void connectSolt();
    void on_connectButton_clicked();
    void onSendMessageToServer(const QString &message);
    void readyRead();

private:
    Ui::Widget *ui;
    QTcpSocket *client_socket;
    SecondWindow *secondWindow;
};
#endif // WIDGET_H
