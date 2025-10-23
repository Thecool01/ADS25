#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }


    // Сортировка по столбцам
    for (int j = 0; j < m; j++) {
        vector<int> column;
        for (int i = 0; i < n; i++) {
            column.push_back(matrix[i][j]);
        }

        sort(column.rbegin(), column.rend());

        for (int i = 0; i < n; i++) {
            matrix[i][j] = column[i];
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}