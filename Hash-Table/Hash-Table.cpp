#include <iostream>
#include <string>
using namespace std;

struct Person
{
    string name;
    string date;
    string group;
    Person()
    {
        name = "NULL";
        date = "NULL";
        group = "NULL";
        
    }
};

struct hashTable
{
    Person* arr;
    int collisions;
    hashTable(int size)
    {
        arr = new Person[size];
        collisions = 0;
    }
    void insert(Person p, int size);
    void pop(string date, int size);
    void search(string date, int size);
};

int hashFunc(string str, int size)
{
        double f = 0.1337 * stoi(str.substr(0, 2)) + stoi(str.substr(3, 2)) + stoi(str.substr(6, 4));
        double g = (f - int(f)) * size;
        return int(g);
}

void hashTable::insert(Person p, int size)
{
    int idx = hashFunc(p.date, size);
    int hash = idx;
    while (arr[idx].name != "NULL")
    {
        idx++;
        collisions++;
        if (idx >= size)
        {
            idx = 0;
        }
        if (idx == hash)
        {
            cout << "Хэш-таблица переполнена!" << endl;
            return;
        }
    }
    arr[idx] = p;
}

void hashTable::pop(string date, int size)
{
    int idx = hashFunc(date, size);
    int hash = idx;
    while (arr[idx].date != date)
    {
        idx++;
        if (idx >= size)
        {
            idx = 0;
        }
        if (idx == hash)
        {
            cout << "Запись с датой " << date << " не найдена для удаления." << endl;
            return;
        }
    }
    arr[idx] = Person();
    cout << "Запись с датой " << date << " удалена." << endl;
}

void hashTable::search(string date, int size)
{
    int idx = hashFunc(date, size);
    int hash = idx;
    while (arr[idx].date != date)
    {
        idx++;
        if (idx >= size)
        {
            idx = 0;
        }
        if (idx == hash)
        {
            cout << "Человек с датой рождения " << date << " не найден." << endl;
            return;
        }
    }
    cout << "Человек с датой рождения " << date << " найден по индексу " << idx << endl;
    cout << "ФИО: " << arr[idx].name << ", Группа: " << arr[idx].group << endl;
}

void displayPerson(const Person& p)
{
    if (p.name == "NULL") return;
    cout << "===" << endl;
    cout << "ФИО: " << p.name << endl;
    cout << "Группа: " << p.group << endl;
    cout << "Дата рождения: " << p.date << endl;
    cout << "===" << endl;
}

void displayHashTable(hashTable* table, int size)
{
    cout << "\nСодержимое хэш-таблицы:\n";
    for (int i = 0; i < size; i++)
    {
        if (table -> arr[i].name != "NULL")
        {
            displayPerson(table -> arr[i]);
        }
    }
    cout << "Коллизии: " << table -> collisions << endl;
}
int main ()
{
    setlocale (LC_ALL, "Rus");
    const int size = 10;
    hashTable ht(size);
    Person p;
    cout << "Введите ФИО: ";
    getline(cin, p.name);
    cout << "Введите дату рождения: ";
    getline(cin, p.date);
    cout << "Введите группу: ";
    getline(cin, p.group);
    ht.insert(p, size);
    
    Person p2;
    p2.name = "Садриев Александр Витальевич";
    p2.date = "16.09.2004";
    p2.group = "ИВТ-24-1б";
    ht.insert(p2, size);
    displayHashTable(&ht, size);
    ht.search(p.date, size);
    ht.pop(p.date, size);
    ht.search(p.date, size);
    displayHashTable(&ht, size);
    return 0;
}
