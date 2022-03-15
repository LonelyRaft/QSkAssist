
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
};

class UDPConfig : public SkConfig
{
public:
    unsigned int m_hTarget;
    unsigned int m_pTarget;
};

class TCPServerConfig : public SkConfig
{
public:
    unsigned int m_mLocal;
};

class TCPClientConfig : public SkConfig
{
public:
};

#endif // Q_SOCKET_ASSISTANT_CONFIG
