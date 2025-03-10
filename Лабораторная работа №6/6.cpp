#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	system("chcp 1251");
	system("cls");
	string str, tmp, longest, shortest = "";
	cout << "Введите строку: ";
	getline(cin, str);
	int count = 0;
	int max = 0;
	int min = 255;
	str += ' ';

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != ' ')
		{
			tmp += str[i];
			count++;
		}
		else if (tmp != "")
		{
			if (count > max)
			{
				max = count;
				longest = tmp;
			}
			if (count < min)
			{
				min = count;
				shortest = tmp;
			}
			tmp = "";
			count = 0;
		}
	}
	cout << "Cамое длинное слово: " << longest << " (Длина: " << max << ")" << endl;
	cout << "Самое короткое слово: " << shortest << " (Длина:" << min << ")" << endl;
	return 0;
}