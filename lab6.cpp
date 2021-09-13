/*В программе № 1 выполнить следующее:
1. Создать объект-контейнер в соответствии  с вариантом задания и заполнить его данными, тип которых определяется вариантом задания.
2. Просмотреть контейнер.
3. Изменить контейнер, удалив из него одни элементы и заменив другие.
4. Просмотреть контейнер, используя для доступа к его элементам итераторы.
5. Создать второй контейнер этого же класса и заполнить его данными того же типа, что и первый контейнер.
6. Изменить первый контейнер, удалив из него n элементов после заданного и добавив затем в него все элементы из второго контейнера.
7. Просмотреть первый  и второй контейнеры.
В программе № 2 выполнить то же самое, но для данных пользовательского типа.
В программе № 3 выполнить следующее:
1. Создать контейнер, содержащий объекты пользовательского типа. Тип контейнера выбирается в соответствии с вариантом задания.
2. Отсортировать его по убыванию элементов.
3. Просмотреть контейнер.
4. Используя подходящий алгоритм, найти в контейнере элемент, удовлетворяющий заданному условию.
5. Переместить элементы, удовлетворяющие заданному условию в другой (предварительно пустой) контейнер. Тип второго контейнера определяется вариантом задания.
6. Просмотреть второй контейнер.
7. Отсортировать первый и второй контейнеры по возрастанию элементов.
8. Просмотреть их.
9. Получить третий контейнер путем слияния первых двух.
10. Просмотреть третий контейнер.
11 .Подсчитать, сколько элементов, удовлетворяющих заданному условию, содержит третий контейнер.
12.Определить, есть ли в третьем контейнере элемент, удовлетворяющий заданному условию.
*/
#include <iostream>
#include <list>
#include <set>
#include <iterator>
#include <vector>
#include <deque>
#include <string>

using namespace std;

class exam {
    public:
    string name_st;
    int day;
    int month;
    int year;
    int score;

    bool operator< (const exam& e) const
    {
            if (score == e.score /*&& name_st!= e.name_st/*/) {
                return (name_st<e.name_st );
            }
            //else {
            //    return(day < e.day || month < e.month);
            //}
           
            return score < e.score;
    }

    exam() {
        string ns;
        int d;
        int m;
        int y;
        int s;
        cout << "Введите имя студента: " << endl;
        cin >> ns;
        name_st = ns;
        cout << "Введите день: " << endl;
        cin >> d;
        day = d;
        cout << "Введите месяц: " << endl;
        cin >> m;
        month = m;
        cout << "Введите год: " << endl;
        cin >> y;
        year = y;
        cout << "Введите оценку за экзамен: " << endl;
        cin >> s;
        score = s;
    }

    void show() {
        cout << "\nДата: " << day << "." << month << "." << year << endl;
        cout << "Имя студента: "<< name_st << endl;
        cout << "Оценка за экзамен: " << score << endl;
    }
};

auto delete_list_elem(list<exam>& list1) 
{
    int i=0,k;
    m:cout << "Введите номер студента кот-ого хотите удалить: " << endl;
    cin >> k;
    if (k<0 || k>list1.size()) {
        cout << "Введено не правильно!" << endl;
        goto m;
    }
    for (list<exam>::iterator it = list1.begin(); it != list1.end(); it++)
    {
        if (i == k) {
            return list1.erase(it);
        }
        i++;
    } 
}

auto change(list<exam>& list1)
{
    int i = 0,k;
    m:cout << "Введите номер студента кот-ого хотите изменить: " << endl;
    cin >> k;
    if (k<0 || k>list1.size()) {
        cout << "Введено не правильно!" << endl;
        goto m;
    }
    for (list<exam>::iterator it = list1.begin(); it != list1.end(); it++)
    {
        if (i == k) {
            exam e;
            *it = e;
            return list1;
        }
        i++;
    }
}

auto add_elem(list<exam>& list1)
{
    cout << "\nДобавление элемента: " << endl;
    exam e;
    list1.push_back(e);
    return list1;
}

void show_elements_list(list<exam>& list1) {
    cout << endl;
    cout << "Вывод списка: " << endl;
    for (list<exam>::iterator ii = list1.begin(); ii != list1.end(); ii++)
    {
        (ii)->show();
    }
}

void show_elements_set(set<exam>& set1) {
    cout << endl;
    cout << "Вывод множества: " << endl;
    for (std::set<exam>::iterator it = set1.begin(); it != set1.end(); ++it)
    {
        exam e= *it;
        e.show();
    }
}

auto sort_wane_list_elements(list<exam>& list1) {
    int min = 0;
    vector<exam> vec;
    for (list<exam>::iterator ii = list1.begin(); ii != list1.end(); ii++)
    {
        vec.push_back(*ii);
    }
    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = 0; j < vec.size() - i - 1; j++) {
            if (vec[j].score < vec[j + 1].score) {
                exam e= vec[j];
                vec[j] = vec[j+1];
                vec[j + 1] = e;
            }
        }
    }
    list1.clear();
    for (int i = 0; i < vec.size(); i++)
    {
        list1.push_back(vec[i]);
    }
    return list1;
}

auto sort_rise_list_elements(list<exam>& list1) {
    int min = 0;
    vector<exam> vec;
    cout << endl;
    cout << "Сортировка листа по возрастанию: " << endl;
    for (list<exam>::iterator ii = list1.begin(); ii != list1.end(); ii++)
    {
        vec.push_back(*ii);
    }
    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = 0; j < vec.size() - i - 1; j++) {
            if (vec[j].score > vec[j + 1].score) {
                exam e = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = e;
            }
        }
    }
    list1.clear();
    for (int i = 0; i < vec.size(); i++)
    {
        list1.push_back(vec[i]);
    }
    return list1;
}

set<exam> moving(list<exam>& list1, set<exam>& set1) {
    vector<exam> v;
    deque<exam> d;
    cout << "Вызвана функция перемещения элементов" << endl;
    for (list<exam>::iterator ii = list1.begin(); ii != list1.end(); ii++)
    {
        if (ii->score > 3) {
            exam e = *ii;
            d.push_back(e);
            v.push_back(e);
        }
    }
    for (int i = 0; i < v.size(); i++) {
        set1.insert(v[i]);
    }
    return set1;
}

auto sort_rise_set_elements(set<exam>& set1) {
    int min = 0;
    vector<exam> vec;
    cout << endl;
    cout << "Сортировка множества по возрастанию: " << endl;
    for (set<exam>::iterator ii = set1.begin(); ii != set1.end(); ii++)
    {
        vec.push_back(*ii);
    }
    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = 0; j < vec.size() - i - 1; j++) {
            if (vec[j].score > vec[j + 1].score) {
                exam e = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = e;
            }
        }
    }
    set1.clear();
    for (int i = 0; i < vec.size(); i++)
    {
        set1.insert(vec[i]);
    }
    return set1;
}

auto delete_list_elements(list<exam>& list1)
{
    int i = 0, k1,k2;
    list<exam> list2;
    m:cout << "Введите номер студента от кот-ого хотите удалить студентов: " << endl;
    cin >> k1;
    cout << "Введите номер студента до кот-ого хотите удалить студентов: " << endl;
    cin >> k2;
    if (k1<0 || k2>list1.size() || k2 < k1) {
        cout << "Введено не правильно!" << endl;
        goto m;
    }

    list<exam>::iterator it = list1.begin(); 
    while(it != list1.end()) 
    {
        if (i >= k1 && i<=k2) {
        }
        else {
            list2.push_back(*it);
        }
        i++;
        it++;
    }
    return list2;
}

auto add_all_elements(list<exam>& list1, set<exam>& set1) {
    int i = 0;
    for (std::set<exam>::iterator it = set1.begin(); it != set1.end(); ++it)
    {
        exam e = *it;
        list1.push_back(e);
   
    }
    return list1;
}

void find_element(list<exam>& list1) {
    int i = 0,k;
    m:cout << "Введите номер элемента кот-го хотите найти: " << endl;
    cin >> k;
    if (k<0 || k>list1.size()) {
        cout << "Введено не правильно!" << endl;
        goto m;
    }
    for (list<exam>::iterator ii = list1.begin(); ii != list1.end(); ii++)
    {
        if (i == k) {
            (ii)->show();
        }
        i++;
    }
}

auto merge(list<exam>& list1, set<exam>& set1) {
    deque<exam> d;
    list<exam> list2;
    cout << "\nВызвано слияние контейнеров " << endl;
    for (std::list<exam>::iterator it = list1.begin(); it != list1.end(); ++it)
    {
        exam e = *it;
        list2.push_back(e);
    }
    for (std::set<exam>::iterator it = set1.begin(); it != set1.end(); ++it)
    {
        exam e = *it;
        list2.push_back(e);
    }
    for (std::list<exam>::iterator it = list2.begin(); it != list2.end(); ++it)
    {
        exam e = *it;
        d.push_back(e);
    }
    return d;
}

void show_deque(deque<exam>& d) {
    cout << "\nВывод deque" << endl;
    for (int i = 0; i < d.size(); i++) {
        d[i].show();
    }
}

void how_many_elements(deque<exam>& d) {
    int k,j=0;
    m:cout << "Проверить сколько сту-ов содержат оценку: ";
    cin>>k;
    if (k<1 || k>5) {
        cout << "Введено не правильно!" << endl;
        goto m;
    }
    for (int i = 0; i < d.size(); i++) {
        if (k == d[i].score) {
            j++;
        }
    }
    cout << "Студенты кот-ые содержат оценку:"<<k<<" = "<<j<< endl;
}

void there_an_element(deque<exam>& d) {
    int k;
    m:cout << "Проверить какой студент содержит оценку: ";
    cin >> k;
    if (k < 1 || k>5) {
        cout << "Введено не правильно!" << endl;
        goto m;
    }
    for (int i = 0; i < d.size(); i++) {
        if (k == d[i].score) {
            cout << "Студенты кот-ый содержит оценку:" << k << " : " << d[i].name_st << endl;
        }
    }
}

int End(int k) {
    return k=4;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int n,k;
    
    cout << "Введите кол-во студентов кот-ых нужно ввести: " << endl;
    cin >> n;
    list<exam> listok;
    set<exam> kont2;
    for (int i = 0; i < n; i++) {
        exam p;
        listok.push_back(p);
    }

    show_elements_list(listok);

    do 
    {
      m:cout << "1) Добавить элемент" << endl;
        cout << "2) Изменить элемент" << endl;
        cout << "3) Удалить элемент" << endl;
        cout << "4) Завершение цикла" << endl;
        cin >> k;

        if (k <= 4 || k > 0);
        else {
            cout << "Ошибка. Значение должно быть числом от 1 до 4." << endl;
            goto m;
        }

        switch (k) {
        case 1:add_elem(listok); show_elements_list(listok); break;
        case 2:change(listok); show_elements_list(listok); break;
        case 3:delete_list_elem(listok); show_elements_list(listok); break;
        case 4:End(k); break;
        default: break;
        }
        
    } while (k != 4);
    
    cout << "Введите кол-во студентов которыми хотите заполнить второй контейнер: " << endl;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        exam e;
        kont2.insert(e);
    }
    show_elements_set(kont2);
    listok = delete_list_elements(listok);
    cout << "\nПосле удаления:" << endl;
    show_elements_list(listok);
    add_all_elements(listok, kont2);
    cout << "\n" << endl;
    show_elements_list(listok);
    cout << "\n" << endl;
    show_elements_set(kont2);
    
    cout << "\nНачало 3 программы: " << endl;
    list<exam> kont1_3p;
    set<exam> kont2_3p;
    cout << "Введите кол-во обьектов кот-ых хотите добавить: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        exam p;
        kont1_3p.push_back(p);
    }
    show_elements_list(kont1_3p);
    kont1_3p=sort_wane_list_elements(kont1_3p);
    show_elements_list(kont1_3p);
    cout << "Введите кол-во элементов кот-ых хотите найти: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        find_element(kont1_3p);
        kont2_3p = moving(kont1_3p, kont2_3p);
    }
    show_elements_set(kont2_3p);
    sort_rise_list_elements(kont1_3p);
    show_elements_list(kont1_3p);
    sort_rise_set_elements(kont2_3p);
    show_elements_set(kont2_3p);
    deque<exam> kont3_3p;
    kont3_3p = merge(kont1_3p, kont2_3p);
    show_deque(kont3_3p);
    do
    {
      q:cout << "1)Подсчитать, сколько элементов, удовлетворяющих заданному условию" << endl;
        cout << "2) Определить, есть ли в третьем контейнере элемент, удов-ий заданному условию." << endl;
        cout << "3) Завершение цикла" << endl;
        cin >> k;

        if (k <= 3 || k > 0);
        else {
            cout << "Ошибка. Значение должно быть числом от 1 до 3." << endl;
            goto q;
        }

        switch (k) {
        case 1:how_many_elements(kont3_3p); break;
        case 2:there_an_element(kont3_3p); break;
        case 3:End(k); break;
        default: break;
        }

    } while (k != 3);
   
}
