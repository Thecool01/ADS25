#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int d = 256;
const int q = 1000003;

int RabinKarpPositions(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();

    long long h = 1;
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    long long p = 0; // Хеш паттерна
    long long t = 0; // Хеш текста

    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    int count = 0;

    for (int i = 0; i <= n - m; i++) {
        if (p == t && text.substr(i, m) == pattern) { // Если хеши совпадают
            count++;
        }
        
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) t += q;
        }
    }

    return count;
}


int main() {
    string s;
    cin >> s;

    int query;
    cin >> query;

    for (int i = 0; i < query; i++) {
        int l, r;
        cin >> l >> r;

        string pattern = s.substr(l - 1, r - l + 1); // Берем субстроку из стринга, и сравниваем ее

        int answer = RabinKarpPositions(s, pattern);
        cout << answer << endl;
    }

    return 0;
}
