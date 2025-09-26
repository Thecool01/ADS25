#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    int maxCoordinate;

    vector<int> x2(n), y2(n);

    for (int i = 0; i < n; i++) {
        int x1, y1;
        cin >> x1 >> y1 >> x2[i] >> y2[i];
        
        maxCoordinate = max(maxCoordinate, max(x2[i], y2[i])); // Ищем максимальную координату
    }
    int count = 0;
    int low = 0, high = maxCoordinate; // Левая граница 0, Правая МАКС_КОРД
    while (low <= high) { // БИНАРНЫЙ ПОИСК
        count = 0;
        long long mid = (low + high) / 2;
        for (int i = 0; i < n; i++) {

            if (x2[i] <= mid && y2[i] <= mid) count++; // Если координата меньше мидла, то прибавляем
        }
        if (count >= k) { // Если количество больше желаемого, то сдвигаем правую сторону
            high = mid - 1;
        }
        else { // Если количество меньше желаемого, то сдвигаем левую сторону
            low = mid + 1;
        }
    }
    cout << low;
    return 0;
}