// лаба 8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Задание: Построить иерархию классов в соответствии с вариантом задания. Построить диаграммы классов.
//12. Создать абстрактный базовый класс список. Реализовать на его базе классы стек и очередь с виртуальными функциями добавления и удаления элементов.

#include <iostream>
using namespace std;

//двусвязной список
template<typename T>
class tlist {
    struct node {
        node* prev;
        node* next;
        T     val;
        node(const T& v) :prev(NULL), next(NULL), val(v) {}
    };
private:
    node* head, * tail;
    int cnt;
public:
    tlist() :head(NULL), tail(NULL), cnt(0) {}
    ~tlist() { clear(); }
    virtual void push(const T& val) = 0;
    virtual void pop(void) = 0;
    void clear() {
        while (head != NULL)
            pop_front();
        cnt = 0;
    }

    bool empty()  const { return (head == NULL); }
    int size() const { return cnt; }
    T& peek() { return head->val; }
protected:

    void push_front(const T& val) {
        node* p = new node(val);
        if (head == NULL)
            head = tail = p;
        else {
            head->prev = p;
            p->next = head;
            head = p;
        }
        ++cnt;
    }

    void push_back(const T& val) {
        node* p = new node(val);
        if (head == NULL)
            head = tail = p;
        else {
            p->prev = tail;
            tail = tail->next = p;
        }
        ++cnt;
    }

    void pop_front() {
        node* t;
        if (head != NULL) {
            t = head;
            head = head->next;
            delete t;
            if (head != NULL)
                head->prev = NULL;
            else
                tail = NULL;
            --cnt;
        }
    }

};

//стек(LIFO)
template<typename T>
class tstack : public tlist<T>
{
public:
    virtual void push(const T& val) { tlist<T>::push_front(val); }
    virtual void pop() { tlist<T>::pop_front(); }
};

//очередь(FIFO)
template<typename T>
class tqueue : public tlist<T>
{
public:
    virtual void push(const T& val) { tlist<T>::push_back(val); }
    virtual void pop() { tlist<T>::pop_front(); }
};

int main()
{
    tstack<int> s;
    for (int c = 0; c <= 10; c++)
        s.push(c);
        s.push(11);
        //s.pop();
        for (; !s.empty(); s.pop())
        {
            cout << s.peek() << endl;
        }
    tqueue<int> q;
    for (int i = 0; i <= 10; ++i)
        q.push(i);
    q.push(111);
   
    for (; !q.empty(); q.pop())
    {
        cout << q.peek() << ' ';
    }

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
