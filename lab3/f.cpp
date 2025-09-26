#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> competitors(n);
    for (int i = 0; i < n; i++) {
        cin >> competitors[i];
    }

    sort(competitors.begin(), competitors.end()); 

    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) { // Создаем массив с суммами
        prefix[i + 1] = prefix[i] + competitors[i];
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++){
        int power;
        cin >> power;

        int low = 0, high = n - 1;

        while(low <= high) { // БИНАРНЫЙ ПОИСК
            int mid = (low + high) / 2;
            if (competitors[mid] > power) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }

        }
        cout << low << " " << prefix[low] << endl;
    }
    return 0;
}