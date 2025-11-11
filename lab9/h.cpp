#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int count = 0;

    // A+C = B+C => A=B

    /*
    Len это длина подстроки А и B
    Мы перебираем все возможные длины a начиная с 1.

    len * 2 < n мы берем потому что строка состоит из трёх частей a + b + c,
    где a и b одинаковые, и c должно быть непустым.

    После двух частей a должно остаться хотя бы один символ для c,
    то есть 2 * len < n.
    */
    for (int len = 1; len * 2 < n; len++) {
        if (s.substr(0, len) == s.substr(len, len)) count++; // Если A и B одинаковы
    }

    cout << count << endl;
    return 0;
}