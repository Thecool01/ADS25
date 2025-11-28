#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> buildLPS(const vector<string> &pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);

    int j = 0;

    for (int i = 1; i < n; i++) {
        while(j > 0 && pattern[i] != pattern[j]) {
            j = lps[j - 1]
        }
    }
}