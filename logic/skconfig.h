
#ifndef Q_SOCKET_ASSISTANT_CONFIG
#define Q_SOCKET_ASSISTANT_CONFIG

#include <qstring.h>

#define SOCKET_TYPE_UDP 0x01
#define SOCKET_TYPE_TCP 0x00

class SkConfig
{
public:
    unsigned int m_type;
    unsigned int m_hLocal;
    unsigned int m_pLocal;
    QString m_name;
    static unsigned int ip2num(const QString &src);
    static QString num2ip(const unsigned int src);
    int verify(void);
};

class UDPConfig : public SkConfig
{
public:
    unsigned int m_hTarget;
    unsigned int m_pTarget;
    int verify(void);
};

class TCPServerConfig : public SkConfig
{
public:
    unsigned int m_mLocal;
    int verify(void);
};

class TCPClientConfig : public SkConfig
{
public:
    unsigned int m_hTarget;
    unsigned int m_pTarget;
    int verify(void);
};

#endif // Q_SOCKET_ASSISTANT_CONFIG
