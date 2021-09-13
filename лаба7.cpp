// лаба7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int tabs = 0, num = 0;

struct Branch
{
	int Data;
	Branch* Left;
	Branch* Right;
};

void Add(int aData, Branch*& aBranch)
{
	if (!aBranch)
	{ 
		aBranch = new Branch;
		aBranch->Data = aData;
		aBranch->Left = 0;
		aBranch->Right = 0;
		return;
	}
	else
		if (aBranch->Data > aData)
		{ 
			Add(aData, aBranch->Left);
		}
		else
		{ 
			Add(aData, aBranch->Right);
		};
}


void print(Branch* aBranch)
{
	cout << endl;
	if (!aBranch) return; 
	tabs++; 
	print(aBranch->Left); 
	for (int i = 0; i < tabs; i++) cout << " "; 
	cout << aBranch->Data << endl; 
	print(aBranch->Right);
	tabs--;
	return;
}

void FreeTree(Branch* aBranch)
{
	if (!aBranch) return;
	FreeTree(aBranch->Left);
	FreeTree(aBranch->Right);
	delete aBranch;
	return;
}

void find_value(vector<int> mass, int n) {
	int min = 1000, max = -1000;
	double sr = 0;
	for (int i = 0; i < n; i++) {
		if (mass[i] < min) {
			min = mass[i];
		}

		if (mass[i] > max) {
			max = mass[i];
		}
	}
	sr = (min + max) / 2;
	min = abs(mass[0] - sr);
	for (int i = 0; i < n; i++)
	{
		if (abs(mass[i] - sr) <= min)
		{
			min = abs(mass[i] - sr);
			num = i;
		}
	}
	cout << "Среднее значение: " << sr << endl;
	cout << "Наиболее близкое к среднему: " << mass[num] << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n, k;
	vector <int> mas;
	Branch* Root = 0;
	cout << "Введите кол-во значений которых хотите ввести: " << endl;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "Введите значение: " << endl;
		cin >> k;
		Add(k, Root);
		mas.push_back(k);
	}

	print(Root);
	find_value(mas, n);
	FreeTree(Root);
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
