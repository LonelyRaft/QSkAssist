
#include "skdata.h"

SkData::SkData(void *index, QWidget *parent) : QWidget(parent)
{
    m_index = index;
    m_boxSend = new QBoxLayout(QBoxLayout::TopToBottom);
    m_boxRecv = new QBoxLayout(QBoxLayout::TopToBottom);
    m_labelSend = new QLabel;
    m_labelRecv = new QLabel;
    m_clearSend = new QToolButton;
    m_texSend = new QToolButton;
    m_clearRecv = new QToolButton;
    m_texStop = new QToolButton;
    m_texSave = new QToolButton;
    m_hexSend = new QCheckBox;
    m_hexRecv = new QCheckBox;
    m_toolSend = new QToolBar;
    m_toolRecv = new QToolBar;
    m_dataSend = new QTextEdit;
    m_dataRecv = new QTextEdit;
    m_send = new QWidget;
    m_recv = new QWidget;
    initUserIF();
    connect(m_clearSend, &QToolButton::clicked,
            m_dataSend, &QTextEdit::clear);
    connect(m_clearRecv, &QToolButton::clicked,
            m_dataRecv, &QTextEdit::clear);
}

SkData::~SkData()
{
    delete m_labelSend;
    delete m_labelRecv;
    delete m_clearSend;
    delete m_clearRecv;
    delete m_texSend;
    delete m_texStop;
    delete m_texSave;
    delete m_hexSend;
    delete m_hexRecv;
    delete m_boxSend;
    delete m_boxRecv;
    delete m_toolSend;
    delete m_toolRecv;
    delete m_dataSend;
    delete m_dataRecv;
    delete m_recv;
    delete m_send;
}

void SkData::initUserIF(void)
{
    m_labelSend->setText(tr("Send Area:"));
    m_hexSend->setText(tr("Display Hex"));
    m_clearSend->setText(tr("Clear"));
    m_texSend->setText(tr("Send"));
    m_toolSend->addWidget(m_labelSend);
    m_toolSend->addWidget(m_hexSend);
    m_toolSend->addWidget(m_clearSend);
    m_toolSend->addWidget(m_texSend);
    m_boxSend->addWidget(m_toolSend);
    m_boxSend->addWidget(m_dataSend);
    m_recv->setLayout(m_boxSend);

    m_labelRecv->setText(tr("Recv Area:"));
    m_hexRecv->setText(tr("Display Hex"));
    m_clearRecv->setText(tr("Clear"));
    m_texStop->setText(tr("Stop"));
    m_texSave->setText(tr("Save"));
    m_toolRecv->addWidget(m_labelRecv);
    m_toolRecv->addWidget(m_hexRecv);
    m_toolRecv->addWidget(m_clearRecv);
    m_toolRecv->addWidget(m_texStop);
    m_toolRecv->addWidget(m_texSave);
    m_boxRecv->addWidget(m_toolRecv);
    m_boxRecv->addWidget(m_dataRecv);
    m_send->setLayout(m_boxRecv);

    m_splitter.setOrientation(Qt::Vertical);
    m_splitter.addWidget(m_send);
    m_splitter.addWidget(m_recv);
    m_grid.addWidget(&m_splitter);
    setLayout(&m_grid);
}

SkDataTcp::SkDataTcp(
    void *index, QWidget *parent) : SkData(index, parent)
{
    m_client = 0;
}

SkDataTcp::~SkDataTcp()
{
    if (m_client)
        delete m_client;
}

SkDataUdp::SkDataUdp(
    void *index, QWidget *parent) : SkData(index, parent)
{
    m_client = 0;
}

SkDataUdp::~SkDataUdp()
{
    if(m_client)
    delete m_client;
}
