
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
#include "skconfig.h"
#include "tcpclient.h"
#include "tcpserver.h"
#include "udpsocket.h"

class SkMainWindow;
class SkData : public QWidget
{
public:
    SkData(QWidget *parent = 0);
    ~SkData();

protected:
    QThread m_worker;
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

class SkDataTcpServer : public SkData
{
public:
    SkDataTcpServer(SkConfig *config = 0, QWidget *parent = 0);
    ~SkDataTcpServer();
    inline void startListen(void)
    {
        m_server.startListen();
    }

private:
    SkTcpServer m_server;
};

class SkDataTcpCleint : public SkData
{
public:
    SkDataTcpCleint(SkConfig *config = 0, QWidget *parent = 0);
    ~SkDataTcpCleint();

private:
};

#endif // Q_SOCKET_ASSISTANT_DATA
