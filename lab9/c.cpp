#include <iostream>
#include <string>

using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    string doubled = A + A;
    size_t pos = doubled.find(B);

    if (pos == string::npos || pos >= A.size()) {
        cout << -1 << endl;
    }
    else {
        /*
        Если строка длиной n, и подстрока B начинается с позиции pos,
        то правый сдвиг равен: shift=𝑛−𝑝𝑜𝑠
        потому что «левая часть» A (длиной pos) перешла в конец.
        Чтобы избежать переполнения, берём по модулю:
        shift=(𝑛−𝑝𝑜𝑠) mod 𝑛
        */
        cout << (A.size() - pos) % A.size() << endl;
    }

    return 0;
}