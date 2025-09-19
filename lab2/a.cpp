#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> numbers(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        numbers[i] = x;
    }

    int k;
    cin >> k;

    int near_index = 0;
    int near_distance = abs(k - numbers[0]);

    for (int i = 1; i < n; i++) {
        int dist = abs(k - numbers[i]);
        if (near_distance > dist) {
            near_distance = dist;
            near_index = i;
        }
    }

    cout << near_index;
    return 0;
}