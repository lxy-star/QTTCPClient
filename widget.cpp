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

    if (secondWindow && secondWindow->chatBox) {
        secondWindow->chatBox->append("服务器: " + message);  // 显示接收到的消息
    }
}

void Widget::connectSolt(){
    QMessageBox::information(this,"连接服务器","连接成功");

    if (!secondWindow) {
        secondWindow = new SecondWindow(this);
        secondWindow->show();

        // 连接发送消息的信号
        connect(secondWindow, &SecondWindow::sendMessageToServer, this, &Widget::onSendMessageToServer);
    }
}

void Widget::on_connectButton_clicked()
{
    QString host = ui->HostLineEdit->text();
    QString portStr = ui->SocketLineEdit->text();
    int port = portStr.toInt();

    if (port <= 0 || port > 65535) {
        QMessageBox::warning(this, "端口错误", "请输入有效的端口号");
        return;
    }

    QHostAddress address(host);
    client_socket->connectToHost(address, port);

    connect(client_socket, &QTcpSocket::connected, this, &Widget::connectSolt);
    connect(client_socket, &QTcpSocket::disconnected, this, [this]() {
        QMessageBox::information(this, "连接服务器", "连接失败");
    });
}

void Widget::onSendMessageToServer(const QString &message){
    if (client_socket->state() == QAbstractSocket::ConnectedState) {
        client_socket->write(message.toUtf8());
    }
}
