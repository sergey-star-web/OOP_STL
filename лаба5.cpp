// лаба5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<iostream>
#include<string>

using namespace std;
const int st = 40;
const int leng = 30;
const int ts = 100;
const int es = 1000;

string terms[ts], explant[es],terms1,strs;
int arr_nums[ts];
int num = 0, num1 = 0, val = 0;;

void addTerm() {
        
        cout << "Название термина:" << endl;

    condi: 
        getline(cin,terms1);
        if (terms1.length()>leng || terms1.length()==0) {
            cin.clear();
            cout << "Ошибка. Число символов в строке не должно превышать " << leng << " символов. Или в термине нет букв" << endl;
            goto condi;
        }
        else  {
            terms[num] = terms1;
            num++;
        }
    
    cout << "Пояснение:(чтобы закончить цикл напишите:*)" << endl;
    for (int i = 0+num1; i < 5+num1; i++) {
       
       condi1: getline(cin, explant[i]);
        if (explant[i].length() > st || explant[i].length() == 0 ) {
            cin.clear();
            cout << "Число символов в строке не должно превышать " << st << " символов. Напишите название еще раз. Или пустое пояснение." << endl;
            goto condi1;
        }
        val = i;
        if (explant[i] == "*") {
            explant[i].clear();
            break;
        }
    }
    
    num1 = num1 + val;
    arr_nums[num-1] = num1;
    
}

void ViewAllTerms() 
{
    if (num > 0) {
        for (int i = 0; i < num; i++) {
            cout << i + 1 << ") " << "термин:" << endl;
            cout << terms[i] << endl;
            cout << endl;
            cout << "Пояснение:" << endl;
            
            if (i > 0) {
                for (int j = arr_nums[i-1]; j < arr_nums[i]; j++) {
                    if (explant[j] != "") {
                        cout << explant[j] << endl;
                    }
                }
            }
            else {
                for (int j = 0; j < arr_nums[i]; j++) {
                    if (explant[j] != "") {
                        cout << explant[j] << endl;
                    }
                }
            }
           
        }
    }
    else {
        cout << "Ошибка. Нет терминов." << endl;
    }
    
}

void ViewTerm() {
    string term;
    int err=0;
    if (num > 0) {
    term:
        cout << "Введите название термина: " << endl;
        cin >> term;
        if (term.length() > 0) {

            for (int i = 0; i < num; i++) {

                if (term == terms[i]) {
                    cout << i + 1 << ") " << "Термин: ";
                    cout << terms[i] << endl;
                    cout << "Пояснение: " << endl;
                    if (i > 0) {
                        for (int j = arr_nums[i - 1]; j < arr_nums[i]; j++) {
                            cout << explant[j] << endl;
                        }
                    }
                    else {
                        for (int j = 0; j < arr_nums[i]; j++) {
                            cout << explant[j] << endl;
                        }
                    }
                }

                else {
                    err++;
                }
            }
            if (err == num) {
                cout << "Такого термина не существует" << endl;
            }

        }
        else {
            cout << "У вас пустой термин. Нужно ввести." << endl;
            goto term;
        }
    }
    else {
        cout << "Ошибка. Нет терминов." << endl;
    }
}
    
int Exit() {
    exit(0);
}

void main()
{
    setlocale(LC_ALL, "rus");

    int n;

m:cout << "1) Добавить термин" << endl;
    cout << "2) Просмотр всех терминов" << endl;
    cout << "3) Просмотр одного термина" << endl;
    cout << "4) Завершение программы" << endl;
    cin >> n;

    if (n <= 4 || n>0);
    else {
        cout << "Ошибка. Значение должно быть числом от 1 до 4." << endl;
        goto m;
    }


    switch (n) {
    case 1:addTerm(); break;
    case 2:ViewAllTerms(); break;
    case 3:ViewTerm(); break;
    case 4:Exit(); break;
    default: break;
    }

    goto m;
    
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
