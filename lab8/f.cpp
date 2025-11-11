#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int countDistinctSubstrings(const string& s) {
    int n = s.length();
    if (n == 0) return 0;
    
    vector<long long> hashes;
    hashes.reserve(n * (n + 1) / 2);
    
    const long long base = 131;
    
    for (int i = 0; i < n; i++) {
        long long hash = 0;
        
        for (int j = i; j < n; j++) {
            hash = hash * base + (s[j] - 'a' + 1);
            hashes.push_back(hash);
        }
    }
    
    // Сортируем и удаляем дубликаты
    sort(hashes.begin(), hashes.end());
    hashes.erase(unique(hashes.begin(), hashes.end()), hashes.end());
    
    return hashes.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    cout << countDistinctSubstrings(s) << endl;
    return 0;
}