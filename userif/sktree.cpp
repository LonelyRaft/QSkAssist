
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
    m_model.setHorizontalHeaderLabels(QStringList(QString(tr("Servers"))));
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
    // connect(&menu.m_refresh, &QAction::triggered,
    // this, &SkServerTree::onRefresh);
    menu.exec(QCursor::pos());
}

void SkServerTree::onNew(bool checked)
{
    SkDlgServer server;
    if (server.exec() == QDialog::Accepted)
    {
        SkConfig *config = new ServerConfig;
        if (!server.getSocketConfig(config))
        {
            QStandardItem *item = new QStandardItem(config->m_name);
            item->setData(QVariant::fromValue(config), SERVER_ROLE);
            m_model.appendRow(item);
            emit addServer(config);
        }
    }
}

void SkServerTree::onStart(bool checked)
{
    qDebug() << "onStart Server\n";
}

void SkServerTree::onStop(bool checked)
{
    qDebug() << "onStop Server\n";
}

void SkServerTree::onDelete(bool checked)
{
    QModelIndex index = currentIndex();
    if (index.isValid())
    {
        SkConfig *config = index.data(SERVER_ROLE).value<SkConfig *>();
        m_model.removeRow(index.row());
        emit removeServer(config);
    }
}

// void SkServerTree::onRefresh(bool checked)
// {
//     qDebug() << "onRefresh Server\n";
// }

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
    // connect(&menu.m_refresh, &QAction::triggered,
    // this, &SkClientTree::onRefresh);
    menu.exec(QCursor::pos());
}

void SkClientTree::onNew(bool checked)
{
    SkDlgClient client;
    if (client.exec() == QDialog::Accepted)
    {
        SkConfig *config = new ClientConfig;
        if (!client.getSocketConfig(config))
        {
            QStandardItem *item = new QStandardItem(config->m_name);
            item->setData(QVariant::fromValue(config), CLIENT_ROLE);
            m_model.appendRow(item);
            emit addClient(config);
        }
    }
}

void SkClientTree::onStart(bool checked)
{
    qDebug() << "onStart Client\n";
}

void SkClientTree::onStop(bool checked)
{
    qDebug() << "onStop Client\n";
}

void SkClientTree::onDelete(bool checked)
{
    QModelIndex index = currentIndex();
    if (index.isValid())
    {
        SkConfig *config = index.data(CLIENT_ROLE).value<SkConfig *>();
        m_model.removeRow(index.row());
        emit removeClient(config);
    }
}

// void SkClientTree::onRefresh(bool checked)
// {
//     qDebug() << "onRefresh Client\n";
// }
