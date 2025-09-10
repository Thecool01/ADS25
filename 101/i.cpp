#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;

    queue<int> S, K;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'S') {
            S.push(i); // Пушаем номера S
        }
        else {
            K.push(i); // Пушаем номера K
        }
    }    

    while (!S.empty() && !K.empty()) {
        int S_number = S.front(); // Берем номер первого S в очереди
        S.pop();

        int K_number = K.front(); // Берем номер первого K в очереди
        K.pop();

        if (S_number < K_number) { // Условие: Если номер S < K, то остается S и на оборот
            S.push(S_number + n); 
        }

        else {
            K.push(K_number + n);
        }
    }
    if (S.empty()) {
        cout << "KATSURAGI";
    }
    else {
        cout << "SAKAYANAGI";
    }
    return 0;
}
