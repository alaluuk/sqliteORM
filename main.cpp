#include "datacontext.h"

#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <iostream>

using namespace std;

int menu();
void allRows(DataContext *persons);
void oneRow(DataContext *persons);
void addData(DataContext *persons);
void updateData(DataContext *persons);
void deleteData(DataContext *persons);

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);
  DataContext p;

  int choice = 1;
  while (choice != 0) {
    choice = menu();
    if (choice == 1) {
      allRows(&p);
    } else if (choice == 2) {
      oneRow(&p);
    } else if (choice == 3) {
      addData(&p);
    } else if (choice == 4) {
      updateData(&p);
    } else if (choice == 5) {
      deleteData(&p);
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
void allRows(DataContext *persons) {
  cout << endl << "Kaikki henkilot" << endl;
    foreach (const Person &obj, persons->GetObjectList()) {
    cout << "ID:" << obj.getId()
         << " :" << obj.getFname().toStdString()
         << " " << obj.getLname().toStdString() << endl;
  }
}
void oneRow(DataContext *persons) {
  cout << "Anna id : ";
  int id;
  cin >> id;
  if(persons->GetOnePerson(id).getId()==-1){
    cout<<"Henkiloa ei ole"<<endl;
  }
  else{
    cout << "Henkilo = " << persons->GetOnePerson(id).getFname().toStdString()
    << " " << persons->GetOnePerson(id).getLname().toStdString()<< endl;
  }

}
void addData(DataContext *persons) {
  QString fname;
  QString lname;
  QTextStream qtin(stdin);
  cout << "Anna etunimi : ";
  fname = qtin.readLine();
  cout << "Anna sukunimi : ";
  lname = qtin.readLine();
  Person objectAdd = Person(fname, lname);
  QString res = persons->AddPerson(objectAdd);
  cout << res.toStdString() << endl;
}
void updateData(DataContext *persons) {
    int id;
    QString fname;
    QString lname;
    QTextStream qtin(stdin);
    cout<<"Anna id : ";
    cin>>id;
    cout<<"Anna etunimi : ";
    fname=qtin.readLine();
    cout<<"Anna sukunimi : ";
    lname=qtin.readLine();
    Person updateObj=Person(fname,lname);
    QString res =persons->UpdatePerson(updateObj, id);
    cout << res.toStdString() << endl;
}
void deleteData(DataContext *persons) {
    cout << "Anna id : ";
    int id;
    cin >> id;
    QString res =persons->DeletePerson(id);
    cout << res.toStdString() << endl;
}
