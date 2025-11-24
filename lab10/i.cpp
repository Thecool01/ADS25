#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    vector<int> dependencies(n + 1, 0); // Количество уровней, чтобы выполнить задание
    
    for (int k = 0; k < m; k++) {
        // В условии сказано, чтобы выполнить J, нужно сделать I
        int i, j;
        cin >> i >> j;
        g[i].push_back(j); 
        dependencies[j]++; // Добавляем количество зависимостей
    }

    // Выполняем те задания, которые не зависят от других
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (dependencies[i] == 0)
            q.push(i);
    }

    vector<int> order; // Очередь выполнения задания

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        order.push_back(v);

        for (int to : g[v]) {
            dependencies[to]--; // Убираем 1 зависимость от тех элементов, который были зависимы от V
            if (dependencies[to] == 0)
                q.push(to);
        }
    }

    int size = order.size();

    if (size != n) { // Если наша очередь отличаеться он количества заданий
        cout << "Impossible" << endl;
        return 0;
    }

    cout << "Possible" << endl;

    for (int i = 0; i < order.size(); i++) {
        cout << order[i] << ' ';
    }    

    return 0;
}
