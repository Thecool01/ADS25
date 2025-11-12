#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> prefix_func(const string &s) {
    int n = s.size();

    vector<int> pi(n, 0);

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];

        while(j > 0 && s[i] != s[j]){
            j = pi[j - 1];
        }

        if (s[i] == s[j]) {
            j++;
        } 
        pi[i] = j; 
    }
    return pi;
}

int main() {
    string s;
    cin >> s;
    if (s.empty()) {
        cout << 0;
        return 0;
    }

    vector<int> pi = prefix_func(s);
    int n = s.size();
    int ans = n - pi[n - 1];
    cout << ans << endl;
}