#include "datacontext.h"

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

        DataContext objectContext;
        objectContext.SetPersonContext();
        cout<<"Eka :"<<objectContext.getOnePerson(9).getFname().toStdString()<<endl;

        foreach (const Person &obj, objectContext.getObjectList()) {
            cout << "ID:" << obj.getId() << " Firstname:" << obj.getFname().toStdString()<<" Lastname:"<<obj.getLname().toStdString()<<endl;
        }


        return a.exec();


}
