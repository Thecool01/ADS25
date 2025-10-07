#include <iostream>
#include <queue>

using namespace std;

int main() {
    long long n;
    cin >> n;

    priority_queue<long long, vector<long long>, greater<long long>> num_arrays; // Очерель, которая хранит числа в порядке возврастания

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        num_arrays.push(x);
    }

    long long sum = 0;

    while (num_arrays.size() != 1) {
        long long x = num_arrays.top(); num_arrays.pop(); // Берем первый элемент и удаляем его
        long long y = num_arrays.top(); num_arrays.pop(); // Берем второй элемент и удаляем его
        num_arrays.push(x + y); // Ищем сумму и пушаем ее
        sum += x + y;
    }
    cout << sum << endl;
    return 0;
}