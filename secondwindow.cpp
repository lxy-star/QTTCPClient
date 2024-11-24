#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SecondWindow)
{
    ui->setupUi(this);

    // 初始化聊天框
    chatBox = new QTextEdit(this);
    chatBox->setReadOnly(true);             // 设置为只读，用户不能编辑
    chatBox->setGeometry(10, 10, 400, 250); // 设置聊天框的位置和大小

    // 初始化输入框
    inputBox = new QLineEdit(this);
    inputBox->setGeometry(10, 270, 300, 30); // 设置输入框的位置和大小

    // 初始化发送按钮
    sendButton = new QPushButton("发送", this);
    sendButton->setGeometry(320, 270, 90, 30); // 设置发送按钮的位置和大小

    // 连接发送按钮的点击事件
    connect(sendButton, &QPushButton::clicked, this, &SecondWindow::onSendButtonClicked);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::onSendButtonClicked()
{
    QString message = inputBox->text();
    if (!message.isEmpty()) {
        chatBox->append("客户端: " + message); // 显示发送的消息

        // 发送消息到服务器
        emit sendMessageToServer(message);

        inputBox->clear(); // 清空输入框
    }
}

void SecondWindow::appendMessage(const QString &message){
    chatBox->append("服务端: " + message);
}

void SecondWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        onSendButtonClicked();
    } else {
        QWidget::keyPressEvent(event); // 调用基类处理其他按键事件
    }
}
