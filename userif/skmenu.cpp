
#include "skmenu.h"

SkMenuBar::SkMenuBar(QWidget *parent) : QMenuBar(parent)
{
    m_file = new QMenu(parent);
    m_setting = new QMenu(parent);
    m_help = new QMenu(parent);
    m_actAbout = new QAction;
    m_actAboutQt = new QAction;
    initUserIF();
}

SkMenuBar::~SkMenuBar()
{
    delete m_file;
    delete m_setting;
    delete m_help;
    delete m_actAbout;
    delete m_actAboutQt;
}

void SkMenuBar::initUserIF(void)
{
    m_file->setTitle(tr("File"));
    m_setting->setTitle(tr("Setting"));
    m_help->setTitle(tr("Help"));
    m_actAbout->setText(tr("About"));
    m_actAboutQt->setText(tr("AboutQt"));
    m_help->addAction(m_actAbout);
    m_help->addAction(m_actAboutQt);
    addMenu(m_file);
    addMenu(m_setting);
    addMenu(m_help);
}

SkServerMenu::SkServerMenu(QWidget *parent) : QMenu(parent)
{
    m_acts = new QAction[4];
    m_new = m_acts;
    m_delete = m_acts + 1;
    m_start = m_acts + 2;
    m_stop = m_acts + 3;
    initUserIF();
}

SkServerMenu::~SkServerMenu()
{
    delete[] m_acts;
}

void SkServerMenu::initUserIF(void)
{
    m_new->setText(tr("New Server"));
    m_delete->setText(tr("Delete Server"));
    m_start->setText(tr("Start Server"));
    m_stop->setText(tr("Stop Server"));
    // m_refresh->setText(tr("Refresh Server"));
    addAction(m_new);
    addAction(m_start);
    addAction(m_stop);
    addAction(m_delete);
    // addAction(m_refresh);
}

SkClientMenu::SkClientMenu(QWidget *parent) : QMenu(parent)
{
    m_acts = new QAction[4];
    m_new = m_acts;
    m_start = m_acts + 1;
    m_stop = m_acts + 2;
    m_delete = m_acts + 3;
    initUserIF();
}

SkClientMenu::~SkClientMenu()
{
    delete[] m_acts;
}

void SkClientMenu::initUserIF(void)
{
    m_new->setText(tr("New Client"));
    m_start->setText(tr("Start Client"));
    m_stop->setText(tr("Stop Client"));
    m_delete->setText(tr("Delete Client"));
    // m_refresh->setText(tr("Refresh Client"));
    addAction(m_new);
    addAction(m_start);
    addAction(m_stop);
    addAction(m_delete);
    // addAction(m_refresh);
}
