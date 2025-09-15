#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n;
    cin >> n; // Вписываем количество колод карт

    for (int _ = 0; _ < n; _++) { // Создаем цикл для каждой колоды карт
        int c;
        cin >> c; // Вписываем начальную карту

        deque<int> cards;
        for (int i = c; i >= 1; i--) { // Создаем цикл от Последней карты до Начальной
            cards.push_front(i); // Вписываем первое число

            for (int j = 0; j < i; j++) { // Меняем карты с конца до начала, так как мы не знаем какая у нас колода изначально
               if (cards.size() > 1) { // Проверка на количество карт в колоде
                int back = cards.back(); // Берем последнюю карту
                cards.pop_back();
                cards.push_front(back); // И кладем ее в начало, и так далее с каждой картой
               }
            }
        }

        for (int ch : cards) {
            cout << ch << ' ';
        }
        cout << endl;
    }
}