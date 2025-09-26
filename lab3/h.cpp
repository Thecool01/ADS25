#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> index(n);
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (i == 0) {
            index[i] = x; // Если первый элемент
        }
        else {
            index[i] = index[i - 1] + x; // Если последующие прибавляем
        }
    }

    for (int i = 0; i < m; i++) {
        long long b;
        cin >> b;
        int id = lower_bound(index.begin(), index.end(), b) - index.begin(); // Ищем число которое >= b и переводим его в число;
        cout << id + 1 << endl;
    }
    return 0;
}