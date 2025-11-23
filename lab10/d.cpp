#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        // У нас граф неориентированный, так что мы можем пройти из v в u и наоборот
        graph[u].push_back(v);
        graph[v].push_back(u);
    
    }

    // Мы используем n + 1 потому что вершины нумеруются с 1 до n, а массивы в C++ индексируются с 0.
    vector<int> dist(n + 1, -1); // Поддерживаем массив dist, где dist[v] - расстояние от вершины v до ближайшей красной вершины.
    vector<bool> is_red(n + 1, false);

    queue<int> bfs_queue;
    

    while(q--) {
        int type, v;
        cin >> type >> v;

        if (type == 1) { // Красим вершину в красный
            if (!is_red[v]) {
                is_red[v] = true;
                dist[v] = 0;
                bfs_queue.push(v);
            }
        }

        else { // Если tipe = 2, запрос расстояние
            
            // Если есть красные вершины, обновляем расстояния BFS
            while (!bfs_queue.empty()) {
                int u = bfs_queue.front();
                bfs_queue.pop();

                for (int neighbor : graph[u]) { // Проверяем соседние вершины
                    if (dist[neighbor] == -1 || dist[neighbor] > dist[u] + 1) {
                        // Если условие выполняется: Обновляем расстояние до соседа, 
                        // Добавляем соседа в очередь для дальнейшего обхода
                        dist[neighbor] = dist[u] + 1;
                        bfs_queue.push(neighbor);
                    }
                }
            }
            cout << dist[v] << endl;
        }
    }
    return 0;

}