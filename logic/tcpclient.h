
#ifndef Q_SOCKET_ASSISTANT_TCPCLIENT
#define Q_SOCKET_ASSISTANT_TCPCLIENT

#include <qtcpsocket.h>
#include "skconfig.h"

class SkTcpServer;
class SkTcpClient : public QObject
{
    Q_OBJECT
public:
    SkTcpClient(QTcpSocket *socket, QObject *parent = 0);
    SkTcpClient(SkConfig *config, QObject *parent = 0);
    ~SkTcpClient();
signals:
    void hasText(QTcpSocket *);

private slots:
    inline void emitHasText(void)
    {
        emit hasText(m_socket);
    }

private:
    QTcpSocket *m_socket;
    friend class SkTcpServer;
};

#endif // Q_SOCKET_ASSISTANT_TCPCLIENT
