
#ifndef Q_SOCKET_ASSISTANT_VIEW
#define Q_SOCKET_ASSISTANT_VIEW

#include <qmainwindow.h>
#include <qgridlayout.h>
#include <qtoolbar.h>
#include <qstatusbar.h>
#include <qsplitter.h>
#include <qtabwidget.h>
#include "sktree.h"
#include "skmenu.h"

/**********************************************
 * 应用主窗口
 * ********************************************/
class SkMainWindow : public QMainWindow
{
public:
    SkMainWindow(QWidget *parent = 0);
    ~SkMainWindow();

public slots:
    // 新建服务器
    void newServer(SkConfig *);
    // 启动服务器
    void startServer(SkConfig *);
    // 停止服务器
    void stopServer(SkConfig *);
    // 删除服务器
    void delServer(SkConfig *);
    // 新建客户端
    void newClient(SkConfig *);
    // 启动客户端
    void startClient(SkConfig *);
    // 停止客户端
    void stopClient(SkConfig *);
    // 删除客户端
    void delClient(SkConfig *);

private:
    // 主窗口菜单栏
    SkMenuBar *m_menu;
    // 主窗口工具栏
    QToolBar *m_tools;
    // 主窗口状态栏
    QStatusBar *m_status;
    // 主窗口数据收发区
    QTabWidget *m_data;
    // 服务器树
    SkServerTree *m_server;
    // 客户端树
    SkClientTree *m_client;
    // 主窗口分区
    QSplitter *m_links;
    // 主窗口布局（格栅布局）
    QGridLayout *m_layout;
    // 主窗口中心组件
    QWidget *m_content;
    void initUserIF(void);
};

#endif // Q_SOCKET_ASSISTANT_VIEW
