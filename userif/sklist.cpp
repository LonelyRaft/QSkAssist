
#include "sklist.h"

SkListView::SkListView(QWidget *parent) : QListView(parent)
{
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &SkListView::customContextMenuRequested,
            this, &SkListView::onCtxMenu);
}

SkListView::~SkListView()
{
}

void SkListView::onCtxMenu(const QPoint &pos)
{
    SkListMenu menu;
    menu.exec(QCursor::pos());
}

SkListMenu::SkListMenu(QWidget *parent) : QMenu(parent)
{
    m_acts = new QAction[4];
    m_new = m_acts;
    m_start = m_acts + 1;
    m_stop = m_acts + 2;
    m_delete = m_acts + 3;
    initUserIF();
}

SkListMenu::~SkListMenu()
{
    delete[] m_acts;
}

void SkListMenu::initUserIF(void)
{
    m_new->setText(tr("New Client"));
    m_start->setText(tr("Start Client"));
    m_stop->setText(tr("Stop Client"));
    m_delete->setText(tr("Delete Client"));
    addAction(m_new);
    addAction(m_start);
    addAction(m_stop);
    addAction(m_delete);
}
