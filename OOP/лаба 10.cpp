/*Порядок выполнения работы.
1. Определить пользовательский тип данных (класс). Определить и реализовать в нем конструкторы, деструктор, операции присваивания, ввода и вывода для стандартных потоков.
2. Написать программу № 1 для создания объектов пользова-тельского класса (ввод исходной информации с клавиатуры с использованием перегруженной операции “>>) и сохранения их в потоке (файле). Предусмотреть в программе вывод сообщения о количестве сохраненных объектов и о длине полученного файла в байтах.
3. Выполнить тестирование программы. 
4. Реализовать для вывода в поток свой манипулятор с параметрами.
5. Написать программу № 2 для чтения объектов из потока, сохранения их в массиве и просмотра массива. Для просмотра объектов использовать перегруженную для cout операцию << и свой манипулятор. Предусмотреть в программе вывод сообщения о количестве прочитанных объектов и байтов.
6. Выполнить программу для чтения из файла сохраненных предыдущей программой объектов и их просмотра. 
7. Написать программу № 3 для добавления объектов в поток.
8. Выполнить программу, добавив в поток несколько объектов и просмотреть полученный файл. 
9. Написать программу № 4 для удаления объектов из файла.
10. Выполнить программу, удалив из потока несколько объектов и просмотреть полученный файл.


11. Написать программу № 5 для корректировки (т.е. замены) записей в файле.
12. Выполнить программу и просмотреть полученный файл.

Методические указания.
1. В качестве пользовательского типа данных взять класс из лабораторной работы № 2. 
2. В совокупности программы должны использовать все классы потоков: istream, ostream, fstream, ifstream, ofstream.
3. Также в программах следует показать все три способа создания потока и открытия файла (см. выше).
4. Необходимо продемонстрировать чтение из файла и запись в файл как с помощью функций read/write, так и с помощью перегруженных операций >> и <<.
5. Пользовательский манипулятор создается с не менее чем с двумя параметрами.
6. Определение пользовательского класса сохранить в h-файле.
7. Определение компонентных функций пользовательского класса сохранить в cpp-файле.
8. Реализацию манипулятора сохранить в h-файле.
В качестве параметров манипулятора можно использовать:
а) ширину поля вывода;
б) точность вывода вещественных чисел;
в) символ-заполнитель;
г) способ выравнивания (к левой или правой границе)
и т.д.
9. В поток записать не менее 5 объектов.
10. После записи объектов в файл и перед чтением их из файла определить количество записанных объектов и вывести эту информацию.
Определить количество записанных в файл объектов можно следующим образом:
а) стать на конец файла  функции seekp(),seekg();
б) определить размер файла в байтах  функции tellp(),tellg();
в) определить количество записанных объектов - размер файла поделить на размер объекта.
11. Необходимо тестировать ошибки при работе с файлом. Для этого следует использовать перегруженные операции operator!(),operator void*() и функции bad(),good().

12. Поскольку в файле может храниться любое, заранее не известное, количество объектов, для их сохранения в программе № 2 при чтении из файла использовать динамический массив.
13. Следует определить функцию find(), которая принимает значение ключевого поля объекта и возвращает смещение этого объекта от начала файла. Вызывать эту функцию перед удалением/изменением объекта в файле. 
14. Для изменения и удаления объекта написать функции del() и repl(), которым передается ссылка на поток, смещение от начала файла изменяемой или удаляемой записи (результат вызова функции find), новое значение изменяемой записи.
*/

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
