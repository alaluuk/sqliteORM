#include "person.h"

#include <QCoreApplication>
#include<QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString myFolder = "C:/codes/qt_projects/sqliteORM";
    db.setDatabaseName(myFolder + "/database/mydb.db");
    db.open();

    if (!db.open()) {
        qDebug() << "Error: Unable to open the database";
        return -1;
    }

    QList<Person> objectList;

    QSqlQuery query("SELECT * FROM person");

    while (query.next()) {
        int id = query.value(0).toInt();
        QString fname = query.value(1).toString();
        QString lname = query.value(2).toString();

        Person obj(id, fname, lname);
        objectList.append(obj);
    }

    foreach (const Person &obj, objectList) {
        cout << "ID:" << obj.getId() << " Firstname:" << obj.getFname().toStdString()<<" Lastname:"<<obj.getLname().toStdString()<<endl;
    }

    db.close();


    return a.exec();
}
