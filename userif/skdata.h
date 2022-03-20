
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
#include <qtcpsocket.h>
#include <qudpsocket.h>
#include "skconfig.h"

class SkMainWindow;
class SkData : public QWidget
{
public:
    SkData(void *index, QWidget *parent = 0);
    ~SkData();

protected:
    // 后台线程
    QThread m_worker;
    // 数据区索引
    void *m_index;
    QLabel *m_labelSend;
    QLabel *m_labelRecv;
    QCheckBox *m_hexSend;
    QCheckBox *m_hexRecv;
    QToolButton *m_clearSend;
    QToolButton *m_clearRecv;
    QToolButton *m_texSend;
    QToolButton *m_texStop;
    QToolButton *m_texSave;
    QToolBar *m_toolSend;
    QToolBar *m_toolRecv;
    QTextEdit *m_dataSend;
    QTextEdit *m_dataRecv;
    QBoxLayout *m_boxSend;
    QBoxLayout *m_boxRecv;
    QWidget *m_recv;
    QWidget *m_send;
    QSplitter m_splitter;
    QGridLayout m_grid;
    friend class SkMainWindow;
    void initUserIF(void);
};

class SkDataTcp : public SkData
{
public:
    SkDataTcp(void *index, QWidget *parent = 0);
    ~SkDataTcp();

private:
    QTcpSocket *m_client;
};

class SkDataUdp : public SkData
{
public:
    SkDataUdp(void *index, QWidget *parent = 0);
    ~SkDataUdp();

private:
    QUdpSocket *m_client;
};

#endif // Q_SOCKET_ASSISTANT_DATA
