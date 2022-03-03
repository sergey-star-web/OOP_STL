// 7 лаба.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Задание: Построить иерархию классов в соответствии с вариантом задания. Построить диаграммы классов.
//12.Вертолет, дельтаплан, самолет, транспорт

#include <iostream>

using namespace std;

// базовый класс воздушный транспорт
class air_transport
{
protected:
    int i;
public:
    air_transport() {}
    ~air_transport() {} 
    virtual void seti(int c) { }
    virtual void speed() {  }
};

// наследники
class helicopter : public air_transport
{
public:
    void seti(int c) { cout << "Введите скорость вертолета" << endl; cin >> c; i = c; }
    void speed() { cout << "скорость вертолета - " << i <<"км/ч"<< endl; }
};

class hang_glider : public air_transport
{
public:
    void seti(int c) { cout << "Введите скорость дельтаплана" << endl; cin >> c; i = c; }
    void speed() { cout << "скорость дельтаплана - " << i << "км/ч" << endl; }
};

class airplane : public air_transport
{
public:
    void seti(int c) { cout << "Введите скорость самолета" << endl; cin >> c; i = c; }
    void speed() { cout << "скорость самолета - " << i << "км/ч" << endl; }
};

class transport : public air_transport
{
public:
    void seti(int c) { cout << "Введите скорость транспорта" << endl; cin >> c; i = c; }
    void speed() { cout << "скорость транспорта - " << i << "км/ч" << endl; }
};

int main()
{
    setlocale(LC_ALL, "rus");
    air_transport* p = new helicopter;
    p->seti(0);
    p->speed();               
    air_transport* p1 = new hang_glider;  
    p1->seti(0);
    p1->speed();     
    air_transport* p2 = new airplane;
    p2->seti(0);
    p2->speed();
    air_transport* p3 = new transport;
    p3->seti(0);
    p3->speed();
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
