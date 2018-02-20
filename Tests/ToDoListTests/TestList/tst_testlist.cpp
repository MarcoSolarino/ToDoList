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
    void testSaveList();
    void testLoadList();


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

void TestList::testSaveList(){
    ToDoList ls;
    Activity *a=new Activity("test",QDate::currentDate(),false);
    ls.addActivity(a);
    ls.saveList();
            QString filename="./home/percrosser/QtProjects/build-ToDoList-Desktop_Qt_5_9_1_GCC_64bit-Debug/list.txt";
            QFile file(filename);
            QTextStream memo(&file);
            if(file.open(QIODevice::ReadOnly)){
                int count=0;
                QString line;
                while(!memo.atEnd()){
                    count++;
                    line=memo.readLine();
                }
             QVERIFY2(count==1,"saveList doesn't work!");
             QVERIFY2(line=="1,  test,  "+QDate::currentDate().toString("dd.MM.yyyy"),"saveList doesn't write in list.txt correctly!");
            }



}

void TestList::testLoadList(){
    ToDoList ll;
    Activity *a=new Activity("test",QDate::currentDate(),false);
    ll.addActivity(a);
    ll.saveList();
    ToDoList ls;
    ls.loadList();
    QVERIFY2(ls.getElements()==1,"loadList doesn't work proprely!");
    auto itr=ls.getList().begin();
    QVERIFY2((*itr)->getTask()=="test","loadlist doesn't import task correctly!");
    QVERIFY2((*itr)->getDate()==QDate::currentDate(),"loadList doesn't import date correctly!");
    QVERIFY2((*itr)->getDone()==false,"loadList doesn't import done correctly!");
    ll.deleteAll();
    ll.saveList();
    ToDoList lt;
    lt.loadList();
    QVERIFY2(lt.getElements()==0,"loadList doesn't work on an empty file!");
    ls.loadList();
    QVERIFY2(ls.getElements()==0,"loadList doesn't work when operating with an empty file and a non-empty list!");



}


QTEST_APPLESS_MAIN(TestList)

#include "tst_testlist.moc"
