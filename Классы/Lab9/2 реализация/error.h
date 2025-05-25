#pragma once
#include <string>
#include <iostream>

using namespace std;

class error
{
    string message;
public:
    error(const string& msg):message(msg) {}
    void what() const
    {
        cout << "Ошибка: " << message << endl;
    }
};
