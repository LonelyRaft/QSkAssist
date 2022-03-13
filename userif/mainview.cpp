
#include "mainview.h"

SkMainWindow::SkMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_status = new QStatusBar(parent);
    m_server = new SkTreeView(parent);
    m_client = new SkListView(parent);
    m_links = new QSplitter(Qt::Vertical, parent);
    m_data = new QTabWidget(parent);
    m_content = new QWidget(parent);
    m_layout = new QGridLayout();
    initUserIF();
}

SkMainWindow::~SkMainWindow()
{
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
    setStatusBar(m_status);
    m_links->addWidget(m_server);
    m_links->addWidget(m_client);
    m_layout->addWidget(m_links, 0, 0, 10, 2);
    m_layout->addWidget(m_data, 0, 2, 10, 8);
    m_content->setLayout(m_layout);
    setCentralWidget(m_content);
}
