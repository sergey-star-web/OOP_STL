//Даны натуральное число n и целочисленный массив  из n элементов. 
//Вставить за каждым элементом массива, значение которого кратно заданному значению,
//его номер в исходном массиве. При отсутствии таких элементов выдать соответствующее сообщение.


#include <iostream>
#include <vector>
#include <random>
#include <iterator>

using namespace std;
int main()
{
	int x = 0, n, val, sm = 0;
	cout << "Enter quantative elemetns: " << endl;
	cin >> n;
	vector<int> v(n), c;
	cout << "enter kratnoe: " << endl;
	cin >> x;
	for (int i = 0; i < n; i++) {
		cout << "enter value: " << endl;
		cin >> v[i];

		if (v[i] % x == 0) {
			c.push_back(v[i]);
			c.push_back(i);

		}
		else {
			sm++;
			c.push_back(v[i]);
		}
	}
	cout << endl;
	if (sm == n) {
		cout << "\nMultiple elements are missing" << endl;
	}

	cout << endl;
	copy(c.begin(), c.end(), ostream_iterator<int>(cout, " "));
}



