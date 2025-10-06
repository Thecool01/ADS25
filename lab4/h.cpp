#include <iostream>
#include <algorithm>

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

Node* insert(Node* root, int value) {
    if (!root) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }
    return root;
}

// ИЗМЕНЕНИЕ ЗНАЧЕНИЙ НА СУММЫ
void transform(Node* root, int &sum) {
    if (!root) return;
    transform(root->right, sum); // сначала рекурсия в правое поддерево
    sum+= root->data; // потом работа с текущим узлом
    root->data = sum; // заменяем значение
    transform(root->left, sum); // потом рекурсия в левое поддерево
}



// ВЫВОД
void print_tree(Node* root) {
    if (!root) return;
    print_tree(root->right);
    cout << root->data << " ";
    print_tree(root->left);
}

int main() {
    int n;
    cin >> n;
    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    int sum = 0;
    transform(root, sum);
    print_tree(root);
    return 0;
}