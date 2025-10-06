#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) { // Структура БИНАРНОГО ДЕРЕВА
        data = value;
        left = nullptr;
        right = nullptr;
    }   
};

Node* insert(const vector<long long> &numbers, int left, int right) {
    if (left > right) return NULL; // Отрезок пуст
    int mid = (left + right) / 2; // ПРИНЦИП БИНАРНОГО ПОИСКА
    Node* newRoot = new Node(numbers[mid]);
    newRoot->left = insert(numbers, left, mid - 1);
    newRoot->right = insert(numbers, mid + 1, right);
    return newRoot;
}

void output(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    output(root->left);
    output(root->right);
}

int main() {
    long long k, n = 1;
    cin >> k;

    for (int i = 0; i < k; i++) {
        n = pow(2, k) - 1;
    }

    vector<long long> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    Node* root = insert(numbers, 0, n - 1); 

    output(root);

    return 0;
}