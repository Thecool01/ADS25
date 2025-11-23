#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> a(m, vector<int>(n)); // Матрица
    queue<pair<int,int>> q; // Очередь BFS

    // ввод поля
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) {
                q.push({i, j});  // все Marios — старт BFS
            }
        }
    }

    // направления (вверх, вниз, влево, вправо)
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    vector<vector<int>> dist(m, vector<int>(n, 0)); // матрица времени, показывающая, через сколько минут клетка была захвачена Mario.
    int answer = 0; 

    // BFS
    while(!q.empty()) {
        // Берем координату Марио
        int x = q.front().first; 
        int y = q.front().second;

        q.pop();
        
        for (int k = 0; k < 4; k++) {
            // Смотрим все 4 направления (соседние клетки)
            int nx = x + dx[k];
            int ny = y + dy[k];

            // Проверяем — не вышли ли мы за границы поля
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (a[nx][ny] == 1) { // Если соседняя клетка гриб
                    a[nx][ny] = 2; // Превращаем в Марио
                    dist[nx][ny] = dist[x][y] + 1; // Запоминаем, на какой минуте этот Mario появился
                    answer = max(answer, dist[nx][ny]); // Обновляем ответ (максимальное время)
                    q.push({nx, ny}); // Добавляем нового Марио в цикл
                    }
            }
        }
    }

    // проверяем: остался ли гриб
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << answer << endl;
    return 0;
}
