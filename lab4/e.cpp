#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int left = -1;
    int right = -1;
};

int main() {
    int n;
    cin >> n;

    vector<Node> tree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0) { // Вписываем влево
            tree[x].left = y; 
        }
        else { // Вписываем вправа
            tree[x].right = y;
        }
    }

    queue<int> q;
    q.push(1); // Вписываем первый корень

    int max_width = 0;
    while(!q.empty()) {
       int size = q.size();
       max_width = max(max_width, size);
       
        for (int i = 0; i < size; i++) {
            int node = q.front(); // Берем вершину и удаляем ее
            q.pop();
            if (tree[node].left != -1) q.push(tree[node].left); // Если вершина имеет левых детей, то добавляем их в очередь
            if (tree[node].right != -1) q.push(tree[node].right); // Если вершина имеет правый детей, то добавляем их в очередь
       }
    }

    cout << max_width << endl;
    return 0;
}
