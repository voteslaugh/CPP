#include <iostream>

using namespace std;

class Queue {
private:
    int* items;
    int front, back, size;

public:
    Queue(int size) {
        items = new int[size];
        this->size = size;
        front = -1;
        back = -1;
    }

    bool isFull() {
        if (front == 0 && back == size-1) {
            return true;
        }
        return false;
    }

    bool isEmpty() {
        if (front == -1)
            return true;
        else
            return false;
    }

    void addEl(int element) {
        if (isFull()) {
            cout << "Очередь заполнена";
        }
        else {
            if (front == -1) front = 0;
            back++;
            items[back] = element;
            cout << endl
                << "Добавлено значение " << element << endl;
        }
    }

    int delEl() {
        int element;
        if (isEmpty()) {
            cout << "Очередь пуста" << endl;
            return (-1);
        }
        else {
            element = items[front];
            if (front >= back) {
                front = -1;
                back = -1;
            }
            else {
                front++;
            }
            cout << endl
                << "Элемент " << element <<" удалён" << endl;
            return (element);
        }
    }

    void display() {
        //Вывод элементов очереди
        int i;
        if (isEmpty()) {
            cout << endl
                << "Пустая очередь" << endl;
        }
        else {
            cout << endl
                << "Передний индекс: " << front;
            cout << endl
                << "Элементы очереди: ";
            for (i = front; i <= back; i++)
                cout << items[i] << "  ";
            cout << endl
                << "Задний индекс: " << back << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    int size=5;
    Queue q(size);

    q.delEl();

    q.addEl(1);
    q.addEl(2);
    q.addEl(3);
    q.addEl(4);
    q.addEl(5);

    // Шестой элемент добавить нельзя
    q.addEl(6);

    q.display();

    q.delEl();

    q.display();

    return 0;
}