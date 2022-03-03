// лаба 1.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include<iomanip>
#include<conio.h>
using namespace std;
class employee

{
public:
	string name;
	long volume;
	float price;
	void show_employee(void);
};

void employee::show_employee(void)
{
	setlocale(LC_ALL, "rus");
	cout << "Фирма-производитель:" << name << endl;
	cout << "Обьем жесткого диска:" << volume << endl;
	cout << "цена:" << price << endl;
};

void main(void)
{
	setlocale(LC_ALL, "rus");
	employee laptop1, laptop2, laptop3;

	laptop1.name = "Apple";
	laptop1.volume = 500;
	laptop1.price = 100000;

	laptop2.name = "hp";
	laptop2.volume = 256;
	laptop2.price = 60000;

	laptop3.name = "lenovo";
	laptop3.volume = 1024;
	laptop3.price = 50000;

	laptop1.show_employee();
	laptop2.show_employee();
	laptop3.show_employee();


}
