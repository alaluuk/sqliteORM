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
  DataContext objectContext;
  objectContext.SetPersonContext();
  cout << "Valittu id :"<<chosen<<":"<<endl;
  cout <<"fname="<<objectContext.getOnePerson(chosen).getFname().toStdString()
       <<" lname="<<objectContext.getOnePerson(chosen).getLname().toStdString()
       << endl;
  cout<<endl<<"Kaikki henkilot"<<endl;
  foreach (const Person &obj, objectContext.getObjectList()) {
    cout << "ID:" << obj.getId()
         << " Firstname:" << obj.getFname().toStdString()
         << " Lastname:" << obj.getLname().toStdString() << endl;
  }

  return a.exec();
}
