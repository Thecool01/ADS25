#include <iostream>
#include <vector>

using namespace std;

vector<int> parent, comp_size; // size[i] - размер компоненты, где i является корнем

// Функция find: находим корень компоненты вершины x
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Сжатие пути
    }
    return parent[x];
}

// Функция unite: объединяем две компоненты
bool unite(int x, int y) {
    x = find(x);
    y = find(y);

    // Если корни одинаковые - вершины уже в одной компоненте
    if (x == y) return false;

    // ОПТИМИЗАЦИЯ ПО РАЗМЕРУ:
    // всегда подвешиваем меньшую компоненту к большей
    if (comp_size[x] < comp_size[y]) {
        parent[x] = y;   // Компонента x меньше — подвешиваем её к y
        comp_size[y] += comp_size[x]; // Увеличиваем размер большей компоненты
    } else {
        parent[y] = x;   // Компонента y меньше (или равна) — подвешиваем её к x
        comp_size[x] += comp_size[y]; // Увеличиваем размер большей компоненты
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    // Список смежности графа
    vector<vector<int>> graph(n + 1);

    // Считываем m рёбер
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // Массив для хранения ответа (количество компонент после каждого удаления)
    vector<int> ans(n);

    // Инициализация DSU
    parent.resize(n + 1);
    comp_size.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i; // Каждый — отдельная компонента
        comp_size[i] = 1;   // Размер каждой компоненты = 1
    }

    vector<bool> added(n + 1, false); // Отслеживаем, какие вершины уже добавлены
    int components = 0;               // Текущее количество компонент

    // ОБРАТНЫЙ ПОРЯДОК:
    // вместо удаления 1..n, мы добавляем вершины n..1
    for (int i = n - 1; i >= 0; i--) {
        int v = i + 1;   // Вершина, которую "добавляем обратно"
        components++;    // Добавили новую вершину → появилась новая компонента
        added[v] = true; // Помечаем вершину как существующую в графе
        
        // Объединяем с соседями, которые уже добавлены
        for (int u : graph[v]) {
            if (added[u] && unite(v, u)) {
                components--; // Успешное объединение уменьшает количество компонент
            }
        }
        
        ans[v - 1] = components; // Запоминаем количество компонент на шаге i
    }

    // Выводим ответы
    for (int i = 1; i < n; i++) {
        cout << ans[i] << "\n";
    }
    cout << 0 << endl;

    return 0;
}



