#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    map<int, pair<int, int>> num_coord;

    int l, k;
    cin >> l >> k;

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            num_coord[x] = {i, j}; // Записываем число и его координаты
        }
    }

    for (int i = 0; i < n; i++) {
        if (num_coord.count(numbers[i])) {
            cout << num_coord[numbers[i]].first << ' ' << num_coord[numbers[i]].second << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}