#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

bool sort_by_lenght(const string& a, const string& b) {
    return a.length() < b.length();
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string line; // Берем линию строк
        getline(cin, line);

        vector<string> words;
        stringstream ss(line); // разбираем их по stringstream
        string word;

        while (ss >> word) {
            words.push_back(word);
        }


        stable_sort(words.begin(), words.end(), sort_by_lenght); // Сортируем по методу merge

        for (int j = 0; j < words.size(); j++) {
            cout << words[j] << ' ';
        }
        cout << endl;
    }
    return 0;
}