#include "Money.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef vector<Money> TVector;
Money s;

TVector make_vector(int n)
{
	Money a;
	TVector v;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	return v;
}

void print_vector(TVector v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	cout << endl;
}

struct  Greater_s
{
	bool operator()(Money t)
	{
		if (t > s)return true;
		else return false;
	}
};

Money Srednee(TVector v)
{
	Money s = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		s = s + v[i];
	}
	int n = v.size();
	return s / n;
}

void Umn(Money& t)
{
	t = t * s;
}


int main()
{
	int n;
	cout << "N: "; cin >> n;
	TVector v;
	v = make_vector(n);
	print_vector(v);
	TVector::iterator i;
	i = min_element(v.begin(), v.end());
	cout << "Min: " << (*i) << endl;
	cout << "Position: ";
	int pos; cin >> pos;
	v.insert(v.begin() + pos, (*i));
	print_vector(v);
	s = Srednee(v);
	cout << "Srednee: " << s << endl;
	auto it = remove_if(v.begin(), v.end(), Greater_s());
	v.erase(it, v.end());
	print_vector(v);
	i = min_element(v.begin(), v.end());
	s = *i;
	cout << "Max: " << s << endl;
	for_each(v.begin(), v.end(), Umn);
	print_vector(v);
	return 0;

}