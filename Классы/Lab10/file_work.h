#include "Time.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int make_file(const char* f_name)
{
    fstream fout(f_name, ios::out | ios::trunc);
    if (!fout) return -1;
    
    int n;
    cout << "Сколько записей создать? ";
    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        Time t;
        cout << "Введите время (м:с): ";
        cin >> t;
        fout << t;
    }
    
    fout.close();
    return 0;
}

int print_file(const char* f_name)
{
    fstream fin(f_name, ios::in);
    if (!fin) return -1;
    
    Time t;
    while (fin >> t)
    {
        cout << t << "\n";
    }
    fin.close();
    return 0;
}

int delete_not_equal(const char* f_name, const Time& value)
{
    fstream fin(f_name, ios::in);
    if (!fin) return -1;
    
    vector<Time> result;
    Time t;
    while (fin >> t)
    {
        if (!(t != value)) result.push_back(t);
    }
    fin.close();
    
    fstream fout(f_name, ios::out | ios::trunc);
    for (const Time& time:result)
        fout << time;
    fout.close();
    return 0;
}

int decrease_matches(const char* f_name, const Time& value)
{
    fstream fin(f_name, ios::in);
    if (!fin) return -1;
    
    vector<Time> result;
    Time t;
    while (fin >> t)
    {
        if (!(t != value))
            t.decrease(1, 30);
        result.push_back(t);
    }
    fin.close();
    
    fstream fout (f_name, ios::out | ios::trunc);
    for (const Time& time:result)
        fout << time;
    fout.close();
    return 0;
}

int add_beginning(const char* f_name, const vector<Time>& values)
{
    fstream fin(f_name, ios::in);
    if (!fin) return -1;
    
    vector<Time> all = values;
    Time t;
    while (fin >> t)
        all.push_back(t);
    fin.close();
    
    fstream fout(f_name, ios::out | ios::trunc);
    for (const Time& time:all)
        fout << time;
    fout.close();
    return 0;
}

