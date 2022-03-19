
#ifndef Q_SOCKET_ASSISTANT_TREE
#define Q_SOCKET_ASSISTANT_TREE

#include <qtreeview.h>
#include <qstandarditemmodel.h>
#include <qmenu.h>
#include <qaction.h>
#include "skconfig.h"

class SkServerTree : public QTreeView
{
#define SERVER_ROLE 0x102
    Q_OBJECT
public:
    SkServerTree(QWidget *parent = 0);
    ~SkServerTree();

signals:
    void addServer(SkConfig *);
    void removeServer(SkConfig *);

public slots:
    void onCtxMenu(const QPoint &);
    void onNew(bool);
    void onStart(bool);
    void onStop(bool);
    void onDelete(bool);
    // void onRefresh(bool);

private:
    QStandardItemModel *m_model;
    void initUserIF(void);
};

class SkClientTree : public QTreeView
{
#define CLIENT_ROLE 0x101
    Q_OBJECT
public:
    SkClientTree(QWidget *parent = 0);
    ~SkClientTree();

signals:
    void addClient(SkConfig *);
    void removeClient(SkConfig *);

public slots:
    void onCtxMenu(const QPoint &);
    void onNew(bool);
    void onStart(bool);
    void onStop(bool);
    void onDelete(bool);
    // void onRefresh(bool);

private:
    QStandardItemModel *m_model;
    void initUserIF(void);
};

#endif // Q_SOCKET_ASSISTANT_TREE
