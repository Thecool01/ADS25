#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500 + 5;

vector<int> g[MAXN];      // список смежности графа
int color[MAXN];          // 0 — не посещен, 1 — в стеке (серый), 2 — обработан
int parent[MAXN];         // для восстановления цикла
int n, m;

int cycv, cycu;           // ребро (u -> v), которым найден цикл
bool found_cycle = false;

// DFS для поиска ЛЮБОГО цикла в графе
void dfs_cycle(int u) {
    color[u] = 1; // покрасили вершину в серый (в процессе обхода)

    for (int v : g[u]) {
        if (color[v] == 0) {
            // идём дальше
            parent[v] = u;
            dfs_cycle(v);
            if (found_cycle) return; // уже нашли цикл — прекращаем
        } 
        else if (color[v] == 1) {
            // нашли обратное ребро — цикл
            cycu = u;
            cycv = v;
            found_cycle = true;
            return;
        }
    }

    color[u] = 2; // покрасили в чёрный — обработано
}

// Проверка, что граф станет ацикличным, если удалить ребро (a -> b)
bool check_without_edge(int a, int b) {
    // сбрасываем цвета
    fill(color, color + n + 1, 0);

    // локальная DFS-функция для проверки циклов
    function<bool(int)> dfs = [&](int u) {
        color[u] = 1;
        for (int v : g[u]) {

            // пропускаем удаляемое ребро
            if (u == a && v == b) continue;

            if (color[v] == 0) {
                if (!dfs(v)) return false;
            } 
            else if (color[v] == 1) {
                // нашли цикл
                return false;
            }
        }
        color[u] = 2;
        return true;
    };

    // запускаем DFS с каждой вершины
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            if (!dfs(i)) return false; // если цикл всё ещё есть
        }
    }
    return true; // цикла нет — граф стал DAG
}

int main() {
    
    cin >> n >> m;

    // читаем граф
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }


    // Ищем один любой цикл в исходном графе
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            dfs_cycle(i);
            if (found_cycle) break;
        }
    }

    // Если циклов нет — граф уже DAG → можно ничего не удалять
    if (!found_cycle) {
        cout << "YES" << endl;
        return 0;
    }

    // Восстанавливаем цикл по найденному обратному ребру (u -> v)

    vector<pair<int,int>> cycle_edges;

    int u = cycu;
    int v = cycv;

    // добавляем обратное ребро
    cycle_edges.push_back({u, v});

    // поднимаемся по parent[] вверх до v, чтобы восстановить весь цикл
    while (u != v) {
        int p = parent[u];
        cycle_edges.push_back({p, u});
        u = p;
    }

    // Пробуем удалить каждое ребро из цикла
    for (auto &e : cycle_edges) {
        int a = e.first;
        int b = e.second;

        // если после удаления этого ребра граф становится DAG
        if (check_without_edge(a, b)) {
            cout << "YES" << endl;
            return 0;
        }
    }

    // если ни одно ребро не помогает — невозможно
    cout << "NO" << endl;
    return 0;
}
