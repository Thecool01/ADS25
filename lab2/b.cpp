#include <iostream>

using namespace std;

struct Node {
    string data;
    Node* next;
    
    Node(string value) {
        data = value;
        next = nullptr;
    }
};

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int n;
    cin >> n;

    int k;
    cin >> k;

    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        Node* newNode = new Node(x);
        if (head == nullptr) { // Если узел пуст
            head = newNode;
            tail = newNode;
            continue;
        }
        else {
            tail->next = newNode; // указываем значение хвоста newNode
            tail = newNode; // хвост - newNode
        }
    }


    Node* temp = head;
    int temp_num = 0;

    while (temp) {
        if (temp_num >= k) {
            cout << temp->data << ' ';
        }
        temp = temp->next;
        temp_num++;
    }

    temp = head; temp_num = 0;

    while (temp_num < k) {
        cout << temp->data << ' ';
        temp = temp->next;
        temp_num++;
    };


    return 0;
}


