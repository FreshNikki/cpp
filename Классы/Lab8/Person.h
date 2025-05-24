#include "Object.h"
#include <iostream>
#include <string>
#pragma once

using namespace std;

class Person:
    public Object
{
public:
    Person(void);
public:
    virtual ~Person(void);
    void Show() override;
    void Input() override;
    Person(string, int);
    Person(const Person&);
    string Get_name () {return name;}
    int Get_age () {return age;}
    void Set_name(string);
    void Set_age(int);
    Person& operator=(const Person&);
protected:
    string name;
    int age;
};


