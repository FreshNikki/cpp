#pragma once
#include "Person.h"

class Employee:
    public Person
{
public:
    Employee(void);
public:
    ~Employee(void);
    void Show() override;
    void Input() override;
    Employee(string, int, float, string);
    Employee(const Employee & );
    float Get_wages () {return wages;}
    string Get_post () {return post;}
    void Set_wages(float);
    void Set_post(string);
    Employee& operator=(const Employee&);
protected:
    float wages;
    string post;
};



