#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class SecondWindow;
}
QT_END_NAMESPACE

class SecondWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();
    QTextEdit *chatBox;
    QLineEdit *inputBox;
    QPushButton *sendButton;
signals:
    void sendMessageToServer(const QString &message);

private slots:
    void onSendButtonClicked();
private:
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
