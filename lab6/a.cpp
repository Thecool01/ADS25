#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_vowel(char c) {
    return c == 'a' || 
    c == 'e' || 
    c == 'i' || 
    c == 'o' || 
    c == 'u';
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<char> vowels, consonants;

    for (int i = 0; i < s.size(); i++) {
        if (is_vowel(s[i])) {
            vowels.push_back(s[i]);
        }
        else {
            consonants.push_back(s[i]);
        }
    }

    sort(vowels.begin(), vowels.end());
    sort(consonants.begin(), consonants.end());

    for (char c : vowels) cout << c;
    for (char c : consonants) cout << c;
    return 0;
}