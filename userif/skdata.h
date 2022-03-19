
#ifndef Q_SOCKET_ASSISTANT_DATA
#define Q_SOCKET_ASSISTANT_DATA

#include <qthread.h>
#include <qsplitter.h>
#include <qlabel.h>
#include <qcheckbox.h>
#include <qtoolbar.h>
#include <qtextedit.h>
#include <qboxlayout.h>
#include <qgridlayout.h>
#include <qtoolbutton.h>
#include <qpushbutton.h>
#include "sktest.h"
#include "skconfig.h"

class SkMainWindow;
class SkData : public QWidget
{
public:
    SkData(SkConfig *config = 0, QWidget *parent = 0);
    ~SkData();

private:
    QThread *m_worker;
    SkConfig *m_config;
    SkTest *m_test;
    QLabel *m_label1;
    QLabel *m_label2;
    QCheckBox *m_hex1;
    QCheckBox *m_hex2;
    QToolButton *m_clear1;
    QToolButton *m_clear2;
    QToolBar *m_tools1;
    QToolBar *m_tools2;
    QTextEdit *m_data1;
    QTextEdit *m_data2;
    QBoxLayout *m_box1;
    QBoxLayout *m_box2;
    QWidget *m_recv;
    QWidget *m_send;
    QSplitter *m_splitter;
    QGridLayout *m_grid;
    friend class SkMainWindow;
    void initUserIF(void);
};

#endif // Q_SOCKET_ASSISTANT_DATA
