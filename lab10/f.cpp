#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }


    vector<bool> passed(n + 1, false);
    queue<int> q;

    int start, end;
    cin >> start >> end;

    // добавляем стартовую вершину
    q.push(start);
    passed[start] = true;

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        if (end == v) {
            cout << "YES" << endl;
            return 0;
        }

        for (int neighbour : graph[v]) {
            if (!passed[neighbour]) {
                passed[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}