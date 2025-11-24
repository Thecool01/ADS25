#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> map(n);
    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false)); // матрица тех же размеров, чтобы не обойти одну и ту же клетку дважды;

    int islands = 0;

    // направления: вверх, вниз, влево, вправо
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    // dx[0], dy[0] → вниз (x+1, y)
    // dx[1], dy[1] → вверх (x-1, y)
    // dx[2], dy[2] → вправо (x, y+1)
    // dx[3], dy[3] → влево (x, y-1)

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // Нашли новый остров
            
            if (map[i][j] == '1' && !visited[i][j]) {
                islands++;

            // BFS
            queue<pair<int, int>> q; // Здесь используем пару, так как у нас не графа а матрица
            q.push({i, j}); // кладём клетку в очередь
            visited[i][j] = true;

            while(!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k]; // координата строки соседа
                    int ny = y + dy[k]; // координата столбца соседа

                // проверка границ
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        if (map[nx][ny] == '1' && !visited[nx][ny]) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
                }
            }
        }
    }
    cout << islands << endl;
    return 0;
}