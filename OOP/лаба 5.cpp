// лаба 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
	string name; // имя
	int grade; // курс
	int id; // идентификационный номер
	Student()
	{
		name = "ivanov";
		grade = 2;
		id = 991;
	}

	Student(string nm, int kr, int ident)  // Конструктор с параметрами
	{
		name = nm;
		grade = kr;
		id = ident;
	}

	~Student()
	{
	}

	void Print()
	{
		cout << "Name: " << name << "grade: " << grade << "ID: " << id << endl;
	}
};

class Student1 : public Student
{
public:

	string surname;
	string diplom;
	string dip;
	int kurs, ID;
	Student1() : Student()
	{
		dip = "наследование";
	}

	~Student1()
	{

	}

	Student1(string nm, int kr, int ident, string diplom) : Student(nm, kr, ident)
	{
		name = nm;
		grade = kr;
		id = ident;
		dip = diplom;
	}


	void Print()
	{
		cout << "Name: " << name << " grade: " << grade << " ID: " << id << " diplom: " << dip << endl;
	}

	void setdip()
	{
		string value;
		cout << "Введите тему диплома" << endl;
		cin >> value;
		dip = value;
	}

	void setid()
	{
		int value;
		cout << "Введите id " << endl;
		cin >> value;
		id = value;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	string nm, dip;
	int kr, ident;
	cout << "BBeguTe uM9 :";
	cin >> nm;
	cout << "BBeguTe HoMep Kypca :";
	cin >> kr;
	cout << "BBeguTe ID :";
	cin >> ident;
	cout << "BBeguTe TeMy gunJIoMa :";
	cin >> dip;
	Student1 a;             // Создаём объект класса student_1 по умолчанию
	Student1 b(nm, kr, ident, dip);  // Создаём объект класса student_1 с параметрами
	Student1* st = new Student1;
	a.Print();
	b.Print();
	b.setdip();
	b.setid();
	b.Print();
	system("PAUSE");
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
