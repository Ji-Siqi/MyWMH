#include <QCoreApplication>
#include <QTcpServer>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    QTextStream qin(stdin);
    QTextStream qout(stdout);
    QTcpServer tcpServer;
    qout << "Please enter the room number you want to create.(It's four figures.)" << endl;
    int port;
    qin >> port;
    tcpServer.listen(QHostAddress::Any, port);
    qout << "OK." << endl << "Please enter the number of people in the room.(It's a positive integer and it's a single digit number.)" << endl;
    int peopleNumber;

    return a.exec();
}
