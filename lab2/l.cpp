#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }

};

int findMaxSum(int n, Node* head) {
    int currentSum = head->data;
    int maxSum = head->data;

    Node* temp = head->next;
    while(temp) {
        currentSum = max(temp->data, currentSum + temp->data);
        maxSum = max(currentSum, maxSum);
        temp = temp->next;
    }
    return maxSum;
}

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

    cout << findMaxSum(n, head);
}