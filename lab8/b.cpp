#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int d = 256; // количество символов ASCII (0-255)
const int q = 1000003; // простое число для модуля

vector<int> RabinKarpPositions(const string &text, const string &pattern) {
    vector<int> positions;
    int n = text.size();
    int m = pattern.size();

    long long h = 1;
    // h используется позже, чтобы убрать влияние самого левого символа при переходе окна (rolling hash).
    // Например, если шаблон длиной 4,
    // то h = d³ = 256³ (но мы берём по модулю q).

    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    long long p = 0; // Хеш паттерна
    long long t = 0; // Хеш текста

    // вычисляем хеш первого окна и шаблона
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t) { // Если хеши совпадают
            positions.push_back(i);
        }
        

        // Это условие НЕ выполняется только для последнего окна
        // потому что для него нет следующего символа text[i + m]
        if (i < n - m) {
            // Убираем уходящий символ text[i], добавляем новый text[i + m]
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            /*
            Визуальный пример

            Текст:    "abcde", m = 3
            Паттерн: "bcd"

            Шаг 1 (i=0): окно "abc", хеш = (a*d² + b*d + c) % q

            Шаг 2 (i=1): переходим к окну "bcd"
            1. Убираем 'a': хеш - a*d²
            2. Сдвигаем: (хеш - a*d²) * d
            3. Добавляем 'd': + d
            Итого: ((a*d² + b*d + c - a*d²) * d + d) = (b*d + c)*d + d = b*d² + c*d + d
            */
            if (t < 0) t += q;
            /*
            Почему проверка if (t < 0) t += q;?

            При работе с модульной арифметикой, если результат отрицательный, 
            мы приводим его к корректному диапазону [0, q-1].
            */
        }
    }

    return positions;
}

int main() {
    string s1, s2, pattern;
    cin >> s1 >> s2 >> pattern;

    vector<int> pos1 = RabinKarpPositions(s1, pattern);
    vector<int> pos2 = RabinKarpPositions(s2, pattern);

    int count = 0;
    int i = 0, j = 0;

    while (i < pos1.size() && j < pos2.size()) {
        if (pos1[i] == pos2[j]) {
            count++; i++; j++;
        }
        else if (pos1[i] < pos2[j]) i++;
        else j++;
    }

    cout << count << endl;
    return 0;
}