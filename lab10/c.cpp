#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 20005; // Учитываем, что можем умножить до 10000*2

struct State { // Создаем структуру, которая будет хранить
    int value; // Наше число
    int steps; // Количество шагов
    int prev; // И предыдущее число (для восстановления пути)
};


void solve(int A, int B) {
    if (A == B) {
        cout << "0" << endl;
        return;
    }

    vector<State> visited(MAX, {-1, -1, -1});
    queue<int> q;
    
    visited[A] = {A, 0, -1};
    q.push(A);
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        if (current == B) { // Если число равно нужному
            break;
        }


        // Операция 1: умножить на 2
        int next1 = current * 2;
        if (next1 < MAX && visited[next1].steps == -1) { // visited[next1].steps == -1 означает, что мы еще не посещали это число
            visited[next1] = {next1, visited[current].steps + 1, current};
            q.push(next1);
        }
        
        // Операция 2: уменьшить на 1
        int next2 = current - 1;
        if (next2 > 0 && visited[next2].steps == -1) {
            visited[next2] = {next2, visited[current].steps + 1, current};
            q.push(next2);
        }
    }


    // Восстанавливаем путь
    vector<int> path;
    int current = B;
    while (current != -1 && current != A) {
        path.push_back(current);
        current = visited[current].prev;
    }
    
    reverse(path.begin(), path.end());

    cout << path.size() << endl;
    if (!path.empty()) {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int A, B;
    cin >> A >> B;
    
    solve(A, B);
    
    return 0;
}

