#ifndef TEST_MAINWINDOW_H
#define TEST_MAINWINDOW_H

#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QtCore/QCoreApplication>

namespace UnitTests
{
class MainWindowTests: public QObject
{
    Q_OBJECT

public:
    MainWindowTests();

private Q_SLOTS:
    void Create();
};
}

#endif