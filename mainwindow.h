#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtNetwork>

#include<QtNetwork/QTcpSocket>

#include<QtNetwork/QTcpServer>

#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void init();        //初始化函数用于完成一些诸如建立信号与槽之间的联系和变量给初值的初始化工作。
private slots:

   void on_send_clicked();

   void newListen(); //建立TCP监听事件

   void acceptConnection(); //接受客户端连接

   void displayError(QAbstractSocket::SocketError); //显示错误信息

private:
    Ui::MainWindow *ui;
    QTcpSocket *tcpSocket;

    QTcpServer *tcpServer;
    QTimer *timer;
};

#endif // MAINWINDOW_H
