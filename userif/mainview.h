
#ifndef Q_SOCKET_ASSISTANT_VIEW
#define Q_SOCKET_ASSISTANT_VIEW

#include <qmainwindow.h>
#include <qgridlayout.h>
#include <qstatusbar.h>
#include <qsplitter.h>
#include <qtabwidget.h>
#include "sktree.h"
#include "sklist.h"
#include "skdata.h"

class SkMainWindow : public QMainWindow
{
public:
    SkMainWindow(QWidget *parent = 0);
    ~SkMainWindow();

private:
    QStatusBar *m_status;
    QTabWidget *m_data;
    SkTreeView *m_server;
    SkListView *m_client;
    QSplitter *m_links;
    QGridLayout *m_layout;
    QWidget *m_content;
    void initUserIF(void);
};

#endif // Q_SOCKET_ASSISTANT_VIEW
