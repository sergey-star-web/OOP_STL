//Дана целая матрица A[n][n]. Если минимальный элемент каждой последующей строки меньше 
//минимального элемента предыдущей строки, то максимальный по модулю элемент матрицы
//добавить к элементам из заданного интервала [a,b] всех четных столбцов матрицы.
//найти номер первой строки, не содержащей ни одного четного элемента, и циклически
//сдвинуть в ней элементы так, чтобы элемент главной диагонали стал первым элементом
//строки. Отсортировать заданный столбец матрицы по возрастанию. Удалить из матрицы 
//строку, в которой больше всего отрицательных элементов.
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    vector<vector<int>> arr;
    vector<int> sor;
   
    int n,val=0, max_v=0,cyc=0, min_v=0,num=0,a,b,num1=2,num2=0,vals=0;
    cout << "Введите кол-во строк и столбцов: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(vector<int>());
        for (int j = 0; j < n; j++)
        {
            arr.back().push_back(val=rand()%31-15);
            cout << val << " ";
            max_v = max(max_v, abs(val));
        }
        cout << endl;
    }
    cout << "Максимальное значение: " << max_v << endl;
    cout <<"====================================================\n";
    for (vector<vector<int> >::iterator it = arr.begin(); it != arr.end(); ++it) {
        
        for (vector<int>::iterator nit = (*it).begin(); nit != (*it).end(); ++nit) {
            cout << *nit <<" ";
            
            min_v = min(min_v, *nit);
        }
        cout << "min: " << min_v << endl;
        if (num > 0) {
            if (min_v < cyc) {

                cout << "значение меньше " << endl;
                cout << "Введите значениe a: " << endl;
                cin >> a;
                cout << "Введите значениe b: " << endl;
                cin >> b;
                for (vector<vector<int> >::iterator i = arr.begin(); i != arr.end(); ++i) { //ко всем элементам чет-ого столбца прибавляется max_v
                    for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); ++j) {
                        num1++;
                        if (num1 % 2 == 0 && *j>=a && *j<=b) {
                            *j = *j + max_v;
                        }
                    }
                }
            }
            else {

                cout << "не меньше" << endl;
            }
        }
        else {
            cyc = min_v;
        }
        cyc = min_v;
       
        min_v = 100;
        num++;
        cout<<endl;
    }
    cout << "====================================================\n";
    num = 0;
    num1 = 0;
    int line = 0,main=0,value=0;
    for (vector<vector<int> >::iterator i = arr.begin(); i != arr.end(); ++i) {
        num++;
        for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); ++j) {
            num2++;
            cout << *j << " ";
            value = *j;
            if (*j % 2 != 0) {
                num1++;
            }
        }
        if (num1 == num2 && line==0) {
            line = num;
        }
       
        num2 = 0;
        num1 = 0;
        cout << endl;
    }
    if (line != 0) {
        cout << "Первая строка: " << line <<" не содержит четные числа: " << endl;
        cout << "число на главной диагонали: " << arr[line-1][line-1] << endl;
        num = -1;
        num1 = 0;
        num2 = 0;
        for (int i = 0; i < arr.size(); ++i) {               //сдвиг элементов
            for (int j = 0; j < arr[i].size(); ++j) {
                if (i == line - 1 && j <= arr[i].size() - line && i != 0) {
                    value = arr[i][j];
                    arr[i][j] = arr[i][line - 1 + j];
                    num1 = arr[i][line - 2 + j];
                    if (i > (n / 2) && i != n - 1) {
                        arr[i][line - 2 + j] = value;
                    }
                    else {
                        arr[i][line - 1 + j] = value;
                    }
                    if (i == n - 1) {
                        arr[i][line + j - 1] = value;
                    }
                    if (j == 0 && i != n - 1) {
                        num2 = num1;
                    }
                    if (j == arr[i].size() - line && i != 0 && i != n - 1) {
                        arr[i][arr[i].size() - 1] = num2;
                    }
                }
            }
        }
    }
    else {
        cout << "В матрице в каждой строке есть четные числа" << endl;
    }
  
    
    cout << endl;
    for (vector<vector<int> >::iterator i = arr.begin(); i != arr.end(); ++i) {
        for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); ++j) {
            cout << *j << " ";
        }
        cout << endl;
    }
    cout << "====================================================\n";
    int col;
    num = -1;
    cout << "Введите столбец для сортировки от 0 до "<<n-1 << endl;
    cin >> col;
    cout << endl;
    for (vector<vector<int> >::iterator i = arr.begin(); i != arr.end(); ++i) {
        for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); ++j) {
            num++;
            if (num == col) {
               
                sor.push_back(*j);
            }
        }
        num = -1;
    }
    
    sort(sor.begin(), sor.end());

    cout << endl;
    num = -1;
    num1 = -1;

    for (vector<vector<int> >::iterator i = arr.begin(); i != arr.end(); ++i) {
        for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); ++j) {
            num++;
            if (num == col) {
                num1++;
                *j=sor[num1];
            }
            cout << *j << " ";
        }
        num = -1;
        cout << endl;
    }

    cout << "====================================================\n";
    num = -1;
    num1 = 0;
    num2 = 0;
    int st = 0;

    for (vector<vector<int> >::iterator i = arr.begin(); i != arr.end(); ++i) {
        num++;
        for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); ++j) {
            if (*j < 0) {
                num1++;
            }
            if (num1 > num2) {
                st = num;
            }
            num2 = max(num2, num1);
        }
        num1=0;
    }

    if (st != 0) {
        cout << "строка в которой больше всего отриц элементов: " << st << endl;
    }
    else {
        cout << "В матрице нет отрицательных элементов" << endl;
    }
    arr.erase(remove(arr.begin(), arr.end(), arr[st]), arr.end());
    for (vector<vector<int> >::iterator i = arr.begin(); i != arr.end(); ++i) {
        for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); ++j) {
            cout << *j << " ";
        }
        cout << endl;
    }
   
    cout << "====================================================\n";
}

