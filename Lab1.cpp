//Дан массив слов. Удалить в каждом слове массиве все символы после символа "*".
//Сформировать подстроку, взяв от каждого слова массива, если это возможно, по n
//символов, начиная с k-ой позиции. Если полученная подстрока не пустая, то
//сформировать предложение из слов массива, длина которых больше n символов,
//циклически сместив в словач символы на n позиций влево.
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	const int z = 20;
	int n, k, quant, m, c, num;
	c = 0;
	num = 0;
	string words[z], str[z], prop[z];
	string s, line;
	cout << "enter quantative words:" << endl;
	cin >> quant;

	for (int j = 0; j < quant; j++)
	{
		cout << "enter word № " << j + 1 << ": " << endl;
		cin >> s;
		words[j] = s;

	}

	if (words->size() > 0) {
		for (int i = 0; i < quant; i++)
		{
			for (int j = 0; j < words[i].size(); j++)
			{
				if (words[i][j] == '*') {
					m = j;
					while (m != words[i].size()) {

						words[i][m] = '\x0';
						m++;
					}
					m = 0;
				}
			}
		}
	}
	cout << "======================================" << endl;
	for (int i = 0; i < quant; i++)
	{
		for (int j = 0; j < words[i].size(); j++)
		{
			cout << words[i][j];
		}
		cout << endl;
	}
	cout << "======================================" << endl;
	cout << "Enter quant simvols (n):" << endl;
	cin >> n;
	cout << "Enter position (k):" << endl;
	cin >> k;

	if (words->size() > 0) {
		for (int i = 0; i < quant; i++)
		{
			if (k <= words[i].size()) {
				for (int j = k; j < words[i].size(); j++)
				{
					if (c < n) {

						line.push_back(words[i][j]);
						c++;
					}
				}
				c = 0;
			}
		}
	}
	cout << "======================================" << endl;
	cout << line << endl;
	cout << "======================================" << endl;
	if (words->size() > 0 && line != "")
	{
		for (int i = 0; i < quant; i++)
		{
			if (n <= words[i].size())
			{
				prop[i] = words[i].substr(n, words[i].size()) + words[i].substr(0, n);
			}
		}
	}
	for (int j = 0; j < quant; j++)
	{
		cout << prop[j] << " ";
	}
	cout << endl;
	cout << "======================================" << endl;
	return 0;
}
