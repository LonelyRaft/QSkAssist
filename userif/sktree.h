
#ifndef Q_SOCKET_ASSISTANT_TREE
#define Q_SOCKET_ASSISTANT_TREE

#include <qtreeview.h>
#include <qstandarditemmodel.h>
#include <qmenu.h>
#include <qaction.h>
#include "skconfig.h"

/***************************************
 * 服务器链接树
 * *************************************/
class SkServerTree : public QTreeView
{
#define SERVER_ROLE 0x102
    Q_OBJECT
public:
    SkServerTree(QWidget *parent = 0);
    ~SkServerTree();
    // 删除指定配置
    inline void delRow(int idx)
    {
        m_model.removeRow(idx);
    }
    // 新增配置
    void newRow(SkConfig *skConfig);
signals:
    // 请求新建服务器信号
    void newServer(SkConfig *);
    // 请求启动服务器信号
    void startServer(SkConfig *);
    // 请求停止服务器信号
    void stopServer(SkConfig *);
    // 请求删除服务器信号
    void delServer(SkConfig *);

public slots:
    // 弹出右键菜单
    void onCtxMenu(const QPoint &);
    // 发射请求新建服务器信号
    void onNew(bool);
    // 发射请求启动服务器信号
    void onStart(bool);
    // 发射请求停止服务器信号
    void onStop(bool);
    // 发射请求删除服务器信号
    void onDelete(bool);

private:
    // 数据模型
    QStandardItemModel m_model;
    void initUserIF(void);
};

/**************************************
 * 客户端链接树
 * ************************************/
class SkClientTree : public QTreeView
{
#define CLIENT_ROLE 0x101
    Q_OBJECT
public:
    SkClientTree(QWidget *parent = 0);
    ~SkClientTree();
    // 删除指定配置
    inline void delRow(int idx)
    {
        m_model.removeRow(idx);
    }
    // 新增配置
    void newRow(SkConfig *skConfig);
signals:
    // 请求新建客户端链接信号
    void newClient(SkConfig *);
    // 请求启动客户端信号
    void startClient(SkConfig *);
    // 请求停止客户端信号
    void stopClient(SkConfig *);
    // 请求删除客户端信号
    void delClient(SkConfig *);

public slots:
    // 弹出右键菜单
    void onCtxMenu(const QPoint &);
    // 发射请求新建客户端链接信号
    void onNew(bool);
    // 发射请求启动客户端链接信号
    void onStart(bool);
    // 发射请求停止客户端信号
    void onStop(bool);
    // 发射请求删除客户端信号
    void onDelete(bool);

private:
    // 数据模型
    QStandardItemModel m_model;
    void initUserIF(void);
};

#endif // Q_SOCKET_ASSISTANT_TREE
