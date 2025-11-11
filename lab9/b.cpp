#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string password, text;
    int c;
    cin >> password >> c >> text;

    int count = 0;
    size_t pos = text.find(password); // Первая позиция
    while(pos != string::npos) {
        count++;
        pos = text.find(password, pos + 1); // Ищем следующий паттерн если он есть
    }

    if (count >= c) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}