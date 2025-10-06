#include <iostream>
#include <vector>
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
    if (!root) return new Node(value); // Если пустой

    if (value < root->data) { // Если значение меньше рута -> то пишем влево
        root->left = insert(root->left, value);
    }
    else { // Если значение меньше рута -> то пишем вправа
        root->right = insert(root->right, value);
    }

    return root;
}

int max_lvl = 0;
vector<int> sum(5001);

void counting(Node* root, int lvl) {
    if (!root) return; // Если рут пусто, то заканчиваем рекурсию
    sum[lvl] += root->data; // Сумма лвл-а
    counting(root->left, lvl + 1); // Рекурсивно обходим левое и правое поддерево
    counting(root->right, lvl + 1);
    max_lvl = max(max_lvl, lvl);

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

    counting(root, 0);

    cout << max_lvl + 1 << endl;
    
    for (int i = 0; i <= max_lvl; i++) {
        cout << sum[i] << " ";
    }
    return 0;
}