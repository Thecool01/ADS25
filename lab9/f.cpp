#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> prefix_func(const string &s) {
    int n = s.size();
    vector<int> pi(n, 0); // Создаем массив для хранения значений префикс-функции, инициализируем нулями

    // Проходим по каждому символу строки, начиная со второго (индекс 1)
    for (int i = 1; i < n; i++) { 
        int j = pi[i - 1]; // Берем значение префикс-функции для предыдущего символа

        // Пока j > 0 и символы не совпадают, двигаемся назад по цепочке префиксов
        while(j > 0 && s[i] != s[j]) {
            j = pi[j - 1]; // Переходим к следующему возможному префиксу
        }
        // Проверяем, совпадают ли символы
        if (s[i] == s[j]) j++; // Если совпали, увеличиваем длину совпадающего префикса-суффикса
        pi[i] = j; // Записываем вычисленное значение префикс-функции для текущей позиции
    }
    return pi;
}


int main() {
    string pattern, text;
    cin >> text >> pattern;
    int p_len = pattern.size(), t_len = text.size();
    vector<int> pi = prefix_func(pattern);

    int j = 0; // текущая длина совпадения с pattern
    vector<int> positions;

    for (int i = 0; i < t_len; i++) {
        while (j > 0 && text[i] != pattern[j])
            j = pi[j - 1];
        if (text[i] == pattern[j])
            j++;
        if (j == p_len) { // нашли полное совпадение
            positions.push_back(i - p_len + 2); // +1 для 1-based индексации
            j = pi[j - 1];
        }
    }

    cout << positions.size() << endl;
    for (int pos : positions)
        cout << pos << ' ';
    cout << endl;
}