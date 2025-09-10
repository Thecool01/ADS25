#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int number) {
    if (number <= 1) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;

    for (int i = 2; i <= sqrt(number); i += 1) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int number;
    cin >> number;

    if (is_prime(number)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}