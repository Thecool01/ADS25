#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> numbers(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    
    // Префиксные суммы
    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + numbers[i];
    }

    int ans = INT_MAX;
    
    for (int low = 0; low < n; low++) {
        /*
        Нам нужно, чтобы сумма подмассива ≥ k.
        Подмассив начинается в l, значит его сумма до индекса j-1 будет:
            pref[j] - pref[l] где j — это правая граница + 1.

            pref[j] - pref[l] >= k
            pref[j] >= pref[l] + k

        Значит мы ищем j, где pref[j] не меньше target.
        */
        long long target = prefix[low] + k;

        // lower_bound ищет первый элемент в отсортированном массиве >= target.
        auto it = lower_bound(prefix.begin() + (low + 1), prefix.end(), target);
        if (it != prefix.end()) { // Если нашли такой j (иначе it == pref.end() — значит дальше суммы слишком маленькие)
            
            int j = int(it - prefix.begin()); // Индекс найденного элемента в prefix
            int len = j - low; // Длина подмассива
            if (len < ans) ans = len; // Если нашли подмассив короче, чем предыдущий лучший, обновляем ans.
        }   
    }

    cout << ans << endl;
    return 0;
}