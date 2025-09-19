#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        numbers[i] = x;
    }

    map<int, int> quantities;
    for (int x : numbers) {
        quantities[x]++;
    }


    int maxMode = 0;

    for (auto x : quantities) {
        maxMode = max(maxMode, x.second);
    }

    vector<int> modes;

    for (auto x : quantities) {
        if (x.second == maxMode) {
            modes.push_back(x.first);
        }
    }

    sort(modes.rbegin(), modes.rend());

    for (int i = 0; i < modes.size(); i++) {
        cout << modes[i] << ' ';
    }
    return 0;
}  