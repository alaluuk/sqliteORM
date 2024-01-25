#include "datacontext.h"

#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <iostream>

using namespace std;

int menu();
void allRows();
void oneRow();
void addData();
void updateData();
void deleteData();

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);
  DataContext persons;

  int choice = 1;
  while (choice != 0) {
    choice = menu();
    if (choice == 1) {
      allRows();
    } else if (choice == 2) {
      oneRow();
    } else if (choice == 3) {
      addData();
    } else if (choice == 4) {
      updateData();
    } else if (choice == 5) {
      deleteData();
    }

    else {
      cout << "Loppu" << endl;
      QCoreApplication::quit();
    }
  }
  return a.exec();
}
int menu() {
  int choice;
  cout << endl << "***********************" << endl;
  cout << "Valitse toiminto" << endl;
  cout << "(1) kaikki tietueet" << endl;
  cout << "(2) valittu tietue" << endl;
  cout << "(3) lisaa uusi" << endl;
  cout << "(4) muokkaa tietue" << endl;
  cout << "(5) poista tietue" << endl;
  cout << "(0) LOPETA" << endl;
  cout << "***********************" << endl;
  cin >> choice;
  system("CLS");
  return choice;
}
void allRows() {
  DataContext persons;
  cout << endl << "Kaikki henkilot" << endl;
  foreach (const Person &obj, persons.GetObjectList()) {
    cout << "ID:" << obj.getId()
         << " Firstname:" << obj.getFname().toStdString()
         << " Lastname:" << obj.getLname().toStdString() << endl;
  }
}
void oneRow() {
  DataContext persons;
  cout << "Anna id" << endl;
  int id;
  cin >> id;
  cout << "fname=" << persons.GetOnePerson(id).getFname().toStdString()
       << " lname=" << persons.GetOnePerson(id).getLname().toStdString()
       << endl;
}
void addData() {
  DataContext persons;
  QString fname;
  QString lname;
  QTextStream qtin(stdin);
  cout << "Anna etunimi" << endl;
  fname = qtin.readLine();
  cout << "Anna sukunimi" << endl;
  lname = qtin.readLine();
  Person objectAdd = Person(fname, lname);
  QString res = persons.AddPerson(objectAdd);
  cout << res.toStdString() << endl;
}
void updateData() { cout << "Ei tehty" << endl; }
void deleteData() { cout << "Ei tehty" << endl; }
