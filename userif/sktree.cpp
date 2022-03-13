
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
    m_acts = new QAction[4];
    m_new = m_acts;
    m_delete = m_acts + 1;
    m_start = m_acts + 2;
    m_stop = m_acts + 3;
    initUserIF();
}

SkTreeMenu::~SkTreeMenu()
{
    delete[] m_acts;
}

void SkTreeMenu::initUserIF(void)
{
    m_new->setText(tr("New Server"));
    m_delete->setText(tr("Delete Server"));
    m_start->setText(tr("Start Server"));
    m_stop->setText(tr("Stop Server"));
    addAction(m_new);
    addAction(m_start);
    addAction(m_stop);
    addAction(m_delete);
}
