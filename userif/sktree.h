
#ifndef Q_SOCKET_ASSISTANT_TREE
#define Q_SOCKET_ASSISTANT_TREE

#include <qtreeview.h>
#include <qmenu.h>
#include <qaction.h>

class SkTreeView : public QTreeView
{
public:
    SkTreeView(QWidget *parent = 0);
    ~SkTreeView();
public slots:
    void onCtxMenu(const QPoint &pos);

private:
};

class SkTreeMenu : public QMenu
{
public:
    SkTreeMenu(QWidget *parent = 0);
    ~SkTreeMenu();

private:
    QAction *m_acts;
    QAction *m_new;
    QAction *m_start;
    QAction *m_stop;
    QAction *m_delete;
    // QAction *m_refresh;
    friend class SkTreeView;
    void initUserIF(void);
};

#endif // Q_SOCKET_ASSISTANT_TREE
