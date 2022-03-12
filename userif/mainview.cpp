
#include "mainview.h"

SkMainWindow::SkMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_status = new QStatusBar(parent);
    m_tree = new SkTreeView(parent);
    m_content = new QWidget(parent);
    m_layout = new QGridLayout();
    initUserIF();
}

SkMainWindow::~SkMainWindow()
{
    delete m_status;
    delete m_tree;
    delete m_layout;
    delete m_content;
}

void SkMainWindow::initUserIF(void)
{
    setStatusBar(m_status);
    m_layout->addWidget(m_tree,0,0,10,2);
    m_content->setLayout(m_layout);
    setCentralWidget(m_content);
}
