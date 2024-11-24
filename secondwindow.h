#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>
#include <QKeyEvent>

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
    void appendMessage(const QString &message);
    void keyPressEvent(QKeyEvent *event) override;

signals:
    void sendMessageToServer(const QString &message);

private slots:
    void onSendButtonClicked();
private:
    Ui::SecondWindow *ui;
    QTextEdit *chatBox;
    QLineEdit *inputBox;
    QPushButton *sendButton;
};

#endif // SECONDWINDOW_H
