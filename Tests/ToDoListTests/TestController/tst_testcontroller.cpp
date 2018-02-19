#include <QString>
#include <QtTest>
#include "/home/percrosser/QtProjects/ToDoList/controller.h"
#include "/home/percrosser/QtProjects/ToDoList/controller.cpp"
#include "/home/percrosser/QtProjects/ToDoList/todolist.cpp"

class TestController : public QObject
{
    Q_OBJECT

public:
    TestController();

private Q_SLOTS:
    void testWriteClear();
    void testSearch();

};

TestController::TestController()
{
}

void TestController::testWriteClear()
{
    ToDoList *l1=new ToDoList;
    Controller *c=new Controller(l1);
    c->write("text",QDate::currentDate(),false);
    QVERIFY2(l1->getElements()==1, "write doesn't work!");
    c->clear();
    QVERIFY2(l1->getElements()==0,"clear doesn't work!");
}

void TestController::testSearch(){
    ToDoList *l2=new ToDoList;
    Controller *c=new Controller(l2);
    c->write("to be found",QDate::currentDate(),false);
    QVERIFY2(c->search(QDate::currentDate()).count()==1,"search doesn't work proprely!");
    QDate WDate=QDate::fromString("23.04.1997","dd.MM.yyyy");
    QVERIFY2(c->search(WDate).count()==0,"search doesn't work proprely!");
}



QTEST_APPLESS_MAIN(TestController)

#include "tst_testcontroller.moc"
