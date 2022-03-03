// 9 лаба.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include <random>
using namespace std;

//класс исключения деления на ноль
class ZeroDivideException
{
public:
    int idx;
    ZeroDivideException(int i)
    {
        idx = i;
    }
};

// класс исключения "корень из отрицательного числа"
class SqrtException
{
public:
    int idx;
    SqrtException(int i)
    {
        idx = i;
    }
};

//класс исключения "выход за пределы индексов массива"
class IndexException
{
public:
    int idx;
    IndexException(int i)
    {
        idx = i;
    }
};

//функция установки очередного значения массива
void SetValue(double val, int i, int n, double* ar)
{
    if (val == 0) //пытаемся делить на ноль
    {
        ar[i] = 0.0;
        throw ZeroDivideException(i);
    }
    if (val < 0) //пытаемся извлечь корень из отрицательного числа
    {
        ar[i] = 0.0;
        throw SqrtException(i);
    }
    if (i > n) //недопустимый индекс массива
    {
        throw IndexException(i);
        ar[i] = sqrt(1 / val); //нормальная ситуация
    }

    if (val > 0)
    {
        ar[i] = val;
    }

    else
    {
        ar[i] = 0.0;
        throw ZeroDivideException(i);
    }
}

//функция печати массива
void Print(int i, int n, double* ar)
{
    if (i > n) //недопустимый индекс массива
    {
        throw IndexException(i);
        cout << ar[i] << ' ' << endl;
    }
}
void main()
{
    setlocale(LC_ALL, "rus");
    int n1 = 20;
    int n2 = 15;
    int n3 = 25;
    double* a = new double[n1];
    double* b = new double[n2];
    double* c = new double[n3];
    double x = -2.0;
    double res = 0;
    int k = 0;
    for (int i = 0; x <= 2.0; i++, x += 0.2)
    {
        try
        {
            res = log(1 / (x + 1));
            cout << res << endl;
            SetValue(res, i, n1, a); //пытаемся сформировать массив
        }
        catch (ZeroDivideException ex) //перехват исключений
        {
            cout << "Zero divide error in index " << ex.idx << endl;
        }
        catch (SqrtException ex)
        {
            cout << "Sqrt error in index " << ex.idx << endl;
        }
        catch (IndexException ex)
        {
            cout << "Index out of range in index " << ex.idx << endl;
        }
    }
    cout << "-------------------------------------------------------------" << endl;
    for (int i = 0; i <= 2 * n1; i++) //генерация некорректного доступа
    {
        try
        {
            Print(i, n1, a); //пытаемся распечатать массив
        }
        catch (IndexException ex) //перехват исключений
        {
            cout << "Index out of range in index " << ex.idx << endl;
        }
    }
    
    
    cout << endl;
    cout << "-------------------------------------------------------------" << endl;
    for (int i = 0; i <= n2; i++)
    {
       
            res = rand() % 10 ;
            cout << res << endl;
            //SetValue(res, i, n2, b); //пытаемся сформировать массив
        
    }
    cout << "-------------------------------------------------------------" << endl;
    for (int i = 1; i <= n3; i++)
    {
        try
        {
            res = sqrt(a[i-1]+b[i+1]);
            //cout << res << endl;
            SetValue(res, i, n2, c); //пытаемся сформировать массив
        }
        catch (ZeroDivideException ex) //перехват исключений
        {
            cout << "Zero divide error in index " << ex.idx << endl;
        }
        catch (SqrtException ex)
        {
            cout << "Sqrt error in index " << ex.idx << endl;
        }
        catch (IndexException ex)
        {
            cout << "Index out of range in index " << ex.idx << endl;
        }
    }
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
