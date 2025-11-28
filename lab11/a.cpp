#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int left, right, cost;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.cost < b.cost;
}

vector<int> parent, nxt; // next ключевая оптимизация: хранит следующую несвязанную вершину

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

bool unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) return false;
    parent[rootY] = rootX;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].left >> edges[i].right >> edges[i].cost;
        edges[i].left--; // переводим в 0-индексацию
        edges[i].right--;
    }

    sort(edges.begin(), edges.end(), compareEdges);
    

    parent.resize(n);
    nxt.resize(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        nxt[i] = i + 1; // указывает на следующую вершину
    }

    /* 
    Состояние после инициализации для n=5:
    parent = [0, 1, 2, 3, 4]
    nxt    = [1, 2, 3, 4, 5]
    Каждая вершина - отдельная компонента, nxt[i] указывает на следующую вершину.
    */

    long long total_cost = 0;

    for (const Edge& e : edges) { // Обрабатываем отрезки в порядке увеличения стоимости
    int cur = e.left; // Начинаем с левого конца отрезка
    while (cur < e.right) { // Пока не дошли до правого конца отрезка
        // Пытаемся соединить текущую вершину с правым концом отрезка
        if (unite(cur, e.right)) { // Если вершины были в разных компонентах
            total_cost += e.cost;
        }

        // Если вершины были в разных компонентах
        int temp = nxt[cur]; // Запоминаем следующую вершину для обработки
        nxt[cur] = max(nxt[cur], e.right); // Обновляем указатель, чтобы пропустить обработанные вершины
        cur = temp; // Переходим к следующей вершине
        }
    }  

    cout << total_cost << endl;
    return 0;
}