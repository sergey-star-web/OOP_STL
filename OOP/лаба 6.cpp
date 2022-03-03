// лаба 6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>


using namespace std;

class B {
	int a;
public:
	B() { };
	B(int x) { a = x; }
	void show_B() { cout << "B=   " << a << "\n"; }

};

class D1 : public B {
	int b;
public:
	D1(int x, int y) : B(y) { b = x; };
	void show_D1() { cout << "D1=  " << b << "\n"; show_B(); }

};

class D2 : private B {
	int c;
public:
	D2(int x, int y) : B(y) { c = x; };
	void show_D2() { cout << "D2=  " << c << "\n"; show_B(); }
};

class D3 : private B {
	int d;
public:
	D3(int x, int y) : B(y) { d = x; };
	void show_D3() { cout << "D3=  " << d << "\n"; show_B(); }
};

class D4 : private D1, public D2 {
	int e;
public:
	D4(int x, int y, int z, int i, int j) : D1(y,z), D2(i,j) { e = x; };
	void show_D4() {
		cout << "D4=  " << e << "\n"; show_D1(); show_D2();
	}
};

class D5 :  private D3, public D2 {
	int f;
public:
	D5(int x, int y, int z, int i, int j) : D2(y, z), D3(i, j) { f = x; };
	void show_D5() {
		cout << "D5=  " << f << "\n"; show_D2(); show_D3();
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	D4 temp(100, 200, 300, 400, 500);
	D5 temp1(1, 2, 3, 4, 5);
	cout << "D4 temp(100,200,300,400,500);\n";
	cout << "D5 temp1(1,2,3,4,5);\n";
	cout << "\nСледуя иерархии класса D4: \n";
	temp.show_D4();
	cout << "\nСледуя иерархии класса D5\n";
	temp1.show_D5();
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
