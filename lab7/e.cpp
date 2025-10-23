#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool sort_by_sum(const vector<int>& a, const vector<int>& b) {
    int sum_a = accumulate(a.begin(), a.end(), 0); // Вычисляем сумму вектора через фунцию
    int sum_b = accumulate(b.begin(), b.end(), 0);

    if (sum_a != sum_b) { // Если у нас суммы не равны, то
        return sum_a > sum_b;
    }

    else { // Иначе просто сортируем лексикографически()
        return a < b;
    }
}   


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> rows(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> rows[i][j];
        }
    }

    stable_sort(rows.begin(), rows.end(), sort_by_sum);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << rows[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}