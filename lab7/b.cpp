#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;

    cin >> n;
    vector<int> list1(n);
    for (int i = 0; i < n; i++) {
        cin >> list1[i];
    }

    cin >> m;
    vector<int> list2(m);
    for (int i = 0; i < m; i++) {
        cin >> list2[i];
    }


    vector<int> result(n + m);

    int i = 0, j = 0, k = 0;

    while(i < n && j < m) { // Пока один из массивов не закончится, вписываем числа с сравнением
        if (list1[i] <= list2[j]) {
            result[k++] = list1[i++];
        }
        else {
            result[k++] = list2[j++];
        }
    }

    if (i < n) { // Если числа в листе1 остались
        while(i < n) {
            result[k++] = list1[i++];
        }
    }

    if (j < m) { // Если числа в листе2 остались
        while(j < m) {
            result[k++] = list2[j++];
        }
    }

    for (int i = 0; i < n + m; i++) {
        cout << result[i] << ' ';
    }
    return 0;
}