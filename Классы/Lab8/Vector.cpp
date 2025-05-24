#include "Vector.h"
#include "Employee.h"
#include <iostream>

using namespace std;

Vector::Vector(int n) {
    size = n;
    beg = new Object * [size];
    cur = 0;
}

Vector::~Vector() {
    for (int i = 0; i < cur; i++) delete beg[i];
    delete[] beg;
}

void Vector::Add() {
    if (cur < size) {
        Employee* e = new Employee;
        e->Input();
        beg[cur++] = e;
    } else {
        cout << "Group is full.\n";
    }
}

void Vector::Del() {
    if (cur > 0) {
        delete beg[--cur];
    } else {
        cout << "Group is empty.\n";
    }
}

void Vector::Show() {
    for (int i = 0; i < cur; i++) beg[i]->Show();
}


