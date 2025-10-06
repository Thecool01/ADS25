#include <iostream>

using namespace std;

struct Node {
    int data;
    int count;
    Node* right;
    Node* left;

    Node(int value) {
        data = value;
        count = 1;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (!root) {
        root = new Node(value);
        return root;
    }
    if (root->data == value) {
        root->count++;
        return root;
    }
    if (root->data > value) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }
    return root;
}

Node* findMin(Node* root) {
    while(root->left) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int value) {
    if (root == NULL) {
		return NULL;
    }
    else if (root->data > value) {
		root->left = deleteNode(root->left, value);
	} 
    else if (root->data < value) {
		root->right = deleteNode(root->right, value);
	} 
    else {
        if (root->count > 1) {
            root->count--;
            return root;
        } 
        else if (root->right == NULL) {
			Node* temp = root->left;
			delete root;
			return temp;
		} 
        else if (root->left == NULL) {
			Node* temp = root->right;
			delete root;
			return temp;
        } 
        else {
            Node* temp = findMin(root->right); // Идем в правое поддерево и ищем левый элемент(минимальный)
            root->data = temp->data; // Заменяем значение удаляемого узла на значение найденного минимума.
            root->count = temp->count; // Если у этого минимального узла было несколько копий (count > 1), мы переносим это количество в текущий узел.
            temp->count = 1; // Сбрасываем count у старого узла перед его удалением — чтобы при удалении (в рекурсивном вызове ниже) всё отработало корректно, и дерево не пыталось “уменьшать” счётчик несколько раз.
            root->right = deleteNode(root->right, temp->data); // Теперь нужно удалить тот самый узел, значение которого мы только что скопировали.
        }
    }
    return root;
}

int count(Node* root, int value) {
    if (!root) return 0; // Если элемента нет
    if (root->data == value) return root->count; // Если нашли элетент, то возвращаем его повторения в дереве
    if (value < root->data) return count(root->left, value); // Если значение меньше нашего узла, то ищем его левее
    return count(root->right, value); // Если значение больше нашего узла, то ищем его правее
}

int main() {
    int n;
    cin >> n;

    Node* root = NULL;

    string command;
    int x;

    while (n--) {
        cin >> command >> x;

        if (command == "insert") {
            root = insert(root, x);
        }
        else if (command == "delete") {
            root = deleteNode(root, x);
        }
        else if (command == "cnt") {
            cout << count(root, x) << endl;
        }
    }
    return 0;
}