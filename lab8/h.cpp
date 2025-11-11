#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

using ll = long long;

const int base = 131;
const ll mod = 1e9 + 7;

// Быстрая хеш-функция
ll compute_hash(const string& s) {
    ll h = 0;
    for (char c : s)
        h = (h * base + (c - 'a' + 1)) % mod;
    return h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    vector<string> strings(k);

    for (int i = 0; i < k; i++)
        cin >> strings[i];

    // Находим самую короткую строку
    int min_idx = 0;
    for (int i = 1; i < k; i++)
        if (strings[i].size() < strings[min_idx].size())
            min_idx = i;

    string shortest = strings[min_idx];
    string answer = "";

    // Перебираем длины подстрок от максимальной к минимальной
    for (int len = shortest.size(); len >= 1 && answer.empty(); len--) {

        // Все подстроки данной длины в короткой строке
        unordered_set<string> candidates;
        for (int start = 0; start + len <= shortest.size(); start++)
            candidates.insert(shortest.substr(start, len));

        // Проверяем каждый кандидат
        for (const string& cand : candidates) {
            ll cand_hash = compute_hash(cand);
            bool found_in_all = true;

            // Проверяем наличие кандидата в каждой строке
            for (int j = 0; j < k && found_in_all; j++) {
                if (j == min_idx) continue; // пропускаем самую короткую

                bool found = false;
                for (int t = 0; t + len <= strings[j].size(); t++) {
                    string sub = strings[j].substr(t, len);
                    if (compute_hash(sub) == cand_hash && sub == cand) {
                        found = true;
                        break;
                    }
                }

                if (!found) found_in_all = false;
            }

            if (found_in_all) {
                answer = cand;
                break;
            }
        }
    }

    cout << answer << '\n';
    return 0;
}