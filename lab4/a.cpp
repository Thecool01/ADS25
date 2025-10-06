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

bool finding_path (string path, Node* root) {
    Node* path_root = root;
    for (int i = 0; i < path.size(); i++) {
        if (path_root == nullptr) return false; // Если путь закончился
        if (path[i] == 'L') path_root = path_root->left; // Идем по правой стороне
        else path_root = path_root->right; // Идем по правой стороне
    }

    if (!path_root) return false;
    else return true;
}

int main() {
    int n, num_paths;
    cin >> n >> num_paths;

    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    for (int i = 0; i < num_paths; i++) {
        string path;
        cin >> path;
        bool path_exist = finding_path(path, root);
        if (path_exist) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}