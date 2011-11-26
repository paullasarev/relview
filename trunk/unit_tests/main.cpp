#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QtCore/QCoreApplication>

#include "test_mainwindow.h"

int main(int argc, char *argv[]) 
{ 
    int result = 0;
    QCoreApplication app(argc, argv); 

    UnitTests::MainWindowTests test1;
    result += QTest::qExec(&test1, argc, argv);
    
    return result;
}

//QTEST_MAIN(UnitTests::MainWindowTest);
//#include "test_mainwindow.moc"
