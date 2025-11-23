#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    
    // Читаем матрицу смежности (1-based индексация)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
    
    // Обрабатываем запросы
    for (int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        // Проверяем все три пары
        if (adj[a][b] == 1 && adj[a][c] == 1 && adj[b][c] == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}