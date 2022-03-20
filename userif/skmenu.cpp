
#include "skmenu.h"

SkMenuBar::SkMenuBar(QWidget *parent) : QMenuBar(parent)
{
    initUserIF();
}

SkMenuBar::~SkMenuBar()
{
}

void SkMenuBar::initUserIF(void)
{
    m_file.setTitle(tr("File"));
    m_setting.setTitle(tr("Setting"));
    m_help.setTitle(tr("Help"));
    m_actAbout.setText(tr("About"));
    m_actAboutQt.setText(tr("AboutQt"));
    m_help.addAction(&m_actAbout);
    m_help.addAction(&m_actAboutQt);
    addMenu(&m_file);
    addMenu(&m_setting);
    addMenu(&m_help);
}

SkServerMenu::SkServerMenu(QWidget *parent) : QMenu(parent)
{
    initUserIF();
}

SkServerMenu::~SkServerMenu()
{
}

void SkServerMenu::initUserIF(void)
{
    m_new.setText(tr("New Server"));
    m_delete.setText(tr("Delete Server"));
    m_start.setText(tr("Start Server"));
    m_stop.setText(tr("Stop Server"));
    // m_refresh.setText(tr("Refresh Server"));
    addAction(&m_new);
    addAction(&m_start);
    addAction(&m_stop);
    addAction(&m_delete);
    // addAction(&m_refresh);
}

SkClientMenu::SkClientMenu(QWidget *parent) : QMenu(parent)
{
    initUserIF();
}

SkClientMenu::~SkClientMenu()
{
}

void SkClientMenu::initUserIF(void)
{
    m_new.setText(tr("New Client"));
    m_start.setText(tr("Start Client"));
    m_stop.setText(tr("Stop Client"));
    m_delete.setText(tr("Delete Client"));
    // m_refresh.setText(tr("Refresh Client"));
    addAction(&m_new);
    addAction(&m_start);
    addAction(&m_stop);
    addAction(&m_delete);
    // addAction(&m_refresh);
}
