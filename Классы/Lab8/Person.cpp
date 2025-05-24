#include "Person.h"

Person::Person(void)
{
    name = "";
    age=0;
}

Person::~Person(void)
{
    
}

Person::Person(string N, int A)
{
    name=N;
    age=A;
}

Person::Person(const Person& person)
{
    name=person.name;
    age=person.age;
}

void Person::Set_age(int A)
{
    age = A;
}

void Person::Set_name(string N)
{
    name = N;
}

Person& Person::operator=(const Person&p)
{
    if (&p==this) return *this;
    name=p.name;
    age=p.age;
    return *this;
}

void Person::Show()
{
    cout << "\nNAME : " << name;
    cout << "\nAGE : " << age;
    cout << "\n";
}

void Person::Input()
{
    cout << "\nName:"; cin >> name;
    cout << "\nAge:"; cin >> age;
}




