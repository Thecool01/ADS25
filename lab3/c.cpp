#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    

    for (int i = 0; i < q; i++) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int count = 0;
        for (int num : numbers) {
            if (num >= l1 && num <= r1 || num >= l2 && num <= r2) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}

