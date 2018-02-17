#include <QString>
#include <QtTest>
#include "/home/percrosser/QtProjects/ToDoList/activity.h"

class TestActivityTest : public QObject
{
    Q_OBJECT

public:
    TestActivityTest();

private Q_SLOTS:
    void testConstructor();
    void testSetTask();
    void testSetDone();
};

TestActivityTest::TestActivityTest()
{
}

void TestActivityTest::testConstructor()
{
    QString testString="test";
    QDate testDate=QDate::currentDate();
    bool testDone=true;
    Activity a1(testString,testDate,testDone);
    QVERIFY2(a1.getTask()==testString, "the name of the task doesn't match");
    QVERIFY2(a1.getDate()==testDate,"date doesn't match");
    QVERIFY2(a1.getDone()==testDone,"checkstate doesn't match");
}

void TestActivityTest::testSetTask(){
    Activity a2("a",QDate::currentDate(),false);
    QString testString="test";
    a2.setTask(testString);
    QVERIFY2(a2.getTask()==testString,"setTask doesn't work!");
}

void TestActivityTest::testSetDone(){
    Activity a3("a",QDate::currentDate(),false);
    a3.setDone(true);
    QVERIFY2(a3.getDone()==true,"setDone doesn't work!");
}

QTEST_APPLESS_MAIN(TestActivityTest)

#include "tst_testactivitytest.moc"
