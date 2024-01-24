#include "datacontext.h"

DataContext::DataContext() {
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString myFolder = "C:/codes/qt_projects/sqliteORM";
    db.setDatabaseName(myFolder + "/database/mydb.db");
    db.open();
}

void DataContext::SetPersonContext()
{
    if (!db.open()) {
        qDebug() << "Error: Unable to open the database";

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

    db.close();
}
