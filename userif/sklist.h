
#ifndef Q_SOCKET_ASSISTANT_LIST
#define Q_SOCKET_ASSISTANT_LIST

#include <qtableview.h>
#include <qheaderview.h>
#include <qstandarditemmodel.h>
#include <qmenu.h>
#include <qaction.h>

class SkListView : public QTableView
{
public:
    SkListView(QWidget *parent = 0);
    ~SkListView();
public slots:
    void onCtxMenu(const QPoint &pos);
    void onNew(bool);
    void onStart(bool);
    void onStop(bool);
    void onDelete(bool);
    // void onRefresh(bool);

private:
    QHeaderView *m_header;
    QStandardItemModel *m_model;
    void initUserIF(void);
};

class SkListMenu : public QMenu
{
public:
    SkListMenu(QWidget *parent = 0);
    ~SkListMenu();

private:
    QAction *m_acts;
    QAction *m_new;
    QAction *m_start;
    QAction *m_stop;
    QAction *m_delete;
    // QAction *m_refresh;
    friend class SkListView;
    void initUserIF(void);
};

#endif // Q_SOCKET_ASSISTANT_LIST
