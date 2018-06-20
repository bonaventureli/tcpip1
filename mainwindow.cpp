#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     init();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::init()

{

   timer = new QTimer;



  this->tcpServer = new QTcpServer(this);

  this->tcpSocket = new QTcpSocket(this);



  newListen();

  connect(tcpServer,SIGNAL(newConnection()),this,SLOT(acceptConnection()));

  //newConnection()用于当有客户端访问时发出信号，acceptConnection()信号处理函数

  connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),

              this,SLOT(displayError(QAbstractSocket::SocketError)));

 //当tcpSocket在接受客户端连接时出现错误时，displayError(QAbstractSocket::SocketError)进行错误提醒并关闭tcpSocket。



}



void MainWindow::on_send_clicked()

{

   this->tcpSocket->write(ui->lineEdit->text().toLatin1());

    //用于发送字符消息

}



void MainWindow::newListen()

{

     //监听是否有客户端来访，且对任何来访者监听，端口为6666

   if(!tcpServer->listen(QHostAddress::Any,6666))

   {

      qDebug()<<tcpServer->errorString();

      close();

      return;

   }

}



void MainWindow::acceptConnection()

{

     //当有客户来访时将tcpSocket接受tcpServer建立的socket

  tcpSocket = tcpServer->nextPendingConnection();

}



void MainWindow::displayError(QAbstractSocket::SocketError)

{

   qDebug()<<tcpSocket->errorString();

   tcpSocket->close();

}
