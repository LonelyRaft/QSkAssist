
#include <qdebug.h>
#include "sklist.h"
#include "skdialog.h"
#include "skconfig.h"

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
    connect(menu.m_new, &QAction::triggered,
            this, &SkListView::onNew);
    connect(menu.m_start, &QAction::triggered,
            this, &SkListView::onStart);
    connect(menu.m_stop, &QAction::triggered,
            this, &SkListView::onStop);
    connect(menu.m_delete, &QAction::triggered,
            this, &SkListView::onDelete);
    // connect(menu.m_refresh, &QAction::triggered,
    // this, &SkListView::onRefresh);
    menu.exec(QCursor::pos());
}

void SkListView::onNew(bool checked)
{
    qDebug() << "onNew Client\n";
    SkDlgClient client;
    ClientConfig config;
    if (client.exec() == QDialog::Accepted)
    {
        client.getClientConfig(config);
    }
}

void SkListView::onStart(bool checked)
{
    qDebug() << "onStart Client\n";
}

void SkListView::onStop(bool checked)
{
    qDebug() << "onStop Client\n";
}

void SkListView::onDelete(bool checked)
{
    qDebug() << "onDelete Client\n";
}

// void SkListView::onRefresh(bool checked)
// {
//     qDebug() << "onRefresh Client\n";
// }

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
    // m_refresh->setText(tr("Refresh Client"));
    addAction(m_new);
    addAction(m_start);
    addAction(m_stop);
    addAction(m_delete);
    // addAction(m_refresh);
}
