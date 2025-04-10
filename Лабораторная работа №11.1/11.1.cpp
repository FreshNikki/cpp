#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int key;
    Node* next;
};

void create_list(Node*& head)
{
    head = nullptr;
    int n, value;
    cout << "Ввести количество элментов: ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cout << "Введите элемент №" << i + 1 << ": ";
        cin >> value;
        Node* newNode = new Node{value, nullptr};
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node* tmp = head;
            while (tmp -> next)
                tmp = tmp -> next;
            tmp -> next = newNode;
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
    Node* tmp = head;
    cout << "Список: ";
    while (tmp)
    {
        cout << tmp -> key << " ";
        tmp = tmp -> next;
    }
    cout << endl;
}

void delete_key(Node*& head, int key)
{
    if (!head) return;
    if (head -> key == key)
    {
        Node* toDelete = head;
        head = head -> next;
        delete toDelete;
        return;
    }
    Node* current = head;
    while (current -> next && current -> next -> key != key)
    {
        current = current -> next;
    }
    if (current -> next)
    {
        Node* toDelete = current -> next;
        current -> next = toDelete -> next;
        delete toDelete;
    }
}

void add_key(Node*& head, int key, int new_key)
{
    Node* newNode = new Node{new_key, nullptr};
    if (!head) return;
    if (head -> key == key)
    {
        newNode -> next = head;
        head = newNode;
        return;
    }
    Node* current = head;
    while (current -> next && current -> next -> key != key)
    {
        current = current -> next;
    }
    if (current -> next)
    {
        newNode -> next = current -> next;
        current -> next = newNode;
    }
}

void save_file(Node* head, const string& filename)
{
    ofstream file(filename);
    Node* tmp = head;
    while (tmp)
    {
        file << tmp -> key << " ";
        tmp = tmp -> next;
    }
    file.close();
}

void delete_list(Node*& head)
{
    while (head)
    {
        Node* tmp = head;
        head = head -> next;
        delete tmp;
    }
}

void load_file(Node*& head, const string& filename)
{
    ifstream file(filename);
    int value;
    Node* last = nullptr;
    head = nullptr;
    while (file >> value)
    {
        Node* newNode = new Node{value, nullptr};
        if (!head)
            head = newNode;
        else
            last -> next = newNode;
        last = newNode;
    }
    file.close();
}

int main()
{
    setlocale(LC_ALL, "Ru");
    Node* head;
    create_list(head);
    print_list(head);
    int key_del;
    cout << "Введите ключ для удаления: ";
    cin >> key_del;
    delete_key(head, key_del);
    print_list(head);
    int key_add, newKey;
    cout << "Введите ключ перед которым нужно добавить элемент: ";
    cin >> key_add;
    cout << "Введите новый ключ для добавления: ";
    cin >> newKey;
    add_key(head, key_add, newKey);
    print_list(head);
    string filename = "/Users/nikita/Documents/PSTU/Лабы.list.txt";
    save_file(head, filename);
    delete_list(head);
    print_list(head);
    load_file(head, filename);
    print_list(head);
    delete_list(head);
    return 0;
}
