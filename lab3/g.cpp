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
    long long hi = 0;
    for (int i = 0; i < n; i++) {
        cin >> children[i];
        hi = max(hi, children[i]);
    }

    long long lo = 1, ans = hi;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (can(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";
}
