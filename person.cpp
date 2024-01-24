#include "person.h"


Person::Person(int i, QString fn, QString ln)
{
    id=i;
    fname=fn;
    lname=ln;
}

int Person::getId() const
{
    return id;
}

QString Person::getFname() const
{
    return fname;
}

QString Person::getLname() const
{
    return lname;
}
