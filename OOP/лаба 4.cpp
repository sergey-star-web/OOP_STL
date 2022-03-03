// лаба 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>

using namespace std;

class Komplex

{
private:
    double real, p, phi;
    double image;


public:
    Komplex() {}
    Komplex(double r, double i = 0) : p(r), phi(i) {}
    ~Komplex() {}   // Деструктор
    Komplex operator+(Komplex&);   // Перегрузка оператора сложения
    Komplex operator-(Komplex&);   // Перегрузка оператора вычитания
    Komplex operator*(Komplex&); // Перегрузка оператора умножения
    Komplex operator/(Komplex&); //перегрузка деления
    friend ostream& operator<<(ostream&, Komplex&);
    friend istream& operator>>(istream&, Komplex&);

    Komplex degree(Komplex& fp, int n)
    {
        return Komplex(pow(fp.p, n),n* fp.phi);
    }
};

Komplex Komplex::operator+(Komplex& fp1)
{
    return Komplex(p + fp1.p, phi + fp1.phi);
}

Komplex Komplex::operator-(Komplex& fp1)
{
    return Komplex(p - fp1.p, phi - fp1.phi);
}

Komplex Komplex::operator*(Komplex& fp1)
{
    double i, j;
    i = p * fp1.p;
    j = phi + fp1.phi;
    return Komplex(i, j);
}
Komplex Komplex::operator/(Komplex& fp1)
{
    double i, j;
    i = p / fp1.p;
    j = phi - fp1.phi;
    return Komplex(i, j);
}

ostream& operator<< (ostream& fo, Komplex& fp)
{

    fo << fp.p << "(cos(" << fp.phi << ")+isin(" << fp.phi << "))" << endl;
    fo << fp.p * cos(fp.phi) << "+i" << fp.p * sin(fp.phi) << endl;
    return fo;
}

istream& operator>>(istream& fi, Komplex& fp)
{
    cout << "Введите модуль p: " << endl;
    fi >> fp.p;
    cout << "Введите аргумент phi: " << endl;
    fi >> fp.phi;
    return fi;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Komplex a, b, c, d, r, r1, r2, r3, r4;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cout << "Первое комплексное число = " << a;
    cout << "Второе комплексное число = " << b;
    cout << "третье комплексное число = " << c;
    cout << "четвертое комплексное число = " << d;
    r1 = a + b;
    r2 = c - a;
    r3 = r1 / r2;
    r4 = r3 * d;
    r = b.degree(b, 3) + r4;
    cout << "результат:" << r << endl;
    system("pause");
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
