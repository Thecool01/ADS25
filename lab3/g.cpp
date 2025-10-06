#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Количество островов и максимальное число полётов
long long n, maxFlights;

// Массив, где хранится количество детей на каждом острове
vector<long long> children;

// Проверяем, можно ли доставить все подарки, если вместимость мешка = capacity
bool canDeliver(long long capacity) {
    long long totalFlights = 0;

    // Для каждого острова считаем, сколько рейсов нужно
    for (long long x : children) {
        // округление деления детей на острове на вместимость сумки
        totalFlights += ceil(x / capacity);

        // Если рейсов уже больше, чем можно — нет смысла дальше считать
        if (totalFlights > maxFlights) return false;
    }

    // Проверяем, уложились ли мы в ограничение по количеству рейсов
    return totalFlights <= maxFlights;
}

int main() {
    // Вводим количество островов и разрешённое число рейсов
    cin >> n >> maxFlights;

    // Заполняем массив количеством детей
    children.resize(n);

    // hi — это максимум детей на одном острове (верхняя граница вместимости)
    long long hi = 0;
    for (int i = 0; i < n; i++) {
        cin >> children[i];
        hi = max(hi, children[i]);
    }

    // lo — минимально возможная вместимость (1 подарок)
    // ans — ответ, который мы будем искать бинарным поиском
    long long lo = 1, ans = hi;

    // Бинарный поиск по вместимости мешка
    while (lo <= hi) {
        long long mid = (lo + hi) / 2; // пробуем вместимость mid

        if (canDeliver(mid)) {
            // Если при такой вместимости уложились в число рейсов,
            // пробуем уменьшить вместимость
            ans = mid;
            hi = mid - 1;
        } else {
            // Иначе — мешок слишком маленький, увеличиваем вместимость
            lo = mid + 1;
        }
    }

    // Выводим минимально возможную вместимость
    cout << ans << endl;
}
