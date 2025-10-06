#include <iostream>

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

void insert(Node* &root, int value) {
    if (!root) {
        root = new Node(value);
        return;
    }
    if (root->data > value) {
        insert(root->left, value);
    }
    else if (value > root->data){
        insert(root->right, value);
    }
}

int max_diameter = 0;

int depth(Node* root) {
    if (root == NULL) return 0;

    int left = depth(root->left);
    int right = depth(root->right);

    max_diameter = max(max_diameter, left + right); // диаметр через текущую вершину рёбра к детям
    return 1 + max(left, right); // глубина (+1 потому что считаем и сам узел)
}

int main() {
    int n, x;
    cin >> n;
    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(root, x);
    }

    depth(root);
    cout << max_diameter + 1 << endl;
    return 0;
}