#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<bool> used(n + 1, false);
    // После нахождения компоненты мы строим её дерево — BFS-ом от корня.
    vector<int> parent(n + 1, -1);
    // Счётчик детей каждой вершины в BFS-дереве.
    vector<int> children(n + 1, 0);

    int bigFam = 0;


    for (int start = 1; start <= n; start++) {
        if (used[start]) continue; // Если вершина start уже была в какой-то компоненте → пропускаем.


        // BFS находим все вершины компоненты
        
        // Компонента это один кусок графа, где все вершины связаны друг с другом через какие-то пути
        // и нет ни одного ребра, ведущего в другой кусок
        vector<int> comp;
        queue<int> q;
        q.push(start);
        used[start] = true;
        comp.push_back(start);

        while (!q.empty()) {
            int v = q.front(); 
            q.pop();
            for (int to : graph[v]) {
                if (!used[to]) {
                    used[to] = true;
                    q.push(to);
                    comp.push_back(to);
                }
            }
        }
        // 2) находим корень = минимальная вершина компоненты
        int root = *min_element(comp.begin(), comp.end());

        // троим BFS-дерево от корня
        // Мы снова делаем BFS, но уже с целью построить дерево:

        queue<int> tq;
        vector<bool> used1(n + 1, false);

        tq.push(root);
        used1[root] = true;
        parent[root] = -1;
        children[root] = 0;

        // BFS строит дерево и считает детей
        while(!tq.empty()) {
            int v = tq.front(); tq.pop();
            for (int to : graph[v]) {
                if (!used1[to]) {
                    used1[to] = true;

                    parent[to] = v;
                    children[v]++;

                    tq.push(to);
                }
            }
            
        }

        for (int v : comp) {
            if (v == root) {
                bigFam++; // root == bigFam
            }
            else {
                int p = parent[v];
                if (children[v] > children[p]) {
                    bigFam++;
                }
            }
        }
    }
    cout << bigFam << endl;
    return 0;
}