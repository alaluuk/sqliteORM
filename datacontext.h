#ifndef DATACONTEXT_H
#define DATACONTEXT_H

#include<QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "person.h"

class DataContext
{
public:
    DataContext();
    ~DataContext();
    void SetObjectList();
    QList<Person> GetObjectList() const;
    Person GetOnePerson(int x);
    QString AddPerson(Person &obj);
    QString UpdatePerson(Person &updateObj, int x);
    QString DeletePerson(int x);

private:
    QSqlDatabase db;
    QList<Person> objectList;
};

#endif // DATACONTEXT_H
