
#ifndef Q_SOCKET_ASSISTANT_DIALOG
#define Q_SOCKET_ASSISTANT_DIALOG

#include <qcombobox.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qdialog.h>
#include <qpushbutton.h>
#include <qgridlayout.h>
#include "skconfig.h"

class SkDlgConfig : public QDialog
{
public:
    SkDlgConfig(QWidget *parent = 0);
    ~SkDlgConfig();
    virtual int getSocketConfig(SkConfig *);

public slots:
    virtual void clearData(void);
    virtual void randPort(void);

protected:
    QLabel m_labType;
    QLabel m_labName;
    QLabel m_labHost;
    QLabel m_labPort;
    QLineEdit m_edtName;
    QComboBox m_type;
    QLineEdit m_edtHost;
    QLineEdit m_edtPort;
    QPushButton m_btnOkay;
    QPushButton m_btnClear;
    QPushButton m_btnRand;
    QGridLayout m_layout;
};

class SkDlgClient : public SkDlgConfig
{
public:
    SkDlgClient(QWidget *parent = 0);
    ~SkDlgClient();
    virtual int getSocketConfig(SkConfig *);

public slots:
    virtual void clearData(void);

private:
    QLabel m_labHostLocal;
    QLabel m_labPortLocal;
    QLineEdit m_edtHostLocal;
    QLineEdit m_edtPortLocal;
};

class SkDlgServer : public SkDlgConfig
{
public:
    SkDlgServer(QWidget *parent = 0);
    ~SkDlgServer();
    virtual int getSocketConfig(SkConfig *);
};

#endif // Q_SOCKET_ASSISTANT_DIALOG
