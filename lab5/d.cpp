#include <iostream>
#include <queue>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    priority_queue<int, vector<int>, greater<int>> densities;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        densities.push(x);
    }

    long long count = 0;

    while(densities.top() < m && densities.size() > 1) { // Пока ТОПОВЫЙ элемент меньше чем нужная плотность и пока все плотности не больше нужной плотности
        long long d_x = densities.top(); densities.pop();
        long long d_y = densities.top(); densities.pop();
        densities.push(d_x + 2 * d_y); // БЕрем последний и предпоследний элемент и через формулу добавляем микстуру
        count++;
    }

    if (densities.top() < m) {
        cout << -1 << endl;
    }
    else {
        cout << count << endl;
    }
    return 0;
}