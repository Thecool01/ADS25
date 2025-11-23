#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int start, end;
    cin >> start >> end;

    // Переходим к индексации с 0
    start--; 
    end--;

    vector<int> dist(n, -1); // вектор расстояний от стартовой вершины до каждой вершины. Инициализируем -1, что обозначает «ещё не посещена / недостижима».
    queue<int> q;

    // BFS
    dist[start] = 0; // Путь от стартовой вершины к самой себе имеет длину 0 рёбер.
    q.push(start);

    while (!q.empty()) { // пока есть вершины для обработки
        int v = q.front(); // берем вершину
        q.pop();

        for (int u = 0; u < n; u++) { 
            if (matrix[v][u] == 1 && dist[u] == -1) { // перебираем все возможные вершины u (от 0 до n-1), и если есть ребро и ещё не посещали, то
                dist[u] = dist[v] + 1; // расстояние до u через v на единицу больше;
                q.push(u); // кладём u в очередь, чтобы потом обработать его соседей.
            }
        }
    }

    cout << dist[end] << endl;
}
