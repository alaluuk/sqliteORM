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
  persons.SetPersonContext();
  cout << "Valittu id :"<<chosen<<":"<<endl;
  cout <<"fname="<<persons.getOnePerson(chosen).getFname().toStdString()
       <<" lname="<<persons.getOnePerson(chosen).getLname().toStdString()
       << endl;
  cout<<endl<<"Kaikki henkilot"<<endl;
  foreach (const Person &obj, persons.getObjectList()) {
    cout << "ID:" << obj.getId()
         << " Firstname:" << obj.getFname().toStdString()
         << " Lastname:" << obj.getLname().toStdString() << endl;
  }

  return a.exec();
}
