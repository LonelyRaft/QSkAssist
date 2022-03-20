
#include <qrandom.h>
#include <qstring.h>
#include "skdialog.h"

SkDlgConfig::SkDlgConfig(QWidget *parent) : QDialog(parent)
{
    m_labName.setText((tr("Name:")));
    m_labName.setAlignment(Qt::AlignRight);
    m_labType.setText(tr("Type:"));
    m_labType.setAlignment(Qt::AlignRight);
    m_labHost.setText(tr("Host:"));
    m_labHost.setAlignment(Qt::AlignRight);
    m_labPort.setText(tr("Port:"));
    m_labPort.setAlignment(Qt::AlignRight);
    m_btnOkay.setText(tr("&Okay"));
    m_btnClear.setText(tr("&Clear"));
    m_btnRand.setText(tr("&Rand"));
    m_type.addItem(tr("TCP"));
    m_type.addItem(tr("UDP"));
    m_layout.addWidget(&m_labName, 0, 0, 1, 3);
    m_layout.addWidget(&m_edtName, 0, 3, 1, 7);
    m_layout.addWidget(&m_labType, 1, 0, 1, 3);
    m_layout.addWidget(&m_type, 1, 3, 1, 7);
    m_layout.addWidget(&m_labHost, 2, 0, 1, 3);
    m_layout.addWidget(&m_edtHost, 2, 3, 1, 7);
    m_layout.addWidget(&m_labPort, 3, 0, 1, 3);
    m_layout.addWidget(&m_edtPort, 3, 3, 1, 5);
    m_layout.addWidget(&m_btnRand, 3, 8, 1, 2);
    m_layout.addWidget(&m_btnClear, 4, 0, 1, 10);
    m_layout.addWidget(&m_btnOkay, 5, 0, 1, 10);
    setLayout(&m_layout);
}

SkDlgConfig::~SkDlgConfig()
{
}

void SkDlgConfig::clearData(void)
{
    m_edtName.clear();
    m_type.setCurrentIndex(0);
    m_edtHost.clear();
    m_edtPort.clear();
}

void SkDlgConfig::randPort(void)
{
    unsigned int port =
        QRandomGenerator::global()->generate();
    m_edtPort.setText(
        QString::number(port % 0xffff));
}

int SkDlgConfig::getSocketConfig(SkConfig *config)
{
    if (0 == config)
        return 0;
    QString str_type = m_type.currentText();
    QString str_name = m_edtName.text();
    QString str_host = m_edtHost.text();
    QString str_port = m_edtPort.text();
    config->m_name = str_name;
    config->m_type = m_type.currentIndex();
    config->m_host = SkConfig::ip2num(str_host);
    config->m_port = str_port.toUInt();
    if (str_name.isEmpty())
    {
        config->m_name =
            QString("%1:%2(%3)")
                .arg(str_type)
                .arg(str_host)
                .arg(str_port);
    }
    return 0;
}

SkDlgClient::SkDlgClient(QWidget *parent) : SkDlgConfig(parent)
{
    m_labHostLocal.setText(tr("Local Host:"));
    m_labHostLocal.setAlignment(Qt::AlignRight);
    m_labPortLocal.setText(tr("Local Port:"));
    m_labPortLocal.setAlignment(Qt::AlignRight);
    m_layout.removeWidget(&m_btnClear);
    m_layout.removeWidget(&m_btnOkay);
    m_layout.addWidget(&m_labHostLocal, 4, 0, 1, 3);
    m_layout.addWidget(&m_edtHostLocal, 4, 3, 1, 7);
    m_layout.addWidget(&m_labPortLocal, 5, 0, 1, 3);
    m_layout.addWidget(&m_edtPortLocal, 5, 3, 1, 7);
    m_layout.addWidget(&m_btnClear, 6, 0, 1, 10);
    m_layout.addWidget(&m_btnOkay, 7, 0, 1, 10);
    connect(&m_btnRand, &QPushButton::clicked,
            this, &SkDlgClient::randPort);
    connect(&m_btnOkay, &QPushButton::clicked,
            this, &SkDlgClient::accept);
    connect(&m_btnClear, &QPushButton::clicked,
            this, &SkDlgClient::clearData);
}

SkDlgClient::~SkDlgClient()
{
}

void SkDlgClient::clearData(void)
{
    m_edtName.clear();
    m_type.setCurrentIndex(0);
    m_edtHost.clear();
    m_edtPort.clear();
    m_edtHostLocal.clear();
    m_edtPortLocal.clear();
}

int SkDlgClient::getSocketConfig(SkConfig *config)
{
    if (0 == config)
        return 1;
    ClientConfig *client = (ClientConfig *)config;
    QString str_type = m_type.currentText();
    client->m_name = m_edtName.text();
    client->m_type = m_type.currentIndex();
    client->m_host = SkConfig::ip2num(m_edtHost.text());
    client->m_hostLocal = SkConfig::ip2num(m_edtHostLocal.text());
    if (0 == client->m_host)
        return 2;
    client->m_port = m_edtPort.text().toUInt();
    client->m_portLocal = m_edtPortLocal.text().toUInt();
    if (0 == client->m_port || 0xffff < client->m_port)
        return 3;
    if (client->m_name.isEmpty())
    {
        client->m_name =
            QString("%1:%2(%3)")
                .arg(str_type)
                .arg(m_edtHost.text())
                .arg(m_edtPort.text());
    }
    return 0;
}

SkDlgServer::SkDlgServer(QWidget *parent) : SkDlgConfig(parent)
{
    connect(&m_btnRand, &QPushButton::clicked,
            this, &SkDlgServer::randPort);
    connect(&m_btnOkay, &QPushButton::clicked,
            this, &SkDlgServer::accept);
    connect(&m_btnClear, &QPushButton::clicked,
            this, &SkDlgServer::clearData);
}

SkDlgServer::~SkDlgServer()
{
}

int SkDlgServer::getSocketConfig(SkConfig *config)
{
    if (0 == config)
        return 1;
    ServerConfig *server = (ServerConfig *)config;
    QString str_type = m_type.currentText();
    server->m_name = m_edtName.text();
    server->m_type = m_type.currentIndex();
    server->m_host = SkConfig::ip2num(m_edtHost.text());
    if (0 == server->m_host)
        return 2;
    server->m_port = m_edtPort.text().toUInt();
    if (0 == server->m_port || 0xffff < server->m_port)
        return 3;
    if (server->m_name.isEmpty())
    {
        server->m_name =
            QString("%1:%2(%3)")
                .arg(str_type)
                .arg(m_edtHost.text())
                .arg(m_edtPort.text());
    }
    return 0;
}
