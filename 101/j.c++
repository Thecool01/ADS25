#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> deq;
    char ch;
    while (cin>>ch) {
        if (ch = '!') {
            break;
        }
        if (ch = '+') {
            int a;
            cin >> a;
            deq.push_front(a);
        }
        if (ch = '-') {
            int a;
            cin >> a;
            deq.push_back(a);
        }
        if (ch = '*') {
            if (deq.empty()) {
                cout << "error" << endl;
            }
            int sum;
            sum = deq.front() + deq.back();
            cout << sum;
            deq.pop_back();
            if (deq.size() == 1) {
                deq.pop_back();
            }
            else {
                deq.pop_front();
            }
        }
    }
}