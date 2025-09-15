#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> ages(n);
    for (int i = 0; i < n; i++) {
        cin >> ages[i];
    }

    stack<int> st; // Будет хранить индексы людей
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        // Убираем всех, кто не младше текущего
        while (!st.empty() && ages[st.top()] > ages[i]) {
            st.pop();
        }

        if (st.empty()) {
            ans[i] = -1; // Младших нет
        } else {
            ans[i] = ages[st.top()]; // Ближайший младший
        }

        st.push(i); // Кладем текущего
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
