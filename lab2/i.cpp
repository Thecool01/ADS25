#include <iostream>

using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev;

    Node(string value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

Node* head = nullptr;
Node* tail = nullptr;

void add_back(string s){
    Node* newNode = new Node(s);

    if (head == nullptr) { // Если пустой 
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->prev = tail; // Новый узел указывает назад на старый хвост
        tail->next = newNode; // Старый узел указывает вперед на новый узел
        tail = newNode; // Новый узел становиться хвостом
    }
    cout << "ok" << endl;
}

void add_front(string s){
    Node* newNode = new Node(s);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head; // Новый узел указывает на старую голову
        head->prev = newNode; // Старая голова ссылается на новый узел 
        head = newNode; // Головой становиться новый узел
    }
    cout << "ok" << endl;
}

bool empty(){
    return head == nullptr;
}

void erase_front(){
    if (empty()) {
        cout << "error" << endl; 
    }
    else {
        cout << head->data << endl;
        Node* temp = head;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next; // Головой становиться предыдщий элемент
            head->prev = nullptr;
        }
        delete temp;
    }
}

void erase_back(){
    if (empty()) {
        cout << "error" << endl;
    }
    else {
        cout << tail->data << endl;
        Node* temp = head;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = tail->prev; // Предыдущий элемент становиться хвостом
            tail->next = nullptr;
        }
        delete temp;
    }
}

void front(){
    if (empty()) {
        cout << "error" << endl;
    }
    else {
        cout << head->data << endl;
    }
}

void back(){
    if (empty()) {
        cout << "error" << endl;
    }
    else {
        cout << tail->data << endl;
    }
}

void clear(){
    Node* temp = head;
    while (temp) {
        Node* nextNode = temp->next; // Следующий элемент
        delete temp; // Очищаем память
        temp = nextNode; // Следующий элемент
    }
    head = nullptr;
    tail = nullptr;
    cout << "ok" << endl;
}


int main() {
    string c;

    while (cin >> c) {
        if(c == "add_front"){
   			string t;
   			cin >> t;
   			add_front(t);
   		}
   		if(c == "add_back"){
   			string t;
   			cin >> t;
   			add_back(t);
   		}
   		if(c == "erase_front"){
   			erase_front();
   		}
   		if(c == "erase_back"){
            erase_back();
   		}
   		if(c == "front"){
   			front();
   		}
   		if(c == "back"){
   			back();
   		}
   		if(c == "clear"){
   			clear();
   		}
   		if(c == "exit"){
   			cout << "goodbye" << endl;
            break;
   		}
    }
}