// Написать программу, которая создает бинарное дерево, состоящее из целых чисел, которые вводятся с клавиатуры. 
//Затем программа выполняет преобразования в соответствии с номером варианта и печатает все числа исходного и 
//преобразованного бинарного дерева (или другой результат работы программы)
//Находит число, ближайшее к среднему арифметическому минимального и максимального чисел в бинарном дереве.

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
