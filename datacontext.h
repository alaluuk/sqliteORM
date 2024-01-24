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
    void SetPersonContext();
    QList<Person> getObjectList() const;

private:
    QSqlDatabase db;
    QList<Person> objectList;
};

#endif // DATACONTEXT_H
