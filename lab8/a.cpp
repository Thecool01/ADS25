#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;
const long long BASE = 11;

long long get_hash(const string &s) {
    long long result = 0;
    long long base_pow = 1;

    for (char c : s) {
        result = (result + (c - 47) * base_pow) % MOD;
        base_pow = (base_pow * BASE) % MOD;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<string> v(2 * n);
    unordered_set<string> st;

    // читаем n пар: число и строку
    for (int i = 0; i < 2 * n; ++i) {
        cin >> v[i];
        st.insert(v[i]);
    }

    int count = 0;
    for (int i = 0; i < 2 * n && count < n; i++) {
        const string &s = v[i];
        long long hs = get_hash(s);
        string hash_str = to_string(hs);

        if (st.count(hash_str)) {
            cout << "Hash of string \"" << s << "\" is " << hash_str << "\n";
            count++;
        }
    }

    return 0;
}

