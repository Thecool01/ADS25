#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Функция для проверки ацикличности через топологическую сортировку
// Топологическая сортировка - это упорядочивание вершин ориентированного графа так, 
// чтобы все ребра шли слева направо.
bool isAcyclic(int n, vector<vector<int>>& graph, int skip_u = -1, int skip_v = -1) {
    // skip это параметры, который будем использовать чтобы понять какую вершину удалить
    vector<int> indegree(n + 1, 0); // indegree - это "полустепень захода" - количество ребер, которые входят в вершину.

    // Считаем полустепени захода, пропуская одно ребро
    for (int u = 1; u <= n; u++) {
        for (int v : graph[u]) {
            if (u == skip_u && v == skip_v) continue;
            indegree[v]++;
        }
    }

    // Топологическая сортировка через BFS
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    int count = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        count++;
        
        for (int v : graph[u]) {
            if (u == skip_u && v == skip_v) continue;
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    // Если посетили все вершины - граф ациклический
    return count == n;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    vector<pair<int, int>> edges;
    
    // Чтение графа
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        edges.push_back({u, v});
    }
    
    // Проверяем, не ацикличен ли граф уже
    if (isAcyclic(n, adj)) {
        cout << "YES" << endl;
        return 0;
    }
    
    // Пробуем удалить каждое ребро
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        
        if (isAcyclic(n, adj, u, v)) {
            cout << "YES" << endl;
            return 0;
        }
    }
    
    cout << "NO" << endl;
    return 0;
}