#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    char data;
    Node* next;

    Node(char value) {
        data = value;
        next = nullptr;
    }
};


int main() {
    int n;
    cin >> n;

    while (n != 0) {
        n--;
        int k;
        cin >> k;

        unordered_map<char, int> freq;
        Node* head = nullptr;
        Node* tail = nullptr;
        for (int i = 0; i < k; i++) {
            char c;
            cin >> c;
            freq[c]++; // Считаем сколько раз появилась буква
            
            Node* newNode = new Node(c);
            
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }

            Node* temp = head;
            while (temp && freq[temp ->data] > 1) { // Если буква уже повторялась, то двигает узел
                temp = temp->next; 
            }

            if (!temp) { // Если в конце узел пустой, значит следующей буквы небыло
                cout << -1 << ' '; 
            }
            else { // Иначе выводим последний элемент который не повторялся
                cout << temp->data << ' ';
            }
        }
    cout << endl;
    }
    return 0;
}