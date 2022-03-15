
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
    connect(m_client, &SkClientTree::addClient,
            this, &SkMainWindow::addClient);
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
    m_tools->addAction(m_menu->m_actAbout);
    m_tools->addAction(m_menu->m_actAboutQt);
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

void SkMainWindow::addServer(ServerConfig *config)
{
    SkData *data = new SkData(this);
    m_data->addTab(data, config->m_name);
}

void SkMainWindow::addClient(ClientConfig *config)
{
    SkData *data = new SkData(this);
    m_data->addTab(data, config->m_name);
}
