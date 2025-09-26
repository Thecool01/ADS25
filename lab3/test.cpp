#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, max_block;
    cin >> n >> max_block;

    vector<long long> ghouls(n);
    long long sum = 0, maxi = 0;

    for (int i = 0; i < n; i++) {
        cin >> ghouls[i];
        sum += ghouls[i];
        maxi = max(maxi, ghouls[i]);
    }

    long long low = maxi, high = sum; 

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long current_sum = 0;
        int total_block = 1; // начинаем с 1 блока

        for (int i = 0; i < n; i++) {
            if (current_sum + ghouls[i] <= mid) {
                current_sum += ghouls[i];
            } else {
                total_block++;       // начинаем новый блок
                current_sum = ghouls[i];
            }
        }

        if (total_block <= max_block) {
            high = mid - 1; // можно уложиться → пробуем меньше
        } else {
            low = mid + 1;  // не можем уложиться → увеличиваем границу
        }
    }

    cout << low << "\n"; // минимальный возможный максимум
    return 0;
}
