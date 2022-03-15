
#ifndef Q_SOCKET_ASSISTANT_DIALOG
#define Q_SOCKET_ASSISTANT_DIALOG

#include <qcombobox.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qdialog.h>
#include <qpushbutton.h>
#include <qgridlayout.h>
#include <qstring.h>
#include "skconfig.h"

class SkDlgConfig : public QDialog
{
public:
    SkDlgConfig(QWidget *parent = 0);
    ~SkDlgConfig();
    int getSocketConfig(SkConfig *);
    QComboBox *m_type;
    QLineEdit *m_edtName;

public slots:
    void clearData(void);
    void randPort(void);

private:
    QLabel *m_labType;
    QLabel *m_labName;
    QLabel *m_labHostLocal;
    QLabel *m_labPortLocal;
    QLabel *m_labHostTarget;
    QLabel *m_labPortTarget;
    QLineEdit *m_edtHostLocal;
    QLineEdit *m_edtPortLocal;
    QLineEdit *m_edtHostTarget;
    QLineEdit *m_edtPortTarget;
    QPushButton *m_btnOkay;
    QPushButton *m_btnClear;
    QPushButton *m_btnRand;
    QGridLayout *m_layout;
    void initUserIF(void);
};

#endif // Q_SOCKET_ASSISTANT_DIALOG
