#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numInRange(const vector<int>& a, int l, int r) { // функция для подсчёта количества элементов массива в диапазоне [L, R]
    auto left = lower_bound(a.begin(), a.end(), l); // Левая граница
    auto right = upper_bound(a.begin(), a.end(), r); // Правая граница
    int ans = int(right - left); // Количество элементов в границе
    return ans;
}

int main() {
    int n, intervals;
    cin >> n >> intervals;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    
    sort(numbers.begin(), numbers.end());

    while(intervals--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int num1 = numInRange(numbers, l1, r1);
        int num2 = numInRange(numbers, l2, r2);

        // Ищем пресечение
        int L = max(l1, l2);
        int R = min(r1, r2);
        
        int intersection = 0;
        if (L <= R) {
            intersection = numInRange(numbers, L, R);
        }

        cout << (num1 + num2 - intersection) << endl;
    }
    return 0;
}