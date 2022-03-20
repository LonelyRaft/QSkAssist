
#include <qdebug.h>
#include "sktree.h"
#include "skmenu.h"
#include "skdialog.h"

// 创建服务端树
SkServerTree::SkServerTree(QWidget *parent) : QTreeView(parent)
{
        initUserIF();
        setContextMenuPolicy(Qt::CustomContextMenu);
        connect(this, &SkServerTree::customContextMenuRequested,
                this, &SkServerTree::onCtxMenu);
}

// 析构服务端树
SkServerTree::~SkServerTree()
{
}

// 初始化 UI
void SkServerTree::initUserIF(void)
{
        m_model.setHorizontalHeaderLabels(
            QStringList(QString(tr("Servers"))));
        setModel(&m_model);
}

// 向树中添加新行
void SkClientTree::newRow(SkConfig *skConfig)
{
        QStandardItem *item =
            new QStandardItem(skConfig->m_name);
        item->setData(QVariant::fromValue(skConfig), SERVER_ROLE);
        m_model.appendRow(item);
}

// 弹出右键菜单
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

// 发射请求新建服务器信号
void SkServerTree::onNew(bool checked)
{
        SkDlgServer dlgServer;
        dlgServer.move(QCursor::pos());
        if (dlgServer.exec() == QDialog::Accepted)
        {
                SkConfig *skConfig = new ServerConfig;
                if (!dlgServer.getSocketConfig(skConfig))
                {
                        QStandardItem *item = new QStandardItem(skConfig->m_name);
                        item->setData(QVariant::fromValue(skConfig), SERVER_ROLE);
                        // m_model.appendRow(item);
                        emit newServer(skConfig);
                }
        }
}

// 发射请求启动服务器信号
void SkServerTree::onStart(bool checked)
{
        QModelIndex index = currentIndex();
        if (index.isValid())
        {
                SkConfig *skConfig = index.data(SERVER_ROLE).value<SkConfig *>();
                emit startServer(skConfig);
        }
}

// 发射请求停止服务器信号
void SkServerTree::onStop(bool checked)
{
        QModelIndex index = currentIndex();
        if (index.isValid())
        {
                SkConfig *skConfig = index.data(SERVER_ROLE).value<SkConfig *>();
                emit stopServer(skConfig);
        }
}

// 发射请求删除服务器信号
void SkServerTree::onDelete(bool checked)
{
        QModelIndex index = currentIndex();
        if (index.isValid())
        {
                SkConfig *skConfig = index.data(SERVER_ROLE).value<SkConfig *>();
                // m_model.removeRow(index.row());
                emit delServer(skConfig);
        }
}

// 创建客户端树
SkClientTree::SkClientTree(QWidget *parent) : QTreeView(parent)
{
        initUserIF();
        setContextMenuPolicy(Qt::CustomContextMenu);
        connect(this, &SkClientTree::customContextMenuRequested,
                this, &SkClientTree::onCtxMenu);
}

// 析构客户端树
SkClientTree::~SkClientTree()
{
}

// 初始化 UI
void SkClientTree::initUserIF(void)
{
        m_model.setHorizontalHeaderLabels(QStringList(QString(tr("Clients"))));
        setModel(&m_model);
}

// 向树中添加新行
void SkClientTree::newRow(SkConfig *skConfig)
{
        QStandardItem *item =
            new QStandardItem(skConfig->m_name);
        item->setData(QVariant::fromValue(skConfig), CLIENT_ROLE);
        m_model.appendRow(item);
}

// 弹出右键菜单
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

// 发射请求新建客户端链接信号
void SkClientTree::onNew(bool checked)
{
        SkDlgClient dlgClient;
        dlgClient.move(QCursor::pos());
        if (dlgClient.exec() == QDialog::Accepted)
        {
                SkConfig *skConfig = new ClientConfig;
                if (!dlgClient.getSocketConfig(skConfig))
                {
                        QStandardItem *item = new QStandardItem(skConfig->m_name);
                        item->setData(QVariant::fromValue(skConfig), CLIENT_ROLE);
                        // m_model.appendRow(item);
                        emit newClient(skConfig);
                }
        }
}

// 发射请求启动客户端链接信号
void SkClientTree::onStart(bool checked)
{
        QModelIndex index = currentIndex();
        if (index.isValid())
        {
                SkConfig *skConfig = index.data(CLIENT_ROLE).value<SkConfig *>();
                emit startClient(skConfig);
        }
}

// 发射请求停止客户端信号
void SkClientTree::onStop(bool checked)
{
        QModelIndex index = currentIndex();
        if (index.isValid())
        {
                SkConfig *skConfig = index.data(CLIENT_ROLE).value<SkConfig *>();
                emit startClient(skConfig);
        }
}

// 发射请求删除客户端信号
void SkClientTree::onDelete(bool checked)
{
        QModelIndex index = currentIndex();
        if (index.isValid())
        {
                SkConfig *skConfig = index.data(CLIENT_ROLE).value<SkConfig *>();
                // m_model.removeRow(index.row());
                emit delClient(skConfig);
        }
}
