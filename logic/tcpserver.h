
#ifndef Q_SOCKET_ASSISTANT_LINK
#define Q_SOCKET_ASSISTANT_LINK

#include <qtcpsocket.h>
#include <qtcpserver.h>
#include "skconfig.h"

class SkTcpServer;
class SkTcpLink : public QObject
{
    Q_OBJECT
public:
    SkTcpLink(QTcpSocket *socket, QObject *parent = 0);
    ~SkTcpLink();

signals:
    void hasText(SkTcpLink *);

public slots:
    inline void setTextType(bool checked)
    {
        m_hex = checked;
    }

private slots:
    inline void emitHasText(void)
    {
        emit hasText(this);
    }

private:
    bool m_hex;
    QTcpSocket *m_socket;
    friend class SkTcpServer;
};

class SkTcpServer : public QObject
{
    Q_OBJECT
public:
    SkTcpServer(SkConfig *config = 0);
    ~SkTcpServer();
    inline void setConfig(SkConfig *config)
    {
        m_config = config;
    }
    inline SkConfig *getConfig() const
    {
        return m_config;
    }
signals:
    void delTcpLink(QTcpSocket *);
    void readTextOkay(QString &);

public slots:
    void startServer(void);
    void stopServer(void);
    void recvLink(void);
    void readText(SkTcpLink *);
    void writeText(SkTcpLink *, const QString &);

private:
    SkConfig *m_config;
    QTcpServer *m_server;
    QList<SkTcpLink *> m_links;
};

#endif // Q_SOCKET_ASSISTANT_LINK
