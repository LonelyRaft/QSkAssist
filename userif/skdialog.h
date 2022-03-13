
#ifndef Q_SOCKET_ASSISTANT_DIALOG
#define Q_SOCKET_ASSISTANT_DIALOG

#include <qcombobox.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qdialog.h>
#include <qpushbutton.h>
#include <qgridlayout.h>

class SkDlgClient : public QDialog
{
public:
    SkDlgClient(QWidget *parent = 0);
    ~SkDlgClient();

private:
    QLabel *m_labName;
    QLabel *m_labType;
    QLabel *m_labHost;
    QLabel *m_labPort1;
    QLabel *m_labPort2;
    QComboBox *m_type; // 协议类型
    QLineEdit *m_name;
    QLineEdit *m_host;   // 目标主机
    QLineEdit *m_port1;  // 目标端口
    QLineEdit *m_port2;  // 本地端口
    QPushButton *m_rand; // 本地端口随机
    QPushButton *m_create;
    QPushButton *m_clear;
    QGridLayout *m_layout;
    void initUserIF(void);
};

class SkDlgServer : public QDialog
{
public:
    SkDlgServer(QWidget *parent = 0);
    ~SkDlgServer();

private:
    QLabel *m_labName;
    QLabel *m_labType;
    QLabel *m_labHost;
    QLabel *m_labPort;
    QComboBox *m_type; // 协议类型
    QLineEdit *m_name;
    QLineEdit *m_host; // 选网卡
    QLineEdit *m_port; // 选端口
    QPushButton *m_create;
    QPushButton *m_clear;
    QGridLayout *m_layout;
    void initUserIF(void);
};

#endif // Q_SOCKET_ASSISTANT_DIALOG
