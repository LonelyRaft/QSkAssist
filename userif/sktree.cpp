
#include <qdebug.h>
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
    connect(menu.m_new, &QAction::triggered,
            this, &SkTreeView::onNew);
    connect(menu.m_start, &QAction::triggered,
            this, &SkTreeView::onStart);
    connect(menu.m_stop, &QAction::triggered,
            this, &SkTreeView::onStop);
    connect(menu.m_delete, &QAction::triggered,
            this, &SkTreeView::onDelete);
    // connect(menu.m_refresh, &QAction::triggered,
    // this, &SkTreeView::onRefresh);
    menu.exec(QCursor::pos());
}

void SkTreeView::onNew(bool checked)
{
    qDebug() << "onNew Server\n";
}

void SkTreeView::onStart(bool checked)
{
    qDebug() << "onStart Server\n";
}

void SkTreeView::onStop(bool checked)
{
    qDebug() << "onStop Server\n";
}

void SkTreeView::onDelete(bool checked)
{
    qDebug() << "onDelete Server\n";
}

// void SkTreeView::onRefresh(bool checked)
// {
//     qDebug() << "onRefresh Server\n";
// }

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
    // m_refresh->setText(tr("Refresh Server"));
    addAction(m_new);
    addAction(m_start);
    addAction(m_stop);
    addAction(m_delete);
    // addAction(m_refresh);
}
