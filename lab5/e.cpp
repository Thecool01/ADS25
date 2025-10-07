#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int num_commands, k;
    cin >> num_commands >> k;

    vector<int> cookies;

    make_heap(cookies.rbegin(), cookies.rend()); // Создаем кучу по возврастанию

    long long sum = 0;
    for (int i = 0; i < num_commands; i++) {
        string command;
        cin >> command;
        if (command == "insert") {
            int x;
            cin >> x;

            if (cookies.size() == k) { // Если у нас достиг лимит
                pop_heap(cookies.begin(), cookies.end()); // pop_heap() передивигает наименьший элемент в конец листа
                int y = cookies.back(); cookies.pop_back(); // Берем и удаляем с конца

                if (x > y) { // Если X > Y, то убираем Y, плюсуем X в сумму, добавляем X в конец и сортируем кучу
                    sum -= y;
                    sum += x;
                    cookies.push_back(x);
                    sort_heap(cookies.begin(), cookies.end());
                }
            }
            else {
                cookies.push_back(x);
                sum += x;
                sort_heap(cookies.begin(), cookies.end());
            }
        }
        else {
            if (cookies.size() == 0) {
                cout << 0 << endl;
            }
            else {
                cout << sum << endl;
            }
        }
    }
    return 0;
}
