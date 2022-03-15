
#ifndef Q_SOCKET_ASSISTANT_MENU
#define Q_SOCKET_ASSISTANT_MENU

#include <qmenubar.h>
#include <qmenu.h>
#include <qaction.h>

class SkMainWindow;
class SkMenuBar : public QMenuBar
{
public:
    SkMenuBar(QWidget *parent = 0);
    ~SkMenuBar();

private:
    QMenu *m_file;
    QMenu *m_help;
    QMenu *m_setting;
    QAction *m_actAbout;
    QAction *m_actAboutQt;
    friend class SkMainWindow;
    void initUserIF(void);
};

class SkServerTree;
class SkServerMenu : public QMenu
{
public:
    SkServerMenu(QWidget *parent = 0);
    ~SkServerMenu();

private:
    QAction *m_acts;
    QAction *m_new;
    QAction *m_start;
    QAction *m_stop;
    QAction *m_delete;
    // QAction *m_refresh;
    friend class SkServerTree;
    void initUserIF(void);
};

class SkClientTree;
class SkClientMenu : public QMenu
{
public:
    SkClientMenu(QWidget *parent = 0);
    ~SkClientMenu();

private:
    QAction *m_acts;
    QAction *m_new;
    QAction *m_start;
    QAction *m_stop;
    QAction *m_delete;
    // QAction *m_refresh;
    friend class SkClientTree;
    void initUserIF(void);
};

#endif // Q_SOCKET_ASSISTANT_MENU
