#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int key; cin >> key; 

    bool flag = false;
    int low = 0;
    int high = n - 1;

    int mid;
    while(low <= high && flag != true) {
        mid = (low + high) / 2;

        if (numbers[mid] == key) {
            flag = true;
        }
        if (numbers[mid] > key) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if (flag) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}