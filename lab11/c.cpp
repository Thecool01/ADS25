#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Road {
    int u, v, length;
    int cost;  // вычисленная стоимость
};

vector<int> parent;

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    parent[y] = x;
    return true;
}


bool compareRoad(const Road& a, const Road& b) {
    return a.cost < b.cost;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    int x, y;
    cin >> x >> y;
    
    vector<Road> roads;
    
    for (int i = 0; i < m; i++) {
        string type;
        int a, b, c;
        cin >> type >> a >> b >> c;
        a--; b--;  // переводим в 0-индексацию
        
        Road road;
        road.u = a;
        road.v = b;
        road.length = c;
        
        if (type == "big") {
            road.cost = c * x;
        } else if (type == "small") {
            road.cost = c * y;
        } else {  // "both"
            road.cost = c * min(x, y);  // выбираем дешевый вариант
        }
        
        roads.push_back(road);
    }

    // Инициализация DSU
    parent.resize(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    // Сортируем дороги по стоимости
    sort(roads.begin(), roads.end(), compareRoad);
    
    // Алгоритм Крускала
    int totalCost = 0;
    int edgesUsed = 0;
    
    for (const Road& road : roads) {
        if (unite(road.u, road.v)) { // Поочередно добавляем самые дешевые дороги, которые не создают циклов
            totalCost += road.cost;
            edgesUsed++;
            if (edgesUsed == n - 1) break; // Останавливаемся, когда добавили n-1 дорогу
        } 
    }

    /* Процесс:
    Дорога 1: A-B (стоимость 5) - разные компоненты, добавляем
    Дорога 2: C-D (стоимость 7) - разные компоненты, добавляем
    Дорога 3: B-C (стоимость 8) - соединяет компоненты {A,B} и {C,D}, добавляем
    edgesUsed = 3, n-1 = 3 ⇒ break - ВСЕ ГОРОДА СОЕДИНЕНЫ!
    Дороги 4 и 5 даже не проверяются
    */
    cout << totalCost << endl;
    
    return 0;
}