#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> number_of_letter(26, 0);

    for (char c : s) { // Подсчет каждой буквы которая встречается в STR
        number_of_letter[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) { // Так как у нас 26 букв в англ. алфафите -> то вывод каждую букву 
        while (number_of_letter[i]--) { // Пока у нас не закончится букву, будем ее выводить
            cout << char('a' + i); // 'a' + 0 = a, 'a' + 1 = b ...
        }
    }
    

    return 0;
} 