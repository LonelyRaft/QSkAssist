
#include "skdata.h"

SkData::SkData(QWidget *parent) : QWidget(parent)
{
    m_label1 = new QLabel;
    m_label2 = new QLabel;
    m_hex1 = new QCheckBox;
    m_hex2 = new QCheckBox;
    m_tools1 = new QToolBar;
    m_tools2 = new QToolBar;
    m_data1 = new QTextEdit;
    m_data2 = new QTextEdit;
    m_box1 = new QBoxLayout(QBoxLayout::TopToBottom);
    m_box2 = new QBoxLayout(QBoxLayout::TopToBottom);
    m_recv = new QWidget;
    m_send = new QWidget;
    m_splitter = new QSplitter(Qt::Vertical);
}

SkData::~SkData()
{
    delete m_label1;
    delete m_label2;
    delete m_hex1;
    delete m_hex2;
    delete m_tools1;
    delete m_tools2;
    delete m_data1;
    delete m_data2;
    delete m_box1;
    delete m_box2;
    delete m_recv;
    delete m_send;
    delete m_splitter;
}

void SkData::initUserIF(void)
{
    m_label1->setText(tr("Send Area:"));
    m_hex1->setText(tr("Display Hex"));
    m_tools1->addWidget(m_label1);
    m_tools1->addWidget(m_hex1);
    m_box1->addWidget(m_tools1);
    m_box1->addWidget(m_data1);
    m_recv->setLayout(m_box1);

    m_label2->setText(tr("Recv Area:"));
    m_hex2->setText(tr("Display Hex"));
    m_tools2->addWidget(m_label2);
    m_tools2->addWidget(m_hex2);
    m_box2->addWidget(m_tools2);
    m_box2->addWidget(m_data2);
    m_send->setLayout(m_box2);

    m_splitter->addWidget(m_send);
    m_splitter->addWidget(m_recv);
}
