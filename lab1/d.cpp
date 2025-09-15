#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> st;

    if (s.empty()) {
        cout << "YES" << endl;
    }

    for (int i = 0; i < s.size(); i++) {
        if (!st.empty() && st.top() == s[i]) { // Если Нынешний символ совподает с топовым символов в стеке, то удалаем его
            st.pop();
        } else {
            st.push(s[i]);
        }
    }

    if (st.empty()) { // Если в конце стек пустой, то сначит строка сбалансированна
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}