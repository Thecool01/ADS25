#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n), arr2(m);

    for (int i = 0; i < n; i++) cin >> arr1[i];
    for (int j = 0; j < m; j++) cin >> arr2[j];

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int i = 0, j = 0;

    vector<int> common_numbers;

    while(i < n && j < m) { // Пока у нас не закончатся цифры в одном из списка
        if (arr1[i] == arr2[j]) { // Если цифры совпадают
            common_numbers.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j]) { // Если во втором массиве число больше, передвигаем индикатор в первом
            i++;
        }
        else { // И наоборот
            j++;
        }
    }
    
    for (int x : common_numbers) {
        cout << x << ' ';
    }
    return 0;
}