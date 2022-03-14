
#include <qdebug.h>
#include "sktree.h"
#include "skdialog.h"
#include "skconfig.h"

SkServerTree::SkServerTree(QWidget *parent) : QTreeView(parent)
{
    m_model = new QStandardItemModel(this);
    initUserIF();
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &SkServerTree::customContextMenuRequested,
            this, &SkServerTree::onCtxMenu);
}

SkServerTree::~SkServerTree()
{
    delete m_model;
}

void SkServerTree::initUserIF(void)
{
    m_model->setHorizontalHeaderLabels(QStringList(QString(tr("Servers"))));
    setModel(m_model);
}

void SkServerTree::onCtxMenu(const QPoint &pos)
{
    SkServerMenu menu;
    connect(menu.m_new, &QAction::triggered,
            this, &SkServerTree::onNew);
    connect(menu.m_start, &QAction::triggered,
            this, &SkServerTree::onStart);
    connect(menu.m_stop, &QAction::triggered,
            this, &SkServerTree::onStop);
    connect(menu.m_delete, &QAction::triggered,
            this, &SkServerTree::onDelete);
    // connect(menu.m_refresh, &QAction::triggered,
    // this, &SkServerTree::onRefresh);
    menu.exec(QCursor::pos());
}

void SkServerTree::onNew(bool checked)
{
    qDebug() << "onNew Server\n";
    SkDlgServer server;
    ServerConfig config;
    if (server.exec() == QDialog::Accepted)
    {
        server.getServerConfig(config);
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
    qDebug() << "onDelete Server\n";
}

// void SkServerTree::onRefresh(bool checked)
// {
//     qDebug() << "onRefresh Server\n";
// }

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

SkClientTree::SkClientTree(QWidget *parent) : QTreeView(parent)
{
    m_model = new QStandardItemModel(this);
    initUserIF();
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &SkClientTree::customContextMenuRequested,
            this, &SkClientTree::onCtxMenu);
}

SkClientTree::~SkClientTree()
{
    delete m_model;
}

void SkClientTree::initUserIF(void)
{
    m_model->setHorizontalHeaderLabels(QStringList(QString(tr("Clients"))));
    setModel(m_model);
}

void SkClientTree::onCtxMenu(const QPoint &pos)
{
    SkClientMenu menu;
    connect(menu.m_new, &QAction::triggered,
            this, &SkClientTree::onNew);
    connect(menu.m_start, &QAction::triggered,
            this, &SkClientTree::onStart);
    connect(menu.m_stop, &QAction::triggered,
            this, &SkClientTree::onStop);
    connect(menu.m_delete, &QAction::triggered,
            this, &SkClientTree::onDelete);
    // connect(menu.m_refresh, &QAction::triggered,
    // this, &SkClientTree::onRefresh);
    menu.exec(QCursor::pos());
}

void SkClientTree::onNew(bool checked)
{
    qDebug() << "onNew Client\n";
    SkDlgClient client;
    ClientConfig config;
    if (client.exec() == QDialog::Accepted)
    {
        client.getClientConfig(config);
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
    qDebug() << "onDelete Client\n";
}

// void SkClientTree::onRefresh(bool checked)
// {
//     qDebug() << "onRefresh Client\n";
// }

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
