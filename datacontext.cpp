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
  QSqlQuery query("SELECT * FROM person");

  while (query.next()) {
    int id = query.value(0).toInt();
    QString fname = query.value(1).toString();
    QString lname = query.value(2).toString();

    Person obj(id, fname, lname);
    objectList.append(obj);
  }

  db.close();
}

QList<Person> DataContext::GetObjectList() const { return objectList; }

Person DataContext::GetOnePerson(int x) {
  foreach (const Person &obj, objectList) {
    if (obj.getId() == x) {
      return obj;
    }
  }
  return Person(-1, "No fname", "No lname");
}

QString DataContext::AddPerson(Person &obj) {
  QSqlQuery query;
  query.prepare("INSERT INTO person(firstname,lastname) VALUES(:fn, :ln)");
  query.bindValue(":fn", obj.getFname());
  query.bindValue(":ln", obj.getLname());
  bool res = query.exec();
  if (res) {
    QSqlQuery query("SELECT last_insert_rowid()");
    if (query.exec() && query.next()) {
      // add new object to list
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
    for (int i = 0; i < objectList.size(); ++i) {
        Person &obj = objectList[i];
        if (obj.getId() == x) {
            obj.setFname(updateObj.getFname());
            obj.setLname(updateObj.getLname());
            return "Person updated successfully"; // You can change this return value as needed
        }
    }

    return "Person not found";
}

QString DataContext::DeletePerson(int x) {
  QSqlQuery query;
  query.prepare("DELETE FROM person WHERE id=:id");
  query.bindValue(":id", x);
  bool res = query.exec();
  if (res) {
    int indexToRemove = -1;
    for (int i = 0; i < objectList.size(); ++i) {
      if (objectList.at(i).getId() == x) {
        indexToRemove = i;
        break;
      }
    }
    // Remove the object if found
    if (indexToRemove != -1) {
      objectList.removeAt(indexToRemove);
      return "Deleted";
    } else {
      return "Person does not exist";
    }
  } else {
    return "Person does not exist";
  }
}
