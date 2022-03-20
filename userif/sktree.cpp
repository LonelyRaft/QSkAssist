
#include <qdebug.h>
#include "sktree.h"
#include "skmenu.h"
#include "skdialog.h"

SkServerTree::SkServerTree(QWidget *parent) : QTreeView(parent)
{
    initUserIF();
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &SkServerTree::customContextMenuRequested,
            this, &SkServerTree::onCtxMenu);
}

SkServerTree::~SkServerTree()
{
}

void SkServerTree::initUserIF(void)
{
    m_model.setHorizontalHeaderLabels(
        QStringList(QString(tr("Servers"))));
    setModel(&m_model);
}

void SkServerTree::onCtxMenu(const QPoint &pos)
{
    SkServerMenu menu;
    connect(&menu.m_new, &QAction::triggered,
            this, &SkServerTree::onNew);
    connect(&menu.m_start, &QAction::triggered,
            this, &SkServerTree::onStart);
    connect(&menu.m_stop, &QAction::triggered,
            this, &SkServerTree::onStop);
    connect(&menu.m_delete, &QAction::triggered,
            this, &SkServerTree::onDelete);
    menu.exec(QCursor::pos());
}

void SkServerTree::onNew(bool checked)
{
}

void SkServerTree::onStart(bool checked)
{
}

void SkServerTree::onStop(bool checked)
{
}

void SkServerTree::onDelete(bool checked)
{
}

SkClientTree::SkClientTree(QWidget *parent) : QTreeView(parent)
{
    initUserIF();
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &SkClientTree::customContextMenuRequested,
            this, &SkClientTree::onCtxMenu);
}

SkClientTree::~SkClientTree()
{
}

void SkClientTree::initUserIF(void)
{
    m_model.setHorizontalHeaderLabels(QStringList(QString(tr("Clients"))));
    setModel(&m_model);
}

void SkClientTree::onCtxMenu(const QPoint &pos)
{
    SkClientMenu menu;
    connect(&menu.m_new, &QAction::triggered,
            this, &SkClientTree::onNew);
    connect(&menu.m_start, &QAction::triggered,
            this, &SkClientTree::onStart);
    connect(&menu.m_stop, &QAction::triggered,
            this, &SkClientTree::onStop);
    connect(&menu.m_delete, &QAction::triggered,
            this, &SkClientTree::onDelete);
    menu.exec(QCursor::pos());
}

void SkClientTree::onNew(bool checked)
{
}

void SkClientTree::onStart(bool checked)
{
}

void SkClientTree::onStop(bool checked)
{
}

void SkClientTree::onDelete(bool checked)
{
}
