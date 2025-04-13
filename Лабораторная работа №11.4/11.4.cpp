#include <iostream>
#include <fstream>
using namespace std;

struct Queue
{
    struct Node
    {
        int key;
        Node* next;
    };
    
    Node* front = nullptr;
    Node* rear = nullptr;
    
    void enqueue(int key)
    {
        Node* newNode = new Node{key, nullptr};
        if (rear)
        {
            rear -> next = newNode;
            rear = newNode;
        }
        else
        {
            front = rear = newNode;
        }
    }
    
    void print()
    {
        if (!front)
        {
            cout << "Очередь пустая\n";
            return;
        }
        cout << "Очередь: ";
        for (Node* curr = front; curr; curr = curr -> next)
            cout << curr -> key << " ";
        cout << endl;
    }
    
    void delete_key(int key)
    {
        Node* curr = front;
        Node* prev = nullptr;
        while (curr)
        {
            if (curr -> key == key)
            {
                if (prev) prev -> next = curr -> next;
                else front = curr -> next;
                if (curr == rear) rear = prev;
                delete curr;
                cout << "Удален элкмент с ключом: " << key << endl;
                return;
            }
            prev = curr;
            curr = curr -> next;
        }
        cout << "Ключ не найден\n";
    }
    
    void insert_key(int before_key, int newKey)
    {
        Node* curr = front;
        Node* prev = nullptr;
        while (curr)
        {
            if (curr -> key == before_key)
            {
                Node* newNode = new Node{newKey, curr};
                if (prev) prev -> next = newNode;
                else front = newNode;
                cout << "Добавлен " << newKey << " Перед " << before_key << endl;
                return;
            }
            prev = curr;
            curr = curr -> next;
        }
        cout << "Ключ для вставки не найден\n";
    }
    
    void save_file(const string& filename)
    {
        ofstream file(filename);
        for (Node* curr = front; curr; curr = curr -> next)
            file << curr -> key << " ";
        file.close();
        cout << "Очередь записана в файл\n";
    }
    
    void delete_queue()
    {
        while (front)
        {
            Node* tmp = front;
            front = front -> next;
            delete tmp;
        }
        rear = nullptr;
        cout << "Очередь уничтожена\n";
        }
    
    void load_file(const string& filename)
    {
        ifstream file(filename);
        int key;
        while (file >> key)
            enqueue(key);
        file.close();
        cout << "Очередь восстановлена из файла\n";
    }
};

int main ()
{
    Queue q;
    int n, val;
    cout << "Введите количество элементов: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Введите элемент №" << i + 1 << ": ";
        cin >> val;
        q.enqueue(val);
    }
    q.print();
    int del_key;
    cout << "Введите ключ для удаления: ";
    cin >> del_key;
    q.delete_key(del_key);
    q.print();
    int newKey, before_key;
    cout << "Введите новый ключ для вставки: ";
    cin >> newKey;
    cout << "Введите ключ, перед которым нужно вставить: ";
    cin >> before_key;
    q.insert_key(before_key, newKey);
    q.print();
    string filename = "/Users/nikita/Documents/PSTU/Лабы/Lab11.4/queue.txt";
    q.save_file(filename);
    q.delete_queue();
    q.print();
    q.load_file(filename);
    q.print();
    q.delete_queue();
    return 0;
}
