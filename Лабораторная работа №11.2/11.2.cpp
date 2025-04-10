#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int key;
    Node* first;
    Node* next;
};

void create_list(Node*& head, Node*& tail)
{
    head = tail = nullptr;
    int n, value;
    cout << "Введите количество элементов: ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cout << "Введите элемент №" << i + 1 << ": ";
        cin >> value;
        Node* newNode = new Node{value, tail, nullptr};
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }
}

void print_list(Node* head)
{
    if (!head)
    {
        cout << "Список пустой" << endl;
        return;
    }
    cout << "Список: ";
    for (Node* current = head; current; current = current -> next)
        cout << current -> key << " ";
    cout << endl;
}

void delete_key(Node*& head, Node*& tail, int key)
{
    Node* current = head;
    while (current && current -> key != key)
        current = current -> next;
    if (!current) return;
    if (current == head) head = current -> next;
    if (current == tail) tail = current -> first;
    if (current -> first) current -> first -> next = current -> next;
    if (current -> next) current -> next -> first = current -> first;
    delete current;
}

void add_key(Node*& head, int keyFind, int newKey)
{
    Node* current = head;
    while (current && current -> key != keyFind)
        current = current -> next;
    if (!current) return;
    Node* newNode = new Node{newKey, current -> first, current};
    if (current -> first)
        current -> first -> next = newNode;
    else
        head = newNode;
    current -> first = newNode;
}

void save_file(Node* head, const string& filename)
{
    ofstream file(filename);
    for (Node* current = head; current; current = current -> next)
        file << current -> key << " ";
    file.close();
}

void delete_list(Node*& head, Node*& tail)
{
    while (head)
    {
        Node* tmp = head;
        head = head -> next;
        delete tmp;
    }
    tail = nullptr;
}

void load_file(Node*& head, Node*& tail, const string& filename)
{
    ifstream file(filename);
    int value;
    head = tail = nullptr;
    while (file >> value)
    {
        Node* newNode = new Node{value, tail, nullptr};
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }
    file.close();
}

int main()
{
    setlocale(LC_ALL, "Ru");
    Node* head = nullptr;
    Node* tail = nullptr;
    create_list(head, tail);
    print_list(head);
    int del_key;
    cout << "Введите ключ для удаления: ";
    cin >> del_key;
    delete_key(head, tail, del_key);
    print_list(head);
    int newKey, beforeKey;
    cout << "Введите ключ для нового элемента: ";
    cin >> newKey;
    cout << "Введите ключ элемента, перед которым надо вставить: ";
    cin >> beforeKey;
    add_key(head, beforeKey, newKey);
    print_list(head);
    string filename = "/Users/nikita/Documents/PSTU/Лабы/Lab11.2/list.txt";
    save_file(head, filename);
    delete_list(head, tail);
    print_list(head);
    load_file(head, tail, filename);
    print_list(head);
    delete_list(head, tail);
    return 0;
}




