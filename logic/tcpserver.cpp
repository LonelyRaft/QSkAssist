
#include "tcpserver.h"

SkTcpLink::SkTcpLink(
    QTcpSocket *socket, QObject *parent) : QObject(parent)
{
    m_socket = socket;
    m_hex = false;
}

SkTcpLink::~SkTcpLink()
{
}

SkTcpServer::SkTcpServer(SkConfig *config)
{
    m_config = config;
    m_server = 0;
}

SkTcpServer::~SkTcpServer()
{
    if (m_config)
        delete m_config;
    if (m_server)
        delete m_server;
}

void SkTcpServer::recvLink(void)
{
    while (m_server->hasPendingConnections())
    {
        QTcpSocket *socket = m_server->nextPendingConnection();
        SkTcpLink *client = new SkTcpLink(socket);
        connect(client, &SkTcpLink::hasText, this, &SkTcpServer::readText);
        m_links.append(client);
    }
}

void SkTcpServer::startServer(void)
{
    if (m_config)
    {
        m_server = new QTcpServer;
        connect(m_server, &QTcpServer::newConnection,
                this, &SkTcpServer::recvLink);
        ServerConfig *config = (ServerConfig *)m_config;
        if (!m_server->isListening())
            m_server->listen(QHostAddress::Any, config->m_port);
    }
}

void SkTcpServer::stopServer(void)
{
    if (m_server)
    {
        m_server->close();
        for (auto idx = m_links.begin();
             idx != m_links.end(); idx++)
        {
            QTcpSocket *socket = (*idx)->m_socket;
            socket->disconnectFromHost();
            if (socket->state() != QAbstractSocket::UnconnectedState)
                socket->abort();
            socket->deleteLater();
            emit delTcpLink(socket);
        }
        m_links.clear();
        delete m_server;
    }
}

void SkTcpServer::readText(SkTcpLink *client)
{
    QString text;
    text = client->m_socket->readAll();
    if (client->m_hex)
    {
    }
    emit readTextOkay(text);
}

void SkTcpServer::writeText(SkTcpLink *client, const QString &text)
{
    if (client->m_hex)
    {
    }
    client->m_socket->write(text.toLocal8Bit());
}
