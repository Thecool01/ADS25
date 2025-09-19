#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

int main(){
    Node* head = nullptr;
    Node* tail = nullptr;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node* newNode = new Node(x);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int number, position;
    cin >> number >> position;

    Node* newNode = new Node(number);

    if (position == 0) {
        newNode->next = head; // Связка нового элемента с первым
        head = newNode; // новый элемент теперь head
    }
    else {
        int temp_num = 0;
        Node* temp = head;
        while (temp_num < position - 1 && temp->next != nullptr) {
            temp = temp->next;
            temp_num++;
        }
        /*Это стандартная вставка после узла temp:

        newNode->next = temp->next; — новый узел теперь указывает на тот узел, который был после temp.

        temp->next = newNode; — temp теперь указывает на новый узел.

        Таким образом новый узел оказывается между temp и temp->next (до вставки).

        Примеры

        Список: 10 -> 20 -> 30 -> 40 -> 50, position = 2, вставляем 99.

        Изначально temp = head (10), temp_num = 0.

        Цель: найти узел с индексом position-1 = 1.

        Итерации:

        temp_num < 1 && temp->next != nullptr → 0 < 1 true → temp становится 20, temp_num = 1.

        Теперь temp_num < 1 false → цикл остановился. temp указывает на 20 (индекс 1).

        Вставка:

        newNode->next = temp->next → 99->next = 30

        temp->next = newNode → 20->next = 99

        Результат: 10 -> 20 -> 99 -> 30 -> 40 -> 50

        Вставка в позицию 1 (position = 1):

        position-1 = 0. Условие temp_num < 0 сразу ложное, цикл не выполняется, temp = head. Вставка происходит после head — правильно.

        position больше длины списка:

        цикл дойдёт до последнего узла и остановится, temp — последний узел. Потом newNode->next = temp->next (nullptr), temp->next = newNode — новый узел добавится в конец. (Если у тебя есть tail, нужно его обновить вручную.)

        position == 0:

        ты обрабатываешь этот случай отдельно (вставка в начало): newNode->next = head; head = newNode; — корректно.*/
        newNode->next = temp->next;
        temp->next = newNode;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    return 0;
}