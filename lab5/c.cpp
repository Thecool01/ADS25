#include <iostream>
#include <queue>

using namespace std;

int main() {
    long long n, people;
    cin >> n >> people;

    priority_queue<int> seats;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        seats.push(x);
    }

    long long sum = 0;

    while(people--) {
        sum += seats.top(); // Плюсуем цену(количество места в ряде)
        int x = seats.top() - 1; seats.pop(); // Одно место заняли -> минусуем 1 место
        seats.push(x); // Пушаем его в наши места
    }
    cout << sum << endl;
    return 0;
}