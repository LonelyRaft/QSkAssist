
#include "skdialog.h"

SkDlgServer::SkDlgServer(QWidget *parent) : QDialog(parent)
{
    m_labName = new QLabel;
    m_labType = new QLabel;
    m_labHost = new QLabel;
    m_labPort = new QLabel;
    m_type = new QComboBox;
    m_name = new QLineEdit;
    m_host = new QLineEdit;
    m_port = new QLineEdit;
    m_create = new QPushButton;
    m_clear = new QPushButton;
    m_layout = new QGridLayout;
    initUserIF();
    connect(m_create, &QPushButton::clicked,
            this, &SkDlgServer::accept);
}

SkDlgServer::~SkDlgServer()
{
    delete m_labName;
    delete m_labType;
    delete m_labHost;
    delete m_labPort;
    delete m_type;
    delete m_name;
    delete m_host;
    delete m_port;
    delete m_create;
    delete m_clear;
    delete m_layout;
}

void SkDlgServer::initUserIF(void)
{
    m_labName->setText((tr("Name:")));
    m_labName->setAlignment(Qt::AlignRight);
    m_labType->setText(tr("Socket Type:"));
    m_labType->setAlignment(Qt::AlignRight);
    m_labHost->setText(tr("Server Host:"));
    m_labHost->setAlignment(Qt::AlignRight);
    m_labPort->setText(tr("Server Port:"));
    m_labPort->setAlignment(Qt::AlignRight);
    m_create->setText(tr("New"));
    m_clear->setText(tr("Clear"));
    m_type->addItem(tr("TCP"));
    m_type->addItem(tr("UDP"));
    m_layout->addWidget(m_labName, 0, 0, 1, 3);
    m_layout->addWidget(m_name, 0, 3, 1, 7);
    m_layout->addWidget(m_labType, 1, 0, 1, 3);
    m_layout->addWidget(m_type, 1, 3, 1, 7);
    m_layout->addWidget(m_labHost, 2, 0, 1, 3);
    m_layout->addWidget(m_host, 2, 3, 1, 7);
    m_layout->addWidget(m_labPort, 3, 0, 1, 3);
    m_layout->addWidget(m_port, 3, 3, 1, 7);
    m_layout->addWidget(m_create, 4, 1, 1, 4);
    m_layout->addWidget(m_clear, 4, 5, 1, 4);
    setLayout(m_layout);
}

int SkDlgServer::getServerConfig(ServerConfig *config)
{
    ServerConfig server;
    server.m_type = m_type->currentText();
    server.m_host = m_host->text();
    server.m_port = m_port->text();
    server.m_name = m_name->text();
    if (server.m_host.isEmpty() ||
        server.m_port.isEmpty())
        return -1;
    if (server.m_name.isEmpty())
        server.m_name =
            QString("%1:%2(%3)")
                .arg(server.m_type)
                .arg(server.m_host)
                .arg(server.m_port);
    config->m_type = server.m_type;
    config->m_host = server.m_host;
    config->m_port = server.m_port;
    config->m_name = server.m_name;
    return 0;
}

SkDlgClient::SkDlgClient(QWidget *parent) : QDialog(parent)
{
    m_labName = new QLabel;
    m_labType = new QLabel;
    m_labHost = new QLabel;
    m_labPort1 = new QLabel;
    m_labPort2 = new QLabel;
    m_type = new QComboBox;
    m_name = new QLineEdit;
    m_host = new QLineEdit;
    m_port1 = new QLineEdit;
    m_port2 = new QLineEdit;
    m_rand = new QPushButton;
    m_create = new QPushButton;
    m_clear = new QPushButton;
    m_layout = new QGridLayout;
    initUserIF();
    connect(m_create, &QPushButton::clicked,
            this, &SkDlgServer::accept);
}

SkDlgClient::~SkDlgClient()
{
    delete m_labName;
    delete m_labType;
    delete m_labHost;
    delete m_labPort1;
    delete m_labPort2;
    delete m_type;
    delete m_name;
    delete m_host;
    delete m_port1;
    delete m_port2;
    delete m_rand;
    delete m_create;
    delete m_clear;
    delete m_layout;
}

void SkDlgClient::initUserIF(void)
{
    m_labName->setText((tr("Name:")));
    m_labName->setAlignment(Qt::AlignRight);
    m_labType->setText(tr("Socket Type:"));
    m_labType->setAlignment(Qt::AlignRight);
    m_labHost->setText(tr("Target Host:"));
    m_labHost->setAlignment(Qt::AlignRight);
    m_labPort1->setText(tr("Target Port:"));
    m_labPort1->setAlignment(Qt::AlignRight);
    m_labPort2->setText(tr("Local Port:"));
    m_labPort2->setAlignment(Qt::AlignRight);
    m_rand->setText(tr("Random"));
    m_create->setText(tr("New"));
    m_clear->setText(tr("Clear"));
    m_type->addItem(tr("TCP"));
    m_type->addItem(tr("UDP"));
    m_layout->addWidget(m_labName, 0, 0, 1, 3);
    m_layout->addWidget(m_name, 0, 3, 1, 7);
    m_layout->addWidget(m_labType, 1, 0, 1, 3);
    m_layout->addWidget(m_type, 1, 3, 1, 7);
    m_layout->addWidget(m_labHost, 2, 0, 1, 3);
    m_layout->addWidget(m_host, 2, 3, 1, 7);
    m_layout->addWidget(m_labPort1, 3, 0, 1, 3);
    m_layout->addWidget(m_port1, 3, 3, 1, 7);
    m_layout->addWidget(m_labPort2, 4, 0, 1, 3);
    m_layout->addWidget(m_port2, 4, 3, 1, 7);
    m_layout->addWidget(m_rand, 5, 3, 1, 5);
    m_layout->addWidget(m_create, 6, 1, 1, 4);
    m_layout->addWidget(m_clear, 6, 5, 1, 4);
    setLayout(m_layout);
}

int SkDlgClient::getClientConfig(ClientConfig *config)
{
    config->m_name = m_name->text();
    return 0;
}
