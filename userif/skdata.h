
#ifndef Q_SOCKET_ASSISTANT_DATA
#define Q_SOCKET_ASSISTANT_DATA

#include <qsplitter.h>
#include <qlabel.h>
#include <qcheckbox.h>
#include <qtoolbar.h>
#include <qtextedit.h>
#include <qboxlayout.h>
#include <qtoolbutton.h>
#include <qpushbutton.h>

class SkMainWindow;
class SkData : public QWidget
{
public:
    SkData(QWidget *parent = 0);
    ~SkData();

private:
    QLabel *m_label1;
    QLabel *m_label2;
    QCheckBox *m_hex1;
    QCheckBox *m_hex2;
    QToolBar *m_tools1;
    QToolBar *m_tools2;
    QTextEdit *m_data1;
    QTextEdit *m_data2;
    QBoxLayout *m_box1;
    QBoxLayout *m_box2;
    QWidget *m_recv;
    QWidget *m_send;
    QSplitter *m_splitter;
    friend class SkMainWindow;
    void initUserIF(void);
};

#endif // Q_SOCKET_ASSISTANT_DATA
