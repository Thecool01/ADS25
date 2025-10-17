#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    sort(points.begin(), points.end());

    long long min_difference = points[1] - points[0];
    for (int i = 0; i < n - 1; i++) {
        long long difference = points[i+1] - points[i];
        if (difference < min_difference) min_difference = difference;
    }

    for (int i = 0; i < n - 1; i++) {
        if (points[i+1] - points[i] == min_difference) {
            cout << points[i] << ' ' << points[i+1] << ' ';
        }
    }

    return 0;
}
