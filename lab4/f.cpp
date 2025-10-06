#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (!root) {
        return new Node(value);
    }
    if (root->data > value) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }
    return root;
}

int sum = 0;

void count_triangles(Node* &root) {
    if (!root) return;

    else {
        if (root->left != NULL && root->right != NULL) sum++; // Подсчет треугольников
        count_triangles(root->left); // С левой стороны
        count_triangles(root->right); // С правой стороны
    }
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
    
    count_triangles(root);

    cout << sum << endl;
    return 0;
}