#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include "money.h"

using namespace std;

typedef priority_queue<Money> TPQueue;

TPQueue make_pqueue(int n)
{
    TPQueue q;
    Money a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        q.push(a);
    }
    return q;
}

void print_pqueue(TPQueue q)
{
    vector<Money> temp;
    while (!q.empty()) {
        temp.push_back(q.top());
        cout << q.top() << endl;
        q.pop();
    }
    cout << endl;
    for (auto m : temp) q.push(m);
}

vector<Money> pqueue_to_vector(TPQueue q)
{
    vector<Money> v;
    while (!q.empty()) {
        v.push_back(q.top());
        q.pop();
    }
    return v;
}

TPQueue vector_to_pqueue(const vector<Money>& v)
{
    TPQueue q;
    for (auto m : v) q.push(m);
    return q;
}


TPQueue insert(TPQueue q, int pos)
{
    vector<Money> v = pqueue_to_vector(q);
    Money min = *min_element(v.begin(), v.end());

    if (pos >= 0 && pos <= v.size())
    {
        v.insert(v.begin() + pos, min);
    }
    else
    {
        cout << "Invalid position!" << endl;
    }

    return vector_to_pqueue(v);
}


TPQueue Del(TPQueue q)
{
    vector<Money> v = pqueue_to_vector(q);
    if (v.empty()) return q;

    Money sum;
    for (auto m : v) sum = sum + m;
    Money average = sum / v.size();

    auto new_end = remove_if(v.begin(), v.end(), [average](Money m) { return m > average; });
    v.erase(new_end, v.end());

    return vector_to_pqueue(v);
}

TPQueue Umn(TPQueue q)
{
    vector<Money> v = pqueue_to_vector(q);
    if (v.empty()) return q;

    Money max = *max_element(v.begin(), v.end());
    for (auto& m : v) m = m * max;

    return vector_to_pqueue(v);
}

int main()
{
    int n;
    cout << "N: ";
    cin >> n;
    TPQueue q = make_pqueue(n);

    cout << "Position ";
    int pos;  cin >> pos;
    q = insert(q, pos);
    print_pqueue(q);

    q = Del(q);
    cout << "Before del: " << endl;
    print_pqueue(q);

    q = Umn(q);
    cout << "Before umn: " << endl;
    print_pqueue(q);

    return 0;
}
