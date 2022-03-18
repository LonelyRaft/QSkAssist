
#include <qthread.h>
#include "sktest.h"

SkTest::SkTest(QObject *parent) : QObject(parent)
{
    i = 0;
}

SkTest::~SkTest()
{
}

void SkTest::test1(bool checked)
{
    i++;
    QThread::sleep(5);
    text = QString("%1").arg(i);
    emit test1ok(text);
}

void SkTest::test2(bool checked)
{
    i++;
    QThread::sleep(5);
    text = QString("%1").arg(i);
    emit test2ok(text);
}

void SkTest::test3(bool checked)
{
    i++;
    QThread::sleep(5);
    text = QString("%1").arg(i);
    emit test3ok(text);
}
