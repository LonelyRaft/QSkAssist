
#ifndef Q_SOCKET_ASSISTANT_CONFIG
#define Q_SOCKET_ASSISTANT_CONFIG

#include <qvariant.h>
#include <qstring.h>

#define SOCKET_TYPE_UDP 0x01
#define SOCKET_TYPE_TCP 0x00

class SkConfig
{
public:
    unsigned int m_type;
    unsigned int m_host;
    unsigned int m_port;
    QString m_name;
    static unsigned int ip2num(const QString &src);
    static QString num2ip(const unsigned int src);
    virtual int verify(void);
};
Q_DECLARE_METATYPE(SkConfig*)

class ClientConfig : public SkConfig
{
public:
    unsigned int m_hostLocal;
    unsigned int m_portLocal;
    int verify(void);
};

class ServerConfig : public SkConfig
{
};

#endif // Q_SOCKET_ASSISTANT_CONFIG
