#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int num_commands, k;
    cin >> num_commands >> k;

    priority_queue<int, vector<int>, greater<int>> cookies;
    long long sum = 0;

    for (int i = 0; i < num_commands; i++) {
        string command;
        cin >> command;

        if (command == "insert") {
            int x;
            cin >> x;

            if ((int)cookies.size() < k) { // Если есть место
                cookies.push(x); sum += x;
            } else if (x > cookies.top()) {
                // Если новое число больше минимального — заменяем
                sum -= cookies.top(); cookies.pop();
                cookies.push(x); sum += x;
            }
        } 
        else {
            cout << sum << endl;
        }
    }

    return 0;
}
