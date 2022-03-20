
#include <qdebug.h>
#include "mainview.h"
#include "skdata.h"
#include "tcpserver.h"

SkMainWindow::SkMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_menu = new SkMenuBar(this);
    m_tools = new QToolBar(parent);
    m_status = new QStatusBar(parent);
    m_server = new SkServerTree(parent);
    m_client = new SkClientTree(parent);
    m_links = new QSplitter(Qt::Vertical, parent);
    m_data = new QTabWidget(parent);
    m_content = new QWidget(parent);
    m_layout = new QGridLayout();
    initUserIF();
    connect(m_server, &SkServerTree::newServer,
            this, &SkMainWindow::newServer);
    connect(m_server, &SkServerTree::startServer,
            this, &SkMainWindow::startServer);
    connect(m_server, &SkServerTree::stopServer,
            this, &SkMainWindow::stopServer);
    connect(m_server, &SkServerTree::delServer,
            this, &SkMainWindow::delServer);
    connect(m_client, &SkClientTree::newClient,
            this, &SkMainWindow::newClient);
    connect(m_client, &SkClientTree::startClient,
            this, &SkMainWindow::startClient);
    connect(m_client, &SkClientTree::stopClient,
            this, &SkMainWindow::stopClient);
    connect(m_client, &SkClientTree::delClient,
            this, &SkMainWindow::delClient);
}

SkMainWindow::~SkMainWindow()
{
    delete m_menu;
    delete m_tools;
    delete m_status;
    delete m_server;
    delete m_client;
    delete m_links;
    delete m_data;
    delete m_layout;
    delete m_content;
}

void SkMainWindow::initUserIF(void)
{
    m_tools->addAction(&m_menu->m_actAbout);
    m_tools->addAction(&m_menu->m_actAboutQt);
    setMenuBar(m_menu);
    addToolBar(m_tools);
    setStatusBar(m_status);
    m_links->addWidget(m_server);
    m_links->addWidget(m_client);
    m_layout->addWidget(m_links, 0, 0, 10, 2);
    m_layout->addWidget(m_data, 0, 2, 10, 8);
    m_content->setLayout(m_layout);
    setCentralWidget(m_content);
}

// 新建服务器
void SkMainWindow::newServer(SkConfig *skConfig)
{
    if (0 == skConfig)
        return;
    switch (skConfig->m_type)
    {
    case SOCKET_TYPE_TCP:
    {
        // todo 新建 TCP 服务器
        break;
    }
    case SOCKET_TYPE_UDP:
    {
        // todo 新建 UDP 服务器
        break;
    }
    default:
        break;
    }
    m_server->newRow(skConfig);
    m_status->showMessage(QString(
        tr("New Server: %1").arg(skConfig->m_name)));
}

// 启动服务器
void SkMainWindow::startServer(SkConfig *skConfig)
{
    m_status->showMessage(QString(tr("启动服务器")));
}

// 停止服务器
void SkMainWindow::stopServer(SkConfig *skConfig)
{
    m_status->showMessage(QString(tr("停止服务器")));
}

// 删除服务器
void SkMainWindow::delServer(SkConfig *skConfig)
{
    m_status->showMessage(QString(tr("删除服务器")));
}

// 新建客户端
void SkMainWindow::newClient(SkConfig *skConfig)
{
    if (0 == skConfig)
        return;
    SkData *skData;
    switch (skConfig->m_type)
    {
    case SOCKET_TYPE_TCP:
        skData = new SkDataTcp(skConfig);
        break;
    case SOCKET_TYPE_UDP:
        skData = new SkDataUdp(skConfig);
        break;
    default:
        return;
    }
    m_data->addTab(skData, skConfig->m_name);
    m_client->newRow(skConfig);
    m_status->showMessage(
        QString(tr("New Client: %1").arg(skConfig->m_name)));
}

// 启动客户端
void SkMainWindow::startClient(SkConfig *skConfig)
{
    SkData *data;
    int cnt = m_data->count();
    if (0 == skConfig)
        return;
    for (int idx = 0; idx < cnt; idx++)
    {
        data = (SkData *)m_data->widget(idx);
        if (skConfig == data->m_index)
        {
            // todo: 启动客户端
            m_status->showMessage(QString(
                tr("Client Start: %1").arg(skConfig->m_name)));
            break;
        }
    }
}

// 停止客户端
void SkMainWindow::stopClient(SkConfig *skConfig)
{
    SkData *data;
    int cnt = m_data->count();
    if (0 == skConfig)
        return;
    for (int idx = 0; idx < cnt; idx++)
    {
        data = (SkData *)m_data->widget(idx);
        if (skConfig == data->m_index)
        {
            // todo: 停止客户端
            m_status->showMessage(QString(
                tr("Client Remove: %1").arg(skConfig->m_name)));
            break;
        }
    }
}

// 删除客户端
void SkMainWindow::delClient(SkConfig *skConfig)
{
    SkData *data;
    int cnt = m_data->count();
    if (0 == skConfig)
        return;
    for (int idx = 0; idx < cnt; idx++)
    {
        data = (SkData *)m_data->widget(idx);
        if (skConfig == data->m_index)
        {
            m_data->removeTab(idx);
            // todo: 删除客户端
            idx = m_client->currentIndex().row();
            m_client->delRow(idx);
            m_status->showMessage(QString(
                tr("Client Remove: %1").arg(skConfig->m_name)));
            break;
        }
    }
}
