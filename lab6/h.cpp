#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<char> letters(n);
    for (int i = 0; i < n; i++) {
        cin >> letters[i];
    }
    char letter;
    cin >> letter;

    int left = 0, right = n - 1, index_ans = 0;

    while (left <= right) { // БИНАРНЫЙ ПОИСК ИНДЕКСА
        int mid = (left + right) / 2;

        if (letters[mid] > letter) {
            right = mid - 1;
            index_ans = mid;
        }
        else {
            left = mid + 1;
        }
    }
    cout << letters[index_ans];
    return 0;
}