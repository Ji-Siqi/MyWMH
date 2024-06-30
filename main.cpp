#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>

enum role {};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    QTextStream qin(stdin);
    QTextStream qout(stdout);
    QTcpServer *tcpServer = new QTcpServer;
    QTcpSocket *tcpSocket[10] = {NULL};
    qout << "Please enter the room number you want to create.(It's four figures.)" << endl;
    int port;
    qin >> port;
    tcpServer -> listen(QHostAddress::Any, port);
    qout << "OK." << endl << "Please enter the number of people in the room.(It's a positive integer and it's a single digit number.)" << endl;
    int peopleNumber, newPeopleNumber = 0;
    qin >> peopleNumber;
    qout << "Wait for connection...";
    if (newPeopleNumber < peopleNumber) {
        QObject::connect(tcpServer, &QTcpServer::newConnection, [&](){
            //取出建立好连接的套接字
            tcpSocket[++newPeopleNumber] = tcpServer -> nextPendingConnection();

            //获取对方的IP和端口
            QString ip = tcpSocket[newPeopleNumber] -> peerAddress().toString();
            qint16 port = tcpSocket[newPeopleNumber] -> peerPort();
            QString temp = QString("[%1:%2]:连接成功").arg(ip).arg(port);

            qout << temp << endl;
        });
    }


    return a.exec();
}
