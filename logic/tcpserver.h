
#ifndef Q_SOCKET_ASSISTANT_TCPSERVER
#define Q_SOCKET_ASSISTANT_TCPSERVER

#include <qtcpserver.h>
#include <qlist.h>
#include <qstring.h>
#include "skconfig.h"
#include "tcpclient.h"

class SkDataTcpServer;
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
    void stopListen(void);
    void creatClient(void);
    void readText(QTcpSocket *);
    void writeText(QTcpSocket *, const QString &);

private:
    SkConfig *m_config;
    QTcpServer *m_server;
    QList<SkTcpClient *> m_clients;
    friend class SkDataTcpServer;
};

#endif // Q_SOCKET_ASSISTANT_TCPSERVER
