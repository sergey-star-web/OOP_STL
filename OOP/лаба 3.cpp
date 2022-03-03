// лаба 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <iomanip>
#include <cmath>



using namespace std;
#define PI 3.14159265

class Paralelogram {
public:
	double SetD(double Diag);    // Установка угла
	double getD();
	double SetSd1(double Sd1);
	double SetSd2(double Sd2);
	double SetSide(int NumerSide, double Num, char Simv = '.');  // Установить значения  угла
																 // Небольшое пояснение к функции 
																 // (Номер угла, Число на которое нужно изменить, Символ обозначающий прибавление или отрицание угла (не обязательный))
																 // Если не указать 3-й параметр, то будет просто установленно значение в нужную сторону без учета %

	void ShowSide(int NumeSide);    // Показать значение из сторон
	double CalculationArea();       // Вычисление площади и периметра
	double CalculationAngle();   // Вычисление диагонали и стороны
	double CalculationHeight();     // Вычисление высоты

public:
	double D = 0;
	double Area;            // Площадь и периметр
	double Height = 0;      // Значение высоты
	double Diag = 0;          //диагональ
	double Side1;       // 1-я сторона - ОСНОВАНИЕ !!!!
	double Side2;       // 2-я сторона
	double st;         // сторона, которую надо найти
	double p;
	double Ang = 0;
	double Sd1, Sd2;
	char Simv;
};

double Paralelogram::SetSd1(double Sd1)
{
	Side1 = Sd1;
	return Side1;

}

double Paralelogram::SetSd2(double Sd2)
{
	Side2 = Sd2;
	return Side2;

}

double Paralelogram::SetSide(int NumerSide, double Num, char Simv)
{
	if (Side1 <= 0 || Side2 <= 0 || D <= 0 || Ang == 0)
	{
		cout << "увеличение размера сторон не может вызваться" << endl;
	}

	else
	{
		cout << "Введите символ: " << endl;
		cin >> Simv;
		if ((Simv == '+' || '-') && NumerSide == 1);


		if ((Simv == '+' || '-') && NumerSide == 2);

		switch (Simv)
		{



		case '+':   // Увеличиваем значение на Num раз
		{

			if (NumerSide == 1)
			{
				Side1 = Side1*Num;

				return Side1;
			}
			else if (NumerSide == 2)
			{
				Side2 = Side2 * Num;
				return Side2;
			}



			break;
		}

		case '-':   // Уменьшаем значение на Num раз
		{


			if (NumerSide == 1)
			{
				Side1 = Side1 / Num;
				return Side1;
			}
			else if (NumerSide == 2)
			{
				Side2 = Side2 / Num;
				return Side2;
			}

			break;
		}

		default:    // Если параметр не задан, то простая установка
		{
			if (NumerSide == 1)
			{
				Side1 = Num;
				return Side1;
			}

			else if (NumerSide == 2)
			{
				Side2 = Num;
				return Side2;
			}
			break;
		}
		}
	}


}

double Paralelogram::SetD(double Diag)
{
	if (Diag <= Side1 || Diag <= Side2)
	{
		cout << "диагональ должна быть больше сторон " << endl;

		return D = 0;
	}
	else
	{
		D = Diag;
		return D;
	}
}

void Paralelogram::ShowSide(int NumerSide)
{
	if (NumerSide == 1) cout << "Основание = " << Side1 << endl;
	if (NumerSide == 2) cout << "2-я сторона = " << Side2 << endl;
}


double Paralelogram::CalculationAngle() {
	if (D != 0)
	{
		cout << "\n Вычисление угла по теореме косинусов из формулы диагонали: "
			<< "D = sqrt(a^2 + b^2 - 2ab * cos(угол)" << endl;
		//cout << "diagonal: " << cos(((D*D)-(Side1 * Side1)-(Side2 * Side2))/(-2 * (Side1 * Side2))) << endl;
		// (cos(D*D / (((Side1 * Side1) + (Side2 * Side2)) - (2 * (Side1 * Side2)))) =Ang;
		Ang = (cos(((D * D) - (Side1 * Side1) - (Side2 * Side2)) / (-2 * (Side1 * Side2)))) / (PI / 180);
		if (Ang <= 0)
		{
		 Ang = 0;
		}
		cout << "угол равен: " << Ang << endl;
		return Ang;
	}
	else cout << "\nНет необходимых данных. Проверьте значения" << endl;;
	
	
}

double Paralelogram::CalculationArea()
{

	if (D != 0 && Ang != 0) // Узнаем, если имеется угол
	{
		Area = Side1 * Side2 * sin(Ang * (PI / 180));
		cout << "площадь = " << Area << endl;
		cout << "корень из площади = " << sqrt(Area) << endl;

		p = 2 * (Side1 + Side2);
		cout << "периметр = " << p << endl;
		cout << "корень из периметра = " << sqrt(p) << endl;

		return Area;
	}
	else cout << "\nОтсутствуют необходимые значения" << endl;

}

double Paralelogram::CalculationHeight()
{
	if (Area != 0 && D != 0 && Ang != 0)
	{
		Height = (Area / Side1);
		cout << "высота равна: " << Height << endl;
		return Height;
	}

	else
	{
		cout << "\nОтсутствуют необходимые значения" << endl;
		return Height = 0;
	}
}

double Paralelogram::getD()
{
	if (D != 0 || D<0 || Ang!=0)
	{
		D = sqrt((((Side1 * Side1) + (Side2 * Side2)) - (2 * (Side1 * Side2)))*cos(Ang*(PI / 180)));
		cout << "Диагональ = " << D << endl;
	}
	else 
	{
		cout << "\nНет необходимых данных. Проверьте значения";
		D = 0;
		return D;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	Paralelogram Par;               // Создание переменной параллелограмма
	double Sd1, Sd2;
	cout << "\n\nВведите основание: ";
	cin >> Sd1;
	Par.SetSd1(Sd1);
	cout << "\n\nВведите другую сторону: ";
	cin >> Sd2;
	Par.SetSd2(Sd2);
	cout << "\n\nВведите диагональ: ";
	double Diag;
	cin >> Diag;
	cout << "\n\n диагональ параллелограмма = " << Par.SetD(Diag);

	Par.CalculationAngle();

	Par.CalculationArea();

	Par.CalculationHeight();
	char Simv;
	Par.SetSide(1, 4); //увеличиваем основание в 4 раза
	Par.ShowSide(1);
	Par.SetSide(2, 2); //уменьшаем сторону в 2 раза
	Par.ShowSide(2);
	Par.getD();

	Par.CalculationAngle();

	Par.CalculationArea();

	Par.CalculationHeight();

	system("PAUSE");
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
