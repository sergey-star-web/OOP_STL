﻿// 2 лабараторная.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <string>
#include<iomanip>

using namespace std;
class employee

{
public:
	string name;
	int volume;
	float price;
	void show_employee(void)
	{
		setlocale(LC_ALL, "rus");
		cout << "Фирма-производитель: " << name << endl;
		cout << "Обьем жесткого диска: " << volume << endl;
		cout << "цена: " << price << endl;
	}
public:
	employee()// конструктор без параметров
	{
		cout << "вызван конструктор без парамтеров "<<endl;
		name = "apple";
		volume = 10;
		price = 20;
		show_employee();
	}

	employee(string n, int v, float p)// конструктор с параметрами
	{
		cout << "вызван конструктор с параметрами " << endl;
		name = n;
		volume = v;
		price = p;
		cout <<" Фирма-производитель: "<< n << " Обьем жесткого диска: "<< v << "цена: "<< p << endl;
	}

	employee(const employee& s)// конструктор копирования
	{
		cout << "вызван конструктор копирования" << endl;
		name = s.name;
		volume = s.volume;
		price = s.price;
		cout << " Фирма-производитель: " << s.name << " Обьем жесткого диска: " << s.volume << "цена: " << s.price << endl;
	}

	~employee()//деструктор
	{
		cout << "вызван деструктор, удален обьект: " << name << endl;
	}

	
	string GetName()
	{
		return name;
	}
	int GetVolume()
	{
		return volume;
	}
	float GetPrice()
	{
		return price;
	}
	void SetName(string value)
	{
		name = value;
	}
	void SetVolume(int value)
	{
		volume = value;
	}
	void SetPrice(float value)
	{
		price = value;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	employee();
	employee* ck = new employee;// выделяем динамическую память для хранения класса в переменную ck
	employee sixseven("lenovo", 500, 60000); //вызов конструктора с параметрами
	employee Copy(sixseven);//вызов конструктора копирования
	cout <<"Указатель на компонент-функцию: "<< ck->GetName()<<endl;
	ck->SetName("acer"); 
	cout <<"новое значение: "<< ck->GetName() << endl;
	cout <<"указатель на обьект: "<< ck->price << endl;
	return 0;
	system("pause");
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
