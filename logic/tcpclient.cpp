
#include <qhostaddress.h>
#include "tcpclient.h"

SkTcpClient::SkTcpClient(QTcpSocket *socket, QObject *parent) : QObject(parent)
{
    m_socket = socket;
    connect(m_socket, &QTcpSocket::readyRead,
            this, &SkTcpClient::emitHasText);
}

SkTcpClient::SkTcpClient(SkConfig *config, QObject *parent) : QObject(parent)
{
    if (0 != config && SOCKET_TYPE_TCP == config->m_type)
    {
        m_socket = new QTcpSocket;
        ClientConfig *client = (ClientConfig *)config;
        m_socket->bind(QHostAddress(client->m_hostLocal), client->m_portLocal);
        m_socket->connectToHost(QHostAddress(client->m_host), client->m_port);
    }
}

SkTcpClient::~SkTcpClient()
{
    delete m_socket;
}

// inline void SkTcpClient::emitHasText(void)
// {
//     emit hasText(m_socket);
// }
