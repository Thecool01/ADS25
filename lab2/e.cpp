#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> result;
    string prev = "";
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        if (i == 0 || name != prev) {
            result.push_back(name);
        }
        prev = name;
    }
    reverse(result.begin(), result.end());
    
    cout << "All in all: " << result.size() << endl;
    cout << "Students:" << endl;
    for (string s : result) {
        cout << s << endl;
    }

    return 0;
}
