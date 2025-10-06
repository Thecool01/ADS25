#include <iostream>
#include <vector>
using namespace std;

long long n, h;
vector<long long> gold;

// Проверяет, успевает ли Робин за 'h' часов, если он ворует 'cap' слитков в час
bool can(long long cap) {
    long long hours = 0;
    for (long long x : gold) {
        // ceil(x / cap) — сколько часов нужно, чтобы опустошить мешок с x слитками
        hours += (x + cap - 1) / cap;

        // Если уже больше, чем есть часов — нет смысла продолжать
        if (hours > h) return false;
    }
    // Если уложились в лимит — всё хорошо
    return hours <= h;
}

int main() {
    cin >> n >> h;
    gold.resize(n);

    // Считываем мешки и ищем максимальное количество слитков в одном мешке
    // (это верхняя граница для K)
    long long high = 0;
    for (int i = 0; i < n; i++) {
        cin >> gold[i];
        high = max(high, gold[i]);
    }

    // Минимальная возможная скорость — 1 слиток/час
    // Максимальная — равна самому большому мешку
    long long low = 1, ans = high;

    // Бинарный поиск минимального K
    while (low <= high) {
        long long mid = (low + high) / 2; // пробуем скорость mid

        if (can(mid)) {
            // Если с этой скоростью успевает — пробуем меньше
            ans = mid;
            high = mid - 1;
        } else {
            // Если не успевает — нужно увеличить скорость
            low = mid + 1;
        }
    }

    // Выводим минимальное K, при котором успевает
    cout << ans << endl;
}
