#include "Time.h"
#include "file_work.h"
#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
    const char* filename = "/Users/nikita/Documents/PSTU/Лабы/Lab10(class)/time.txt";
    make_file(filename);
    cout << "\nСозданный файл:\n";
    print_file(filename);
    
    Time ref;
    cout << "\nВведите значение для сравнения (м:с): ";
    cin >> ref;
    
    delete_not_equal(filename, ref);
    cout << "\nПосле удаления всех неравных:\n";
    print_file(filename);
    
    decrease_matches(filename, ref);
    cout << "\nПосле уменьшения равных на 1 минуту 30 секунд:\n";
    print_file(filename);
    
    int k;
    cout << "\nСколько записей добавить в начало файла? ";
    cin >> k;
    vector<Time> prepend_times;
    for (int i = 0; i < k; ++i)
    {
        Time t;
        cout << "Введите интервал (м:с): ";
        cin >> t;
        prepend_times.push_back(t);
    }
    
    add_beginning(filename, prepend_times);
    cout << "\nИтоговое содержимое файла:\n";
    print_file(filename);
    return 0;
}
