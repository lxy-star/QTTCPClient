#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , secondWindow(nullptr)
{
    ui->setupUi(this);
    client_socket = new QTcpSocket();
    connect(client_socket,&QTcpSocket::readyRead,this,&Widget::readyRead);
}

Widget::~Widget()
{
    delete ui;
    delete client_socket;
    if(secondWindow){
        delete secondWindow;
    }
}
void Widget::on_pushButton_2_clicked()
{
    this->close();
}

void Widget::readyRead(){
    QByteArray data = client_socket->readAll();
    QString message = QString::fromUtf8(data);

    if (secondWindow) {
        secondWindow->appendMessage(message);  // 显示接收到的消息
    }
}

void Widget::connectSolt(){
    QMessageBox::information(this,"连接服务器","连接成功");

    if (!secondWindow) {
        secondWindow = new SecondWindow(nullptr);
        secondWindow->show();

        // 连接发送消息的信号
        connect(secondWindow, &SecondWindow::sendMessageToServer, this, &Widget::onSendMessageToServer);
    }
    // 关闭主窗口
    this->hide();
}

void Widget::on_connectButton_clicked()
{
    QString host = ui->HostLineEdit->text();
    QString portStr = ui->PortLineEdit->text();
    int port = portStr.toInt();

    if (port <= 0 || port > 65535) {
        QMessageBox::warning(this, "端口错误", "请输入有效的端口号");
        return;
    }

    QHostAddress address(host);
    client_socket->connectToHost(address, port);

    connect(client_socket, &QTcpSocket::connected, this, &Widget::connectSolt);
    connect(client_socket, &QTcpSocket::disconnected, this,&Widget::onServerDisconnected);
}

void Widget::onSendMessageToServer(const QString &message){
    if (client_socket->state() == QAbstractSocket::ConnectedState) {
        client_socket->write(message.toUtf8());
    }
}

void Widget::onServerDisconnected(){
    QMessageBox::information(this, "连接服务器", "连接失败");
    // 可以在这里进行一些清理工作，比如关闭socket
    if (client_socket) {
        client_socket->deleteLater(); // 安全地删除socket对象
        client_socket = nullptr;      // 将socket置为空指针，防止野指针
    }
    secondWindow->close();
    this->show();
}
