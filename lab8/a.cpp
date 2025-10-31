// #include <iostream>
// #include <unordered_set>
// #include <cmath>
// #include <vector>

// using namespace std;

// const long long MOD = 1e9 + 7;
// const long long BASE = 11;

// long long get_hash(const string &s) {
//     long long sum_result = 0;
//     long long p = 0;
//     long long p_base = 1;
//     for (size_t i = 0; i < s.size(); ++i) {
//         sum_result = (sum_result + (((long long)s[i] - 47) * p_base) % MOD) % MOD;
//         p++;
//         p_base = pow(BASE, p);
//     }
//     cout << sum_result << endl;
//     return sum_result;
// }

// int main() {
//     int n;
//     cin >> n;

//     vector<string> arr(2 * n);
//     unordered_set<long long> hashs;

//     for (int i = 0; i < 2 * n; i++) {
//         cin >> arr[i];

//         hashs.insert(stoll(arr[i]));

//     }

//     for (int i = 0; i < 2 * n; i++) {
//         long long h = get_hash(arr[i]);

//         if (hashs.count(h)){
//             cout << "Hash of string \"" << arr[i] << "\" is " << h << endl;
//         }
//     }

//     return 0;
// }

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

    unordered_set<long long> given_hashes;
    vector<string> strings(n);

    // читаем n пар: число и строку
    for (int i = 0; i < n; ++i) {
        long long h;
        string s;
        cin >> h >> s;
        given_hashes.insert(h);
        strings[i] = s;
    }

    for (auto &s : strings) {
        long long h = get_hash(s);
        if (given_hashes.count(h)) {
            cout << "Hash of string \"" << s << "\" is " << h << endl;
        }
    }

    return 0;
}

