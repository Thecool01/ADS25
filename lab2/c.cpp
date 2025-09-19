#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    };
};

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int n;
    cin >> n;

    int index = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node* newNode = new Node(x);
        if (index % 2 != 0) {
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        index++;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << ' ';
        temp = temp->next;
    }

    return 0;

}