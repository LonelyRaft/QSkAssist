
#ifndef Q_SOCKET_ASSISTANT_VIEW
#define Q_SOCKET_ASSISTANT_VIEW

#include <qmainwindow.h>
#include <qgridlayout.h>
#include <qstatusbar.h>
#include "sktree.h"

class SkMainWindow : public QMainWindow
{
public:
    SkMainWindow(QWidget *parent = 0);
    ~SkMainWindow();

private:
    QStatusBar *m_status;
    SkTreeView *m_tree;
    QGridLayout *m_layout;
    QWidget *m_content;
    void initUserIF(void);
};

#endif // Q_SOCKET_ASSISTANT_VIEW
