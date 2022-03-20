
#include <qdebug.h>
#include "tcpserver.h"

SkTcpServer::SkTcpServer(SkConfig *config)
{
    m_config = config;
    m_server = new QTcpServer;
    connect(m_server, &QTcpServer::newConnection,
            this, &SkTcpServer::creatClient);
}

SkTcpServer::~SkTcpServer()
{
    if (m_config)
        delete m_config;
    delete m_server;
}

void SkTcpServer::startListen(void)
{
    if (m_config)
    {
        ServerConfig *config = (ServerConfig *)m_config;
        if (!m_server->isListening())
            m_server->listen(QHostAddress::Any, config->m_port);
    }
}

void SkTcpServer::stopListen(void)
{
}

void SkTcpServer::creatClient(void)
{
    while (m_server->hasPendingConnections())
    {
        QTcpSocket *socket = m_server->nextPendingConnection();
        SkTcpClient *client = new SkTcpClient(socket);
        connect(client, &SkTcpClient::hasText, this, &SkTcpServer::readText);
        m_clients.append(client);
    }
}

void SkTcpServer::readText(QTcpSocket *client)
{
    QString text;
    text = client->readAll();
    emit readTextOkay(text);
}

void SkTcpServer::writeText(QTcpSocket *client, const QString &text)
{
    client->write(text.toLocal8Bit());
}
