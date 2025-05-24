#include "Employee.h"

Employee::Employee(void):Person()
{
    wages=0.0f;
    post="";
}

Employee::~Employee(void)
{
    
}

Employee::Employee(string N, int A, float W, string P):Person(N,A)
{
    wages=W;
    post=P;
}

Employee::Employee(const Employee &E) : Person(E)
{
    wages=E.wages;
    post=E.post;
}

void Employee::Set_wages(float W)
{
    wages=W;
}

void Employee::Set_post(string P)
{
    post=P;
}

Employee& Employee::operator=(const Employee&e)
{
    if(&e==this) return *this;
    name=e.name;
    age=e.age;
    wages=e.wages;
    post=e.post;
    return *this;
}

void Employee::Show()
{
    cout << "\nNAME : "<<name;
    cout << "\nAGE : "<<age;
    cout << "\nWAGES : " <<wages;
    cout << "\nPOST : " <<post;
    cout << "\n";
}

void Employee::Input()
{
    cout <<"\nName:"; cin >> name;
    cout <<"\nAge:"; cin >> age;
    cout <<"\nWages:"; cin >> wages;
    cout <<"\nPost:"; cin >> post;
}
