#include "datacontext.h"

DataContext::DataContext() {
  QSqlDatabase db;
  db = QSqlDatabase::addDatabase("QSQLITE");
  QString myFolder = "C:/codes/qt_projects/sqliteORM";
  db.setDatabaseName(myFolder + "/database/mydb.db");
  db.open();
  if (!db.open()) {
    qDebug() << "Error: Unable to open the database";
  } else {
    SetObjectList();
  }
}

DataContext::~DataContext() {
  QString myConnection = db.connectionName();
  db.close();
  db = QSqlDatabase();
  db.removeDatabase(myConnection);
}

void DataContext::SetObjectList() {
  //get data from database and push it to the QList
  QSqlQuery query("SELECT * FROM person");

  while (query.next()) {
    int id = query.value(0).toInt();
    QString fname = query.value(1).toString();
    QString lname = query.value(2).toString();

    Person obj(id, fname, lname);
    objectList.append(obj);
  }
}

QList<Person> DataContext::GetObjectList() const {
    return objectList;
}

Person DataContext::GetOnePerson(int x) {
  //get the chosen Person from QList
  foreach (const Person &obj, objectList) {
    if (obj.getId() == x) {
      return obj;
    }
  }
  //if Person does not exist on QList
  return Person(-1, "No fname", "No lname");
}

QString DataContext::AddPerson(Person &obj) {
  //add the Person to database
  QSqlQuery query;
  query.prepare("INSERT INTO person(firstname,lastname) VALUES(:fn, :ln)");
  query.bindValue(":fn", obj.getFname());
  query.bindValue(":ln", obj.getLname());

  //if the data was succesfully added to database push it to QList
  if (query.exec()) {
    //check what is the id of the inserted Person
    QSqlQuery query("SELECT last_insert_rowid()");
    if (query.exec() && query.next()) {
      int lastId = query.value(0).toInt();
      Person addPerson = Person(lastId, obj.getFname(), obj.getLname());
      objectList.append(addPerson);
    }
    return "added person: " + obj.getFname() + " " + obj.getLname();
  } else {
    return "something went wrong";
  }
}

QString DataContext::UpdatePerson(Person &updateObj, int x)
{
    //update the database
    QSqlQuery query;
    query.prepare("UPDATE person SET firstname=:fn, lastname=:ln WHERE id=:id");
    query.bindValue(":id", x);
    query.bindValue(":fn", updateObj.getFname());
    query.bindValue(":ln", updateObj.getLname());
    //if database was succesfully updated, update QList
    if (query.exec()) {
        for (int i = 0; i < objectList.size(); ++i) {
            Person &obj = objectList[i];
            if (obj.getId() == x) {
                obj.setFname(updateObj.getFname());
                obj.setLname(updateObj.getLname());
                return "Person updated successfully";
            }
        }
    }
    return "Person not found";
}

QString DataContext::DeletePerson(int x) {
  //delete Person from database
  QSqlQuery query;
  query.prepare("DELETE FROM person WHERE id=:id");
  query.bindValue(":id", x);
  //if Person was deleted from database, delete from QList
  if (query.exec()) {
    int indexToRemove = -1;
    for (int i = 0; i < objectList.size(); ++i) {
        if (objectList.at(i).getId() == x) {
        indexToRemove = i;
        break;
        }
    }
    if (indexToRemove != -1) {
        objectList.removeAt(indexToRemove);
        return "Person deleted";
    }
    else {
        return "Person does not exist";
    }
  }
  else {
    return "Person does not exist";
  }
}
