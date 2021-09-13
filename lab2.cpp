//Спомощью текстового редактора создать файл, содержащий текст
//длина которого не превышает 1000 символов(длина строки текста не должна
//превышать 70 символов
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int show()
{
	int num = 0;
	string buf;
	ifstream file("D:\\ООП\\2 семестр\\file.DAT");
	while (getline(file, buf))
	{
		num++;
		cout << num << ")"; 
		cout << buf << endl;
	}
	cout <<"============================================"<<endl;
	file.close();
	return 1;
}

int count()
{
	const int z = 1000;
	int num=0,count=0,a=0,str=0,k=0,i1=0,q=0;
	string list[z],list_nums[z],nums[z],ind[z],max_nums[z];
	string buf,values;
	char st;
	ifstream file("D:\\ООП\\2 семестр\\file.DAT");
	while (getline(file, buf))
	{
		list[num] = buf;
		num++;
	}
	
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < list[i].length(); j++)
		{
			if (isdigit(list[i][j]) || list[i][j]==' ')
			{
				if (list[i][j] != ' ')
				{
				   //cout << list[i][j];
				   list_nums[i1].push_back(list[i][j]);
				   count++;
				}
			}
			
			else {
				if (!list_nums[i1].empty()) {
					nums[k] = list_nums[i1];
					ind[k] = to_string(i+1);
					cout << nums[k]<<endl;
					k++;
				}
				a = max(a, count);
				count = 0;
				i1++;
			}
		}
	}
	count = 0;
	
	cout << "max length nums: " << a << endl;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < nums[i].length(); j++) {
			count++;
			if (count == a) {
				cout << "max str: " << nums[i] << " num str: " << ind[i] << endl;
				max_nums[q] = nums[i];
				q++;
			}
		}
		count = 0;
	}
	cout << "============================================" << endl;
	cout << "Введите enter чтобы вывести посл-ть или любую другую клавишу для остановки" << endl;
	for (int i = 0; i < q; i++) {
		
		st = cin.get();
		if (st == '\n') {

			cout << max_nums[i] << endl;

		}
		else {
			return 0;
		}
	}
	file.close();
	cout << "============================================" << endl;
	return 1;
}
int main()
{
	setlocale(LC_ALL, "rus");
	show();
	count();

}
