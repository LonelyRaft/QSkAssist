
#ifndef Q_SOCKET_ASSISTANT_CONFIG
#define Q_SOCKET_ASSISTANT_CONFIG

#include <qstring.h>

struct ClientConfig
{
    QString m_name;
    QString m_host;
    QString m_port;
    QString m_type;
};

struct ServerConfig
{
    QString m_name;
    QString m_host;
    QString m_port;
    QString m_type;
};

#endif // Q_SOCKET_ASSISTANT_CONFIG
