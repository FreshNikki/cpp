#include <iostream>
#include <fstream>
using namespace std;

struct StackNode
{
    int key;
    StackNode* next;
};

void push(StackNode*& top, int key)
{
    StackNode* newNode = new StackNode{key, top};
    top = newNode;
}

void print_Stack(StackNode* top)
{
    if (!top)
    {
        cout << "Стек пустой\n";
        return;
    }
    cout << "Стек: ";
    for (StackNode* curr = top; curr; curr = curr -> next)
        cout << curr -> key << " ";
    cout << endl;
}

void delete_key(StackNode*& top, int key)
{
    StackNode* tmp_top = nullptr;
    bool found = false;
    while (top)
    {
        int current = top -> key;
        StackNode* to_delete = top;
        top = top -> next;
        if (current == key)
        {
            delete to_delete;
            found = true;
            break;
        }
        else
        {
            push(tmp_top, current);
            delete to_delete;
        }
    }
    while (tmp_top)
    {
        push(top, tmp_top -> key);
        StackNode* old = tmp_top;
        tmp_top = tmp_top -> next;
        delete old;
    }
    if (!found) cout << "Элемент с ключом " << key << " не найден.\n";
}

void insert_key(StackNode*& top, int before_key, int newKey)
{
    StackNode* tmp_top = nullptr;
    bool inserted = false;
    while (top)
    {
        int current = top -> key;
        if (current == before_key && !inserted)
        {
            push (tmp_top, newKey);
            inserted = true;
        }
        push(tmp_top, current);
        StackNode* old = top;
        top = top -> next;
        delete old;
    }
    while (tmp_top)
    {
        push(top, tmp_top -> key);
        StackNode* old = tmp_top;
        tmp_top = tmp_top -> next;
        delete old;
    }
    if (!inserted)
        cout << "Ключ " << before_key << " Не найден, вставка не выполнена.\n";
}

void save_file(StackNode* top, const string& filename)
{
    ofstream file(filename);
    for (StackNode* curr = top; curr; curr = curr -> next)
        file << curr -> key << " ";
    file.close();
}

void delete_stack(StackNode*& top)
{
    while (top)
    {
        StackNode* tmp = top;
        top = top -> next;
        delete tmp;
    }
}

void load_file(StackNode*& top, const string& filename)
{
    ifstream file(filename);
    int val;
    StackNode* reversed = nullptr;
    while (file >> val)
        push(reversed, val);
    while (reversed)
    {
        push(top, reversed -> key);
        StackNode* tmp = reversed;
        reversed = reversed -> next;
        delete tmp;
    }
    file.close();
}

int main()
{
    setlocale(LC_ALL, "Ru");
    StackNode* top = nullptr;
    int n, val;
    cout << "Введите количество элементов: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Введите элемент №" << i + 1 << ": ";
        cin >> val;
        push(top, val);
    }
    
    print_Stack(top);
    int del_key;
    cout << "Введите ключ удля удаления: ";
    cin >> del_key;
    delete_key(top, del_key);
    print_Stack(top);
    
    int newKey, before_key;
    cout << "Введите новый ключ: ";
    cin >> newKey;
    cout << "Введите ключ, перед которым нужно вставить: ";
    cin >> before_key;
    insert_key(top, before_key, newKey);
    print_Stack(top);
    
    string filename = "/Users/nikita/Documents/PSTU/Лабы/Lab11.3/stack.txt";
    save_file(top, filename);
    delete_stack(top);
    print_Stack(top);
    load_file(top, filename);
    print_Stack(top);
    delete_stack(top);
    return 0;
}
