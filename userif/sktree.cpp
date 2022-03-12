
#include "sktree.h"

SkTreeView::SkTreeView(QWidget *parent) : QTreeView(parent)
{
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &SkTreeView::customContextMenuRequested,
            this, &SkTreeView::onCtxMenu);
}

SkTreeView::~SkTreeView()
{
}

void SkTreeView::onCtxMenu(const QPoint &pos)
{
    SkTreeMenu menu;
    menu.exec(QCursor::pos());
}

SkTreeMenu::SkTreeMenu(QWidget *parent) : QMenu(parent)
{
    m_acts = new QAction[5];
    m_new_server = m_acts;
    m_del_server = m_acts + 1;
    m_start_server = m_acts + 2;
    m_stop_server = m_acts + 3;
    m_edit_server = m_acts + 4;
    initUserIF();
}

SkTreeMenu::~SkTreeMenu()
{
    delete[] m_acts;
}

void SkTreeMenu::initUserIF(void)
{
    m_new_server->setText(tr("New Server"));
    m_del_server->setText(tr("Delete Server"));
    m_start_server->setText(tr("Start Server"));
    m_stop_server->setText(tr("Stop Server"));
    m_edit_server->setText(tr("Edit Server"));
    addAction(m_new_server);
    addAction(m_del_server);
    addAction(m_start_server);
    addAction(m_stop_server);
    addAction(m_edit_server);
}
