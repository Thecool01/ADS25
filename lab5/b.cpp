#include <iostream>
#include <queue>
#include <cmath>

using namespace std;    

int main() {
    long long n;
    cin >> n;

    priority_queue<long long> stones;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        stones.push(x);
    }

    while (stones.size() > 1) {
        long long x = stones.top(); stones.pop(); // Берем первый элемент и удаляем его
        long long y = stones.top(); stones.pop(); // Берем второй элемент и удаляем его
        if (x != y) stones.push(abs(x - y)); // Если не равны, то минусуем один от другого под модулем
    }
    if (stones.size() == 0) {
        cout << 0 << endl;
    }
    else {
        cout << stones.top() << endl;
    }
    return 0;
}