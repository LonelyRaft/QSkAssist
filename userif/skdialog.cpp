
#include <qrandom.h>
#include "skdialog.h"

SkDlgConfig::SkDlgConfig(QWidget *parent) : QDialog(parent)
{
    m_labName = new QLabel;
    m_labType = new QLabel;
    m_labHostLocal = new QLabel;
    m_labPortLocal = new QLabel;
    m_labHostTarget = new QLabel;
    m_labPortTarget = new QLabel;
    m_type = new QComboBox;
    m_edtName = new QLineEdit;
    m_edtHostLocal = new QLineEdit;
    m_edtPortLocal = new QLineEdit;
    m_edtHostTarget = new QLineEdit;
    m_edtPortTarget = new QLineEdit;
    m_btnOkay = new QPushButton;
    m_btnClear = new QPushButton;
    m_btnRand = new QPushButton;
    m_layout = new QGridLayout;
    initUserIF();
    connect(m_btnRand, &QPushButton::clicked,
            this, &SkDlgConfig::randPort);
    connect(m_btnOkay, &QPushButton::clicked,
            this, &SkDlgConfig::accept);
    connect(m_btnClear, &QPushButton::clicked,
            this, &SkDlgConfig::clearData);
}

SkDlgConfig::~SkDlgConfig()
{
    delete m_labType;
    delete m_labName;
    delete m_labHostLocal;
    delete m_labPortLocal;
    delete m_labHostTarget;
    delete m_labPortTarget;
    delete m_type;
    delete m_edtName;
    delete m_edtHostLocal;
    delete m_edtPortLocal;
    delete m_edtHostTarget;
    delete m_edtPortTarget;
    delete m_btnOkay;
    delete m_btnClear;
    delete m_layout;
}

void SkDlgConfig::initUserIF(void)
{
    m_labName->setText((tr("Name:")));
    m_labName->setAlignment(Qt::AlignRight);
    m_labType->setText(tr("Type:"));
    m_labType->setAlignment(Qt::AlignRight);
    m_labHostLocal->setText(tr("Host:"));
    m_labHostLocal->setAlignment(Qt::AlignRight);
    m_labPortLocal->setText(tr("Port:"));
    m_labPortLocal->setAlignment(Qt::AlignRight);
    m_labHostTarget->setText(tr("Target Host:"));
    m_labHostTarget->setAlignment(Qt::AlignRight);
    m_labPortTarget->setText(tr("Target Port:"));
    m_labPortTarget->setAlignment(Qt::AlignRight);
    m_btnOkay->setText(tr("&Okay"));
    m_btnClear->setText(tr("&Clear"));
    m_btnRand->setText(tr("&Rand"));
    m_type->addItem(tr("TCP"));
    m_type->addItem(tr("UDP"));

    m_layout->addWidget(m_labName, 0, 0, 1, 3);
    m_layout->addWidget(m_edtName, 0, 3, 1, 7);
    m_layout->addWidget(m_labType, 1, 0, 1, 3);
    m_layout->addWidget(m_type, 1, 3, 1, 7);
    m_layout->addWidget(m_labHostLocal, 2, 0, 1, 3);
    m_layout->addWidget(m_edtHostLocal, 2, 3, 1, 7);
    m_layout->addWidget(m_labPortLocal, 3, 0, 1, 3);
    m_layout->addWidget(m_edtPortLocal, 3, 3, 1, 5);
    m_layout->addWidget(m_btnRand, 3, 8, 1, 2);
    m_layout->addWidget(m_labHostTarget, 4, 0, 1, 3);
    m_layout->addWidget(m_edtHostTarget, 4, 3, 1, 7);
    m_layout->addWidget(m_labPortTarget, 5, 0, 1, 3);
    m_layout->addWidget(m_edtPortTarget, 5, 3, 1, 7);
    m_layout->addWidget(m_btnOkay, 7, 0, 1, 5);
    m_layout->addWidget(m_btnClear, 7, 5, 1, 5);
    setLayout(m_layout);
}

void SkDlgConfig::clearData(void)
{
    m_edtName->clear();
    m_type->setCurrentIndex(0);
    m_edtHostLocal->clear();
    m_edtPortLocal->clear();
    m_edtHostTarget->clear();
    m_edtPortTarget->clear();
}

void SkDlgConfig::randPort(void)
{
    unsigned int port =
        QRandomGenerator::global()->generate();
    m_edtPortLocal->setText(
        QString::number(port % 0xffff));
}

void SkDlgConfig::getSocketConfig(SkConfig *config)
{
    if (0 == config)
        return;
    QString var_type = m_type->currentText();
    QString var_name = m_edtName->text();
    QString var_hLocal = m_edtHostLocal->text();
    QString var_pLocal = m_edtPortLocal->text();
    config->m_name = var_name;
    config->m_type = m_type->currentIndex();
    config->m_hLocal = SkConfig::ip2num(var_hLocal);
    config->m_pLocal = var_pLocal.toUInt();
    if (var_name.isEmpty())
    {
        config->m_name =
            QString("%1:%2(%3)")
                .arg(var_type)
                .arg(var_hLocal)
                .arg(var_pLocal);
    }
}

void SkDlgConfig::getTcpClient(SkConfig *config)
{
    if (0 == config)
        return;
    TCPClientConfig *tcpconfig = (TCPClientConfig *)config;
    QString var_type = m_type->currentText();
    QString var_name = m_edtName->text();
    QString var_hLocal = m_edtHostLocal->text();
    QString var_pLocal = m_edtPortLocal->text();
    QString var_hTarget = m_edtHostTarget->text();
    QString var_pTarget = m_edtPortTarget->text();
    tcpconfig->m_name = var_name;
    tcpconfig->m_type = m_type->currentIndex();
    tcpconfig->m_hLocal = SkConfig::ip2num(var_hLocal);
    tcpconfig->m_pLocal = var_pLocal.toUInt();
    tcpconfig->m_hTarget = SkConfig::ip2num(var_hTarget);
    tcpconfig->m_pTarget = var_pTarget.toUInt();
    if (var_name.isEmpty())
    {
        config->m_name =
            QString("%1:%2(%3)")
                .arg(var_type)
                .arg(var_hTarget)
                .arg(var_pTarget);
    }
}

void SkDlgConfig::getTcpServer(SkConfig *config)
{
    if (0 == config)
        return;
    TCPServerConfig *tcpconfig = (TCPServerConfig *)config;
    QString var_type = m_type->currentText();
    QString var_name = m_edtName->text();
    QString var_hLocal = m_edtHostLocal->text();
    QString var_pLocal = m_edtPortLocal->text();
    tcpconfig->m_name = var_name;
    tcpconfig->m_type = m_type->currentIndex();
    tcpconfig->m_hLocal = SkConfig::ip2num(var_hLocal);
    tcpconfig->m_pLocal = var_pLocal.toUInt();
    if (var_name.isEmpty())
    {
        config->m_name =
            QString("%1:%2(%3)")
                .arg(var_type)
                .arg(var_hLocal)
                .arg(var_pLocal);
    }
}

void SkDlgConfig::getUdpSocket(SkConfig *config)
{
    if (0 == config)
        return;
    UDPConfig *udpconfig = (UDPConfig *)config;
    QString var_type = m_type->currentText();
    QString var_name = m_edtName->text();
    QString var_hLocal = m_edtHostLocal->text();
    QString var_pLocal = m_edtPortLocal->text();
    QString var_hTarget = m_edtHostTarget->text();
    QString var_pTarget = m_edtPortTarget->text();
    udpconfig->m_name = var_name;
    udpconfig->m_type = m_type->currentIndex();
    udpconfig->m_hLocal = SkConfig::ip2num(var_hLocal);
    udpconfig->m_pLocal = var_pLocal.toUInt();
    udpconfig->m_hTarget = SkConfig::ip2num(var_hLocal);
    udpconfig->m_pTarget = var_pTarget.toUInt();
    if (var_name.isEmpty())
    {
        config->m_name =
            QString("%1:%2(%3)")
                .arg(var_type)
                .arg(var_hTarget)
                .arg(var_pTarget);
    }
}
