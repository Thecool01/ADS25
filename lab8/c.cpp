#include <iostream>
#include <vector>
#include <string>

using namespace std;

using ll = long long;
const int base = 131;
const ll mod = 1e9 + 7;

ll compute_hash(const string& s) {
    ll h = 0;
    for (char c : s) {
        h = (h * base + (c - 'a' + 1)) % mod;
    }
    return h;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int len_s = s.length();

    int n;
    cin >> n;

    vector<string> tapes(n);
    vector<ll> hashes(n);
    vector<int> lengths(n);

    for (int i = 0; i < n; i++) {
        cin >> tapes[i];
        hashes[i] = compute_hash(tapes[i]);
        lengths[i] = tapes[i].length();
    }

    // Предподсчет степеней base
    vector<ll> pow_base(len_s + 1);
    pow_base[0] = 1;
    for (int i = 1; i <= len_s; i++) {
        pow_base[i] = (pow_base[i - 1] * base) % mod;
    }

    // Хеши префиксов
    vector<ll> pref_hash(len_s + 1);
    for (int i = 0; i < len_s; i++) {
        pref_hash[i + 1] = (pref_hash[i] * base + (s[i] - 'a' + 1)) % mod;
    }

    // Динамика
    vector<bool> can_cover(len_s + 1, false);
    can_cover[0] = true;

    for (int i = 0; i < len_s; i++) {
        if (!can_cover[i]) continue;
        
        for (int j = 0; j < n; j++) {
            int L = lengths[j];
            if (i + L > len_s) continue;
            
            // Просто вычисляем хеш прямо здесь
            ll substr_hash = pref_hash[i + L] - pref_hash[i] * pow_base[L];
            substr_hash %= mod;
            if (substr_hash < 0) substr_hash += mod;
            
            if (substr_hash == hashes[j]) {
                // Отмечаем все позиции, которые покрывает этот шаблон
                for (int k = i; k < i + L; k++) {
                    can_cover[k + 1] = true;
                }
            }
        }
    }

    if (can_cover[len_s]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}