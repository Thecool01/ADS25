#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int BASE = 131;
const long long MOD = 1e9 + 7;

long long computeHash(const string& s) {
    long long hash = 0;
    for (char c : s) {
        hash = (hash * BASE + c) % MOD;
    }
    return hash;
}

int countPattern(const string& text, const string& pattern, long long patternHash) {
    int count = 0;
    int patternLen = pattern.length();
    int textLen = text.length();
    
    if (patternLen > textLen) return 0;
    
    long long textHash = 0;
    long long power = 1;
    
    // Вычисляем BASE^(patternLen-1)
    for (int i = 0; i < patternLen - 1; i++) {
        power = (power * BASE) % MOD;
    }
    
    // Вычисляем хеш первого окна
    for (int i = 0; i < patternLen; i++) {
        textHash = (textHash * BASE + text[i]) % MOD;
    }
    
    // Проверяем первое окно
    if (textHash == patternHash && text.substr(0, patternLen) == pattern) {
        count++;
    }
    
    // Скользим окном
    for (int i = patternLen; i < textLen; i++) {
        textHash = (textHash - text[i - patternLen] * power % MOD + MOD) % MOD;
        textHash = (textHash * BASE + text[i]) % MOD;
        
        if (textHash == patternHash && text.substr(i - patternLen + 1, patternLen) == pattern) {
            count++;
        }
    }
    
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    while (cin >> N && N != 0) {
        vector<string> patterns(N);
        vector<long long> hashes(N);
        vector<int> frequencies(N, 0);
        
        for (int i = 0; i < N; i++) {
            cin >> patterns[i];
            hashes[i] = computeHash(patterns[i]);
        }
        
        string text;
        cin >> text;
        
        int maxFreq = 0;
        for (int i = 0; i < N; i++) {
            frequencies[i] = countPattern(text, patterns[i], hashes[i]);
            maxFreq = max(maxFreq, frequencies[i]);
        }
        
        cout << maxFreq << endl;
        for (int i = 0; i < N; i++) {
            if (frequencies[i] == maxFreq) {
                cout << patterns[i] << endl;
            }
        }
    }
    
    return 0;
}