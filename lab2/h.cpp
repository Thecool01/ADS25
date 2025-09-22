#include <iostream>

using namespace std;

struct Node{

    int data;
    Node* next;

    Node(int value) { // Конструктор с аргументом
        data = value;
        next = nullptr;
    }

    Node(int value, Node* next) { // Конструктор с аргументом и с указателем на следующий узел
        data = value;
        this->next = next;        
    }

};

Node* insert(Node* head, Node* newNode, int p){ // Вставка узла на позицию p
    if (p == 0) {
        newNode->next = head; // Новый узел становиться головой старого узла
        return newNode; 
    }

    Node* temp = head;
    for (int i = 0; i < p - 1; i++) {
        temp = temp->next; // Передвигаемся до позиции p
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* remove(Node* head, int p) { // Удаление элемента на позиции p
    if (!head) {
        return nullptr;
    }
    if (p == 0) {
        Node* temp = head->next; // Если позиция p0, то берем следущий элемент и удаляем голову
        delete head;
        return temp;
    }
    Node* temp = head;
    for (int i = 0; i < p - 1; i++) {
        temp = temp->next;
    }
    Node* del = temp->next; // Сохраняем узел который нужно удалить
    temp->next = del->next; // Передвигаем курсор
    delete del; // Удаляем нужный узел
    return head;
}

Node* replace(Node* head, int p1, int p2) { // Перемещение узла с позиции p1 на позицию p2
    if (p1 == p2) { // Если позиции равны, то ничего не меняется
        return head;
    }

    Node* prev1 = nullptr;
    Node* cursor1 = head;

    for (int i = 0; i < p1; i++) {
        prev1 = cursor1; 
        cursor1 = cursor1->next; // Передвигаемся по позиции p1
    }

    // Извлекаем Сursor1
    if (prev1) { // Удаление: если p1 == 0, то prev1 == nullptr и head сдвигается.
        prev1->next = cursor1->next;
        
    }
    else {
        head = cursor1->next; // !
    }

    // Вставляем в p2
    if (p2 == 0) {
        cursor1->next = head;
        return cursor1;
    }

    Node* cursor2 = head;
    for (int i = 0; i < p2 - 1; i++) {
        cursor2 = cursor2->next;
    }
    cursor1->next = cursor2->next;
    cursor2->next = cursor1; // Вставляем на следущий указатель cursor2

    return head;
/*
Почему такой порядок действий? 
Потому что условие задачи гласит: 
p2 считается после того, 
как узел из p1 уже удалён — 
именно поэтому мы сначала удаляем, 
затем вставляем, использую p2 как 
индекс в сокращённом списке.
*/
}

Node* reverse(Node* head) { // Разворот узлов в обратном порядке
    Node* prev = nullptr;
    Node* temp = head;
    while(temp) {
        Node* nxt = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nxt;
    }
    /* cur -> [1] -> [2] -> [3] -> nullptr

    В теле:
    nxt = cur->next; → nxt указывает на [2].
    cur->next = prev; → меняем стрелку у [1]: теперь [1] -> nullptr.
    prev = cur; → prev указывает на [1] (перевёрнутая часть).
    cur = nxt; → cur теперь указывает на [2].
    Состояние после итерации:
    Перевёрнутая часть (prev): [1] -> nullptr
    Оставшаяся часть (cur): [2] -> [3] -> nullptr*/
    return prev;
}

void print(Node* head) { // Вывод всего узла
    Node* temp = head;
    if (!head) {
        cout << "-1" << endl;
        return;
    }

    while(temp) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}

Node* cyclic_left(Node* head, int x) { // Циклический сдвиг узлов вправо на x (НАЧАЛЬНЫЙ узел передвигается в КОНЕЦ и т.д.)
    if (!head || !head->next) return head; // Если узел пустой или есть только один узел, то ничего не меняется

    int n = 0;
    Node* temp = head;
    while(temp) {
        n++;
        temp = temp->next;
    }
    x %= n; // Делим, чтобы не повторять перемещение;

    if (x == 0) return head; // Если 0 ничего не меняется

    Node* new_tail = head; // Узел, после которого начнется новый список
    for (int i = 0; i < x - 1; i++) {
        new_tail = new_tail->next;
    }
    Node* new_head = new_tail->next; // Новая голова

    Node* tmp = new_head;
    while(tmp->next) {
        tmp = tmp->next;
    }
    
    tmp->next = head; // Соединяем с оставшимся списком
    new_tail->next = nullptr;  // Последний элемент указывает на nullptr 
    
    return new_head;
}

Node* cyclic_right(Node* head, int x) { // Циклический сдвиг узлов влево на x (КОНЕЧНЫЙ узел передвигается в НАЧАЛО и т.д.)
    if (!head || !head->next) return head; // Если узел пустой или есть только один узел, то ничего не меняется

    int n = 0;
    Node* temp = head;
    while(temp) {
        n++;
        temp = temp->next;
    }
    x %= n; // Делим, чтобы не повторять перемещение;
    if (x == 0) return head;
    return cyclic_left(head, n - x); // Сдвиг вправо на x равен сдвигу влево на n - x.
}

int main() {
    Node* head = nullptr;   
    while(true) {
        int command;
        cin >> command;
        if (command == 0) {
            break;
        }
        if (command == 1) {
            int x, p;
            cin >> x >> p;
            head = insert(head, new Node(x), p);
        }   
        if (command == 2) {
            int p;
            cin >> p;
            head = remove(head, p);
        }
        if (command == 3) {
            print(head);
        }
        if (command == 4) {
            int p1, p2;
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }
        if (command == 5) {
            head = reverse(head);
        }
        if (command == 6) {
            int x;
            cin >> x;
            head = cyclic_left(head, x);
        }
        if (command == 7) {
            int x;
            cin >> x;
            head = cyclic_right(head, x);
        }
    }
    return 0;
}

