#include <iostream>
#include <stack>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    stack<char> st1, st2;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != '#') {
            st1.push(s1[i]);
        }
        else {
            st1.pop();
        }
    }
    
    for (int i = 0; i < s2.size(); i++) {
        if (s2[i] != '#') {
            st2.push(s2[i]);
        }
        else {
            st2.pop();
        }
    }
    
    if (st1 == st2) {
        cout << "Yes";
    }

    else {
        cout << "No";
    }
    return 0;
}