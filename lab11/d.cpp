#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge { // Создаем структура Ребра
    int u, v, cost;
};

// Функция сравнения для сортировки ребер
bool compareEdges(const Edge& a, const Edge& b) {
    return a.cost < b.cost; // Мы сравниваем ребра по их стоимости
}

vector<int> parent;

int find(int x) { // Нахождение КОРНЯ вершин
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

bool unite(int x, int y) { // Функция объединения
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) return false; // Если у двух вершин уже есть одинаковый КОРЕНЬ
    parent[rootY] = rootX; // Если все же нет, то вершина Y будет иметь корень X
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<Edge> edges;

    // Читаем матрицу и создаем список ребер
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { 
            int cost;
            cin >> cost;
            if (i < j) {
                // Добавляем только ребра которые нужно добавить (cost > 0)
                // и только один раз для каждой пары (i < j)
                edges.push_back({i, j, cost});
            }
        }
    }

    // Инициализируем систему непересекающихся множеств
    parent.resize(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    // Сортируем ребра по стоимости с использованием функции сравнения
    sort(edges.begin(), edges.end(), compareEdges);

    int total_cost = 0;
    int components = n; // начальное количество компонент

    // Алгоритм Крускала
    for (const Edge& edge : edges) {
        if (unite(edge.u, edge.v)) { // unite() возвращает true, если ребро соединило разные компоненты
            total_cost += edge.cost;
            components--;
            // Если осталась одна компонента - граф связен
            if (components == 1) break;
        }
    }
    cout << total_cost << endl;

    return 0;

}

