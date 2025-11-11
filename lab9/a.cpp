#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main(){
    string A, B;
    cin >> A >> B;

    string repeated = A;
    int count = 1;

    int limit = ceil(B.size() / A.size()) + 2;

    while(repeated.find(B) == string::npos && count <= limit) { // Пока мы не нашли подстроку и пока мы не привысим лимит
        repeated += A;
        count++;
    }

    if (repeated.find(B) != string::npos) {
        cout << count << endl;
    }
    else {
        cout << -1 << endl;
    }

    return 0;

}

