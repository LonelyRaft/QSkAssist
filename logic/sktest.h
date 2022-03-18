
#ifndef Q_SOCKET_ASSISTANT_TEST
#define Q_SOCKET_ASSISTANT_TEST

#include <qobject.h>
#include <qstring.h>

class SkTest : public QObject
{
    Q_OBJECT
public:
    SkTest(QObject *parent = 0);
    ~SkTest();

public slots:
    void test1(bool);
    void test2(bool);
    void test3(bool);

signals:
    void test1ok(const QString&);
    void test2ok(const QString&);
    void test3ok(const QString&);

private:
    QString text;
    int i;
};

#endif // Q_SOCKET_ASSISTANT_TEST
