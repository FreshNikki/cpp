#include <iostream>
#include <fstream>
using namespace std;

struct Stack
{
    struct Node
    {
        int key;
        Node* next;
    };
    Node* top = nullptr;
    
    void push(Node*& top, int key)
    {
        Node* newNode = new Node{key, top};
        top = newNode;
    }
    
    void print_Stack(Node* top)
    {
        if (!top)
        {
            cout << "Стек пустой\n";
            return;
        }
        cout << "Стек: ";
        for (Node* curr = top; curr; curr = curr -> next)
            cout << curr -> key << " ";
        cout << endl;
    }
    
    void delete_key(Node*& top, int key)
    {
        Node* tmp_top = nullptr;
        bool found = false;
        while (top)
        {
            int current = top -> key;
            Node* to_delete = top;
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
            Node* old = tmp_top;
            tmp_top = tmp_top -> next;
            delete old;
        }
        if (!found) cout << "Элемент с ключом " << key << " не найден.\n";
    }
    
    void insert_key(Node*& top, int before_key, int newKey)
    {
        Node* tmp_top = nullptr;
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
            Node* old = top;
            top = top -> next;
            delete old;
        }
        while (tmp_top)
        {
            push(top, tmp_top -> key);
            Node* old = tmp_top;
            tmp_top = tmp_top -> next;
            delete old;
        }
        if (!inserted)
            cout << "Ключ " << before_key << " Не найден, вставка не выполнена.\n";
    }
    
    void save_file(Node* top, const string& filename)
    {
        ofstream file(filename);
        for (Node* curr = top; curr; curr = curr -> next)
            file << curr -> key << " ";
        file.close();
    }
    
    void delete_stack(Node*& top)
    {
        while (top)
        {
            Node* tmp = top;
            top = top -> next;
            delete tmp;
        }
    }
    
    void load_file(Node*& top, const string& filename)
    {
        ifstream file(filename);
        int val;
        Node* reversed = nullptr;
        while (file >> val)
            push(reversed, val);
        while (reversed)
        {
            push(top, reversed -> key);
            Node* tmp = reversed;
            reversed = reversed -> next;
            delete tmp;
        }
        file.close();
    }
};

int main()
{
    setlocale(LC_ALL, "Ru");
    Stack s;
    int n, val;
    cout << "Введите количество элементов: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Введите элемент №" << i + 1 << ": ";
        cin >> val;
        s.push(s.top, val);
    }
    
    s.print_Stack(s.top);
    int del_key;
    cout << "Введите ключ удля удаления: ";
    cin >> del_key;
    s.delete_key(s.top, del_key);
    s.print_Stack(s.top);
    
    int newKey, before_key;
    cout << "Введите новый ключ: ";
    cin >> newKey;
    cout << "Введите ключ, перед которым нужно вставить: ";
    cin >> before_key;
    s.insert_key(s.top, before_key, newKey);
    s.print_Stack(s.top);
    
    string filename = "/Users/nikita/Documents/PSTU/Лабы/Lab11.3/stack.txt";
    s.save_file(s.top, filename);
    s.delete_stack(s.top);
    s.print_Stack(s.top);
    s.load_file(s.top, filename);
    s.print_Stack(s.top);
    s.delete_stack(s.top);
    return 0;
}
