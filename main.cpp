#include "datacontext.h"

#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);
  int chosen = 14;
  DataContext persons;
  persons.SetObjectList();

  cout << "Valittu id :"<<chosen<<":"<<endl;
  cout <<"fname="<<persons.GetOnePerson(chosen).getFname().toStdString()
       <<" lname="<<persons.GetOnePerson(chosen).getLname().toStdString()
       << endl;
  cout<<endl<<"Kaikki henkilot"<<endl;
  foreach (const Person &obj, persons.GetObjectList()) {
    cout << "ID:" << obj.getId()
         << " Firstname:" << obj.getFname().toStdString()
         << " Lastname:" << obj.getLname().toStdString() << endl;
  }
  Person objectAdd=Person("Matti","Mainio");
  QString res=persons.AddPerson(objectAdd);
  cout<<res.toStdString()<<endl;

  return a.exec();
}
