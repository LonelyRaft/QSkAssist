
#ifndef Q_SOCKET_ASSISTANT_TREE
#define Q_SOCKET_ASSISTANT_TREE

#include <qtreeview.h>
#include <qstandarditemmodel.h>
#include <qmenu.h>
#include <qaction.h>
#include "skconfig.h"

/**************************************
 * 服务器链接树
**************************************/
class SkServerTree : public QTreeView
{
#define SERVER_ROLE 0x102
    Q_OBJECT
public:
    SkServerTree(QWidget *parent = 0);
    ~SkServerTree();

signals:
    void addServer(SkConfig *);
    void startServer(SkConfig *);
    void stopServer(SkConfig *);
    void removeServer(SkConfig *);

public slots:
    void onCtxMenu(const QPoint &);
    void onNew(bool);
    void onStart(bool);
    void onStop(bool);
    void onDelete(bool);

private:
    QStandardItemModel m_model;
    void initUserIF(void);
};

/**************************************
 * 客户端链接树
**************************************/
class SkClientTree : public QTreeView
{
#define CLIENT_ROLE 0x101
    Q_OBJECT
public:
    SkClientTree(QWidget *parent = 0);
    ~SkClientTree();

signals:
    void addClient(SkConfig *);
    void startClient(SkConfig *);
    void stopClient(SkConfig *);
    void removeClient(SkConfig *);

public slots:
    void onCtxMenu(const QPoint &);
    void onNew(bool);
    void onStart(bool);
    void onStop(bool);
    void onDelete(bool);

private:
    QStandardItemModel m_model;
    void initUserIF(void);
};

#endif // Q_SOCKET_ASSISTANT_TREE
