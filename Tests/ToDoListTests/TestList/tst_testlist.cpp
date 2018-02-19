#include <QString>
#include <QtTest>
#include "/home/percrosser/QtProjects/ToDoList/todolist.h"
#include "/home/percrosser/QtProjects/ToDoList/todolist.cpp"
#include <QList>


class TestList : public QObject
{
    Q_OBJECT

public:
    TestList();

private Q_SLOTS:
    void testAddRemoveAct();
    void testDeleteAll();
    void testSearch();
    void testGetList();
    void testGetElements();


};

TestList::TestList()
{
}

void TestList::testAddRemoveAct()
{
    Activity *a=new Activity("text",QDate::currentDate(),false);
    ToDoList l1;
    l1.addActivity(a);
    QVERIFY2(l1.getElements()==1,"AddActivity doesn't work proprely!");
    l1.removeActivity(a);
    QVERIFY2(l1.getElements()==0,"RemoveActivity doesn't work proprely!");
}

void TestList::testDeleteAll(){
    Activity *a=new Activity("text",QDate::currentDate(),false);
    Activity *b=new Activity("text2",QDate::currentDate(),true);
    ToDoList l2;
    l2.addActivity(a);
    l2.addActivity(b);
    l2.deleteAll();
    QVERIFY2(l2.getElements()==0,"DeleteAll doesn't work proprely!");

}

void TestList::testSearch(){
    QDate sdate=QDate::fromString("23.04.1997","dd.MM.yyyy");
    Activity *a=new Activity("to be found",sdate,true);
    ToDoList l3;
    l3.addActivity(a);
    QVERIFY2(l3.search(sdate).count()==1,"search doesn't work proprely");
}

void TestList::testGetList(){
    ToDoList l4;
    Activity *a=new Activity("tesxt",QDate::currentDate(),false);
    l4.addActivity(a);
    QVERIFY2(l4.getList().count()==l4.getElements(),"getList doesn't work proprely!");
}

void TestList::testGetElements(){
    ToDoList l5;
    Activity *a=new Activity("text",QDate::currentDate(),false);
    l5.addActivity(a);
    QVERIFY2(l5.getElements()==1,"getElements doesn't work proprely!");
}


QTEST_APPLESS_MAIN(TestList)

#include "tst_testlist.moc"
