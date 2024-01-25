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
    void SetPersonContext();
    QList<Person> getObjectList() const;
    Person getOnePerson(int x);

private:
    QSqlDatabase db;
    QList<Person> objectList;
};

#endif // DATACONTEXT_H
