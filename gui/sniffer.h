#ifndef SNIFFER_H
#define SNIFFER_H


#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/file.h>
#include<sys/time.h>
#include<sys/socket.h>
#include<sys/ioctl.h>
#include<sys/signal.h>
#include<sys/stat.h>
#include<net/if.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<netinet/tcp.h>
#include<netinet/if_ether.h>
#include<netdb.h>
#include<fcntl.h>

#include <QDialog>

namespace Ui {
class sniffer;
}

class sniffer : public QDialog
{
    Q_OBJECT

public:
    explicit sniffer(QWidget *parent = 0);
    ~sniffer();
signals:
    void sendMessage(QString msg);

private slots:
    void on_pushButton_clicked();

    void on_auto_get_clicked();

    void on_set_clicked();
    void procedure(char *interface, int fd);

    //void on_start_clicked();
    void tcp_viewer();

    void on_startsniffer_clicked();

private:
    Ui::sniffer *ui;
};

#endif // SNIFFER_H
