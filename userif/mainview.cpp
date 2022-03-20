
#include <qdebug.h>
#include "mainview.h"
#include "skdata.h"

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
    connect(m_server, &SkServerTree::addServer,
            this, &SkMainWindow::addServer);
    connect(m_server, &SkServerTree::startServer,
            this, &SkMainWindow::startServer);
    connect(m_server, &SkServerTree::stopServer,
            this, &SkMainWindow::stopServer);
    connect(m_server, &SkServerTree::removeServer,
            this, &SkMainWindow::removeServer);
    connect(m_client, &SkClientTree::addClient,
            this, &SkMainWindow::addClient);
    connect(m_client, &SkClientTree::startClient,
            this, &SkMainWindow::startClient);
    connect(m_client, &SkClientTree::stopClient,
            this, &SkMainWindow::stopClient);
    connect(m_client, &SkClientTree::removeClient,
            this, &SkMainWindow::removeClient);
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

void SkMainWindow::addServer(SkConfig *config)
{
    if (0 == config)
        return;
    switch (config->m_type)
    {
    case SOCKET_TYPE_TCP:
    {
        SkData *data = new SkDataTcpServer(config);
        m_data->addTab(data, config->m_name);
        m_status->showMessage(QString(
            tr("Server Add: %1").arg(config->m_name)));
        break;
    }
    case SOCKET_TYPE_UDP:
    {
        SkData *data = new SkData(config);
        m_data->addTab(data, config->m_name);
        m_status->showMessage(QString(
            tr("Server Add: %1").arg(config->m_name)));
        break;
    }
    default:
        break;
    }
}

void SkMainWindow::startServer(SkConfig *config)
{
    SkData *data;
    int cnt = m_data->count();
    if (0 == config)
        return;
    for (int idx = 0; idx < cnt; idx++)
    {
        data = (SkData *)m_data->widget(idx);
        if (config == data->m_config)
        {
            ((SkDataTcpServer *)data)->startListen();
            m_status->showMessage(QString(
                tr("Server Start: %1").arg(config->m_name)));
            break;
        }
    }
}

void SkMainWindow::stopServer(SkConfig *config)
{
    SkData *data;
    int cnt = m_data->count();
    if (0 == config)
        return;
    for (int idx = 0; idx < cnt; idx++)
    {
        data = (SkData *)m_data->widget(idx);
        if (config == data->m_config)
        {

            break;
        }
    }
}

void SkMainWindow::removeServer(SkConfig *config)
{
    SkData *data;
    int cnt = m_data->count();
    if (0 == config)
        return;
    for (int idx = 0; idx < cnt; idx++)
    {
        data = (SkData *)m_data->widget(idx);
        if (config == data->m_config)
        {
            m_data->removeTab(idx);
            m_status->showMessage(QString(
                tr("Server Remove: %1").arg(config->m_name)));
            break;
        }
    }
}

void SkMainWindow::addClient(SkConfig *config)
{
    if (0 == config)
        return;
    switch (config->m_type)
    {
    case SOCKET_TYPE_TCP:
    {
        SkData *data = new SkDataTcpCleint(config);
        m_data->addTab(data, config->m_name);
        m_status->showMessage(QString(
            tr("Client Add: %1").arg(config->m_name)));
        break;
    }
    case SOCKET_TYPE_UDP:
    {
        SkData *data = new SkData(config);
        m_data->addTab(data, config->m_name);
        m_status->showMessage(QString(
            tr("Client Add: %1").arg(config->m_name)));
        break;
    }
    default:
        break;
    }
}

void SkMainWindow::startClient(SkConfig *config)
{
    if (0 == config)
        return;
}

void SkMainWindow::stopClient(SkConfig *config)
{
    if (0 == config)
        return;
}

void SkMainWindow::removeClient(SkConfig *config)
{
    SkData *data;
    int cnt = m_data->count();
    if (0 == config)
        return;
    for (int idx = 0; idx < cnt; idx++)
    {
        data = (SkData *)m_data->widget(idx);
        if (config == data->m_config)
        {
            m_data->removeTab(idx);
            m_status->showMessage(QString(
                tr("Client Remove: %1").arg(config->m_name)));
            break;
        }
    }
}
