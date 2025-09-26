#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, max_block;
    cin >> n >> max_block;

    vector <long long> ghouls(n);
    long long sum = 0, maxi = 0;

    for (int i = 0; i < n; i++) {
        cin >> ghouls[i];
        sum += ghouls[i];
        maxi = max(maxi, ghouls[i]);
    }
    
    long long low = maxi, high = sum; // Левая граница это МАКСИМАЛЬНОЕ ЧИСЛО, правая СУММА
    
    while (low <= high) { // Бинарный поиск
        long long mid = (low + high) / 2;
        long long current_sum = 0, total_block = 1;


        for (int i = 0; i < n; i++) {
            if (current_sum + ghouls[i] <= mid) {
                current_sum += ghouls[i];
            }
            else { // Иначе, если сумма больше чем мидл, то создаем блок, начинаем от начального числа в блоке
                total_block++;
                current_sum = ghouls[i];
            }

        }

        if (total_block <= max_block) { // Меняем правую границу
            high = mid - 1;
        }
        else {
            low = mid + 1; // Иначе меняем левую
        }
    }

    cout << low << endl;
    return 0;

}