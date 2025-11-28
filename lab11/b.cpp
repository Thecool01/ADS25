#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> ducks(n);
    for (int i = 0; i < n; i++) {
        cin >> ducks[i];
    }
    
    // Алгоритм Прима для нахождения MST
    vector<bool> visited(n, false); // Отслеживаем посещенные вершины
    vector<int> minEdge(n, INT_MAX);  // Минимальная стоимость подключения к каждой вершине

    minEdge[0] = 0;    // Начинаем с вершины 0, стоимость подключения к ней = 0
    int totalCost = 0;  // Общая стоимость построенных мостов

    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || minEdge[j] < minEdge[u])) {
                u = j;
            }
        }

        visited[u] = true;
        totalCost += minEdge[u];

        for (int v = 0; v < n; v++) {
            // Для каждой непосещенной вершины v:
            // Вычисляем стоимость моста между u и v: ducks[u] + ducks[v]
            // Если эта стоимость меньше текущей минимальной для v, обновляем minEdge[v]
            if (!visited[v]) {
                int cost = ducks[u] + ducks[v];
                if (cost < minEdge[v]) {
                    minEdge[v] = cost;
                }
            }
        }
    }

    cout << totalCost << endl;
    return 0;
}