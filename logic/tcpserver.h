
#ifndef Q_SOCKET_ASSISTANT_TCPSERVER
#define Q_SOCKET_ASSISTANT_TCPSERVER

#include <qtcpserver.h>
#include <qlist.h>
#include <qstring.h>
#include "skconfig.h"
#include "tcpclient.h"

class SkTcpServer : public QObject
{
    Q_OBJECT
public:
    SkTcpServer(SkConfig *config = 0);
    ~SkTcpServer();
signals:
    void readTextOkay(QString &);
public slots:
    void startListen(void);
    void creatClient(void);
    void readText(QTcpSocket *);
    void writeText(QTcpSocket *, const QString&);

private:
    SkConfig *m_config;
    QTcpServer *m_server;
    
};

#endif // Q_SOCKET_ASSISTANT_TCPSERVER
