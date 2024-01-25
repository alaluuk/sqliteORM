#include "datacontext.h"

DataContext::DataContext() {
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString myFolder = "C:/codes/qt_projects/sqliteORM";
    db.setDatabaseName(myFolder + "/database/mydb.db");
    db.open();
    if (!db.open()) {
        qDebug() << "Error: Unable to open the database";

    }
}

DataContext::~DataContext()
{
    QString myConnection = db.connectionName();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(myConnection);
}

void DataContext::SetObjectList()
{
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

QList<Person> DataContext::GetObjectList() const
{
    return objectList;
}

Person DataContext::GetOnePerson(int x)
{
    foreach (const Person &obj, objectList) {
        if(obj.getId()==x) {
            return obj;
        }
    }
    return Person(-1, "No fname","No lname");
}

QString DataContext::AddPerson(Person &obj)
{
    QSqlQuery query;
    query.prepare(
        "INSERT INTO person(firstname,lastname) VALUES(:fn, :ln)");
    query.bindValue(":fn", obj.getFname());
    query.bindValue(":ln", obj.getLname());
    bool res = query.exec();
    // qDebug()<<res;
    if (res) {
        return "added person: "+obj.getFname()+" "+obj.getLname();
    } else {
        return "something went wrong";
    }
}

