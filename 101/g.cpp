#include <iostream>
#include <cmath>
#include <vector>
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
    vector<int> prime_numbers;
    vector<int> superprime_numbers;
    int n;
    cin >> n;

    int number = 2;
    prime_numbers.push_back(2); // Первое простое число 2

    while (superprime_numbers.size() < 100) {
        number++;
        if (is_prime(number)) {
            prime_numbers.push_back(number);

            if (is_prime(prime_numbers.size())) {
                superprime_numbers.push_back(number);
            }
        }

    }

    cout << superprime_numbers[n - 1] << endl;

    return 0;
}