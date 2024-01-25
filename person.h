#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person
{
public:
    Person(int i, QString fn, QString ln);
    Person(QString fn, QString ln);
    int getId() const;

    QString getFname() const;

    QString getLname() const;

    void setFname(const QString &newFname);

    void setLname(const QString &newLname);

private:
    int id;
    QString fname;
    QString lname;
};

#endif // PERSON_H
