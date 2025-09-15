#include <iostream>

using namespace std;

class Stack{
private:
    int* arr;
    int capacity;
    int top;


public:
    Stack(int size) {
        arr = new int[size]; // new оператор динамического выделения памяти в C++. Он «просит» у операционной системы память под объект
        capacity = size; // размер
        top = -1; // индекс верхнего элемента
    }

    // Добавить
    void push(int x ) {
        if (isFull()) {
            cout << "Stack is full!" << endl;
            return;
        }
        arr[++top] = x;
    }
    
    // Убрать
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        top--;
    }

    int top_element() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        return arr[top];
    }

    // Проверки на пустоту и заполненность

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    int size() {
        return top + 1;
    }
};


int main() {
    Stack st(5);
}