

#include <iostream>
#include "employee.h"
#include <fstream>
#include "manip.h"
#include <string>

	void employee::show_employee(void)
	{
		setlocale(LC_ALL, "rus");
		cout << "Фирма-производитель: " << name << endl;
		cout << "Обьем жесткого диска: " << volume << endl;
		cout << "цена: " << price << endl;
	}

	employee::employee()
	{
		name = "пусто";
		volume = 0;
		price = 0;
	}

	employee::employee(string n, int v, float p)
	{
		cout << "вызван конструктор с параметрами " << endl;
		name = n;
		volume = v;
		price = p;
		cout << " Фирма-производитель: " << n << " Обьем жесткого диска: " << v << " цена: " << p << endl;
	}

	employee :: employee(const employee& s)
	{
		cout << "вызван конструктор копирования" << endl;
		name = s.name;
		volume = s.volume;
		price = s.price;
		cout << " Фирма-производитель: " << s.name << " Обьем жесткого диска: " << s.volume << "цена: " << s.price << endl;
	}

	employee::~employee()
	{
		
	}

	

	string employee::GetName()
	{
		return name;
	}
	int employee::GetVolume()
	{
		return volume;
	}
	float employee::GetPrice()
	{
		return price;
	}
	void employee::SetName(string value)
	{
		name = value;
	}
	void employee::SetVolume(int value)
	{
		volume = value;
	}
	void employee::SetPrice(float value)
	{
		price = value;
	}

	
	const bool operator !(const fstream& v1)
	{
		return !(bool)v1;
	}
	

istream& operator>>(istream& is, employee& e)
{
	cout << "Введите фирму ноутбука: " << endl;
	is >> e.name;
	cout << "Введите обьем жесткого диска: " << endl;
	is >> e.volume;
	cout << "Введите цену ноутбука: " << endl;
	is >> e.price;
	return is;
}

int find(fstream& f,employee& emp, int n)
{
	string line,line2;
	int search,num,pos,pos1,itogpos,pos2;
	pos = 0;
	num = 1;
	ifstream file;
	file.open("myfiles.txt");
	cout << "Введите номер ноутбука:" << endl;
	cin >> search;
	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (search > 0 && search <= n)
			{
				pos+=line.length()+2;
				if (search == num)
				{
					pos1 = line.length() + 2;
					pos2 = pos;
					itogpos = pos - pos1;
					cout << "смещение: " << itogpos << endl;
					cout << "Ноутбук найден: " << line << endl;
				}
			}
			else
			{
				cout << "Введите корректный номер ноутбука!" << endl;
			}
			num++;
		}
		file.close();
	}
	return pos2;
}

void del(fstream& f,employee& emp,int n)
{
	cout << "Вызвалась функция удаления" << endl;
	int Pos = find(f, emp,n);
	int Size;
	string line, line2;
	int search, num, pos, pos1, itogpos;
	num = 1;
	pos = 0;
	pos1 = 0;
	fstream file;
	fstream file2;
	file.open("myfiles.txt");
	file2.open("tempname.txt", ofstream::out |ofstream::trunc);
	if (file.is_open())
	{
		while (getline(file, line))
		{
				pos += line.length() + 2;
				if (Pos != pos)
				{
					
					file2 << line << endl;
				}
				
		}
		file.close();
		file2.close();
	}
	else
	{
		cout << "файл не открылся" << endl;
		file.close();
	}
	fstream file3;
	fstream file_t;
	pos = 0;
	pos1 = 0;
	file3.open("myfiles.txt", ofstream::out | ofstream::trunc);
	file_t.open("tempname.txt");
	if (file_t.is_open())
	{
		while (getline(file_t, line2))
		{

			pos += line2.length() + 2;
			
				file3 << line2 << endl;

		}
		file_t.close();
		file3.close();
	}
	else
	{
		cout << "файл не открылся" << endl;
		file_t.close();
	}
	
}

void repl(fstream& f, employee& emp,int n)
{
	ifstream file1;
	string line_pr;
	int num = 1;
	file1.open("myfiles.txt");
	if (!file1.is_open())
		cout << "Файл не может быть открыт!\n";
	else
	{
		while (getline(file1,line_pr))
		{
			cout <<num<<")"<< line_pr << endl;
			num++;
		}
	}
	cout << "Вызвалась функция изменения обьектов" << endl;
	int Pos = find(f, emp,n);
	int Size,volume,price;
	string line, line2,inp_line;
	int search, pos;
	pos = 0;
	fstream file;
	fstream file2;
	file.open("myfiles.txt");
	file2.open("tempname.txt", ofstream::out | ofstream::trunc);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			pos += line.length() + 2;
			if (Pos == pos)
			{
				cout << "Введите изменяемые значения" << endl;
				cout << "Введите фирму ноутбука: " << endl;
				cin >> inp_line;
				cout << "Введите обьем жесткого диска: " << endl;
				cin >> volume;
				cout << "Введите цену ноутбука: " << endl;
				cin >> price;
				file2 << inp_line << " " << volume << " " << price << endl;
			}
			else
			{
				file2 << line << endl;
			}

		}
		file.close();
		file2.close();
	}
	else
	{
		cout << "файл не открылся" << endl;
		file.close();
	}
	fstream file3;
	fstream file_t;
	pos = 0;
	file3.open("myfiles.txt", ofstream::out | ofstream::trunc);
	file_t.open("tempname.txt");
	if (file_t.is_open())
	{
		while (getline(file_t, line2))
		{
			file3 << line2 << endl;
		}
		file_t.close();
		file3.close();
	}
	else
	{
		cout << "файл не открылся" << endl;
		file_t.close();
	}
}

ostream& operator<<(ostream& os, employee& e)
{
	os <<e.name<<" "<<e.volume<<" "<<e.price<< endl;
	return os;
}

int main()
{
	setlocale(LC_ALL, "rus");
	const int k = 5;
	double size, sm,q1 = 0,sm1=0,sm_e;
	int n;
	cout << "введите сколько обьектов нужно ввести, не менее 5: " << endl;
	cin >> n;
	int a[k];
	fstream stream("myfiles.txt", ios::out);
	fmanip(stream, 2, 0, '-');
	string name;
	employee e1;
	if (!stream)
	{
		cout << "ошибка открытия файла " << endl;
	}
	else
	{
		cout << " файл открылся " << endl;
	}
	if (stream.good())
	{
		cout << "Поток не обнаружил ошибку." << endl;
	}
	else
	{
		cout << "ошибка" << endl;
	}
	if (stream.bad())
	{
		cout << "ошибка выделения памяти, отсутствие буфера и т. Д." << endl;
	}
	else
	{
		cout << "ошибок не найдено " << endl;
	}
	for (int i = 1; i < n + 1; i++)
	{
		cin >> e1;
		stream << e1;
		sm = stream.tellg();
		cout << "размер " << i << " объекта: " << sm - sm1 << endl;
		a[i] = sm - sm1;
		sm1 = stream.tellg();
	}
	stream.seekg(0, std::ios::end);
	size = stream.tellg();
	q1 = size / (size / n);
	cout << "Размер файла: " << size << endl;
	cout << "кол-во добавленных обьектов: " << q1 << endl;
	ifstream file;
	file.open("myfiles.txt");
	if (!file.is_open())
		cout << "Файл не может быть открыт!\n";
	else
	{
		const int len = 1000, st = 10;
		static char buff[len][st];

		for (int j = 1; j <= n; j++)
		{
			file.getline(buff[j], len - 1, '\n');
			cout << j << ")" << buff[j] << endl;
		}

	}
	stream.close();
	del(stream,e1,n);

	repl(stream, e1, n);
	
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
