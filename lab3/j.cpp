#include <iostream>
#include <vector>
using namespace std;

long long n, h;
vector<long long> gold;

bool can(long long cap) {
    long long hours = 0;
    for (long long x : gold) {
        hours += (x + cap - 1) / cap; // ceil(x / cap)
        if (hours > h) return false;
    }
    return hours <= h;
}

int main() {
    cin >> n >> h;
    gold.resize(n);
    long long high = 0;
    for (int i = 0; i < n; i++) {
        cin >> gold[i];
        high = max(high, gold[i]);
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
