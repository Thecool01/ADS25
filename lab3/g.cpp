#include <iostream>
#include <vector>
using namespace std;

long long n, f;
vector<long long> children;

bool can(long long cap) {
    long long flights = 0;
    for (long long x : children) {
        flights += (x + cap - 1) / cap; // ceil(x / cap)
        if (flights > f) return false;
    }
    return flights <= f;
}

int main() {
    cin >> n >> f;
    children.resize(n);
    long long high = 0;
    for (int i = 0; i < n; i++) {
        cin >> children[i];
        high = max(high, children[i]);
    }

    long long low = 1, ans = high;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (can(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
}