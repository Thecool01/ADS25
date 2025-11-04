#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    /*
    Считать N

    Считать массив p[0..N-1]

    Для i = 0:
    S[0] = 97 + p[0]

    Для i ≥ 1:
    S[i] = 97 + (p[i] - p[i-1]) / 2^i

    Вывести строку, преобразуя к char
    */

    int n;
    cin >> n;
    vector<long long> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

     string result;

    for (int i = 0; i < n; i++) {
        long long diff;
        if (i == 0) diff = p[i];
        else diff = p[i] - p[i - 1];

        // вычисляем 2^i
        long long power = 1LL << i;

        // находим (S_i - 97)
        long long value = diff / power;

        // преобразуем обратно в символ
        char c = static_cast<char>(value + 97);
        result += c;
    }

    cout << result << endl;
    return 0;
}