#include <iostream>
#include <queue>

using namespace std;

int main() {

    queue<int> boris, nursik;
    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        boris.push(a);
    }

    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        nursik.push(a);
    }

    int moves = 0;

    while (moves < 1000000 && !boris.empty() && !nursik.empty()) {

        moves++;

        int B = boris.front(); // Берем карту  и удаляем ее из колоды boris
        boris.pop();
        int N = nursik.front(); // Берем карту и удаляем ее из колоды nursik
        nursik.pop();

        if ((B == 0 && N == 9)) {
            boris.push(B);
            boris.push(N);
        }
        else if ((B == 9 && N == 0)) {
            nursik.push(B);
            nursik.push(N);
        }
        else if (B > N) {
            boris.push(B);
            boris.push(N);
        }
        else {
            nursik.push(B);
            nursik.push(N);
        }
    }

    if (moves == 1000000) {
        cout << "blin nichya" << endl;
    }
    else {
        if (boris.empty()) {
            cout << "Nursik" << " " << moves << endl;
        }
        else {
            cout << "Boris" << " " << moves << endl; 
        }
    }
    return 0;
}