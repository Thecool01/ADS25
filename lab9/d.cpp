#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string prev;
    cin >> prev;
    
    prev[0] = tolower(prev[0]);
    int n;
    cin >> n;
    
    vector<string> cities(n);
    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }
    
    vector<string> answer;
    int best = 0;
    
    // Проверяем все суффиксы предыдущего города
    for (int len = prev.size(); len >= 1; len--) { // Будем идти от начала к концу "Kokshetau" -> "okshetau"
        string suffix = prev.substr(prev.size() - len);
        
        for (string& city : cities) {
            city[0] = tolower(city[0]);
            // Проверяем начинается ли город с этого суффикса
            if (city.size() >= len && city.substr(0, len) == suffix) {
                if (len > best) { // Нашли суффикс больше
                    best = len;
                    answer.clear();
                    answer.push_back(city);
                }
                else if (len == best) {
                    answer.push_back(city); // Если есть суффикс такой же длины
                }
            }
        }
        // Прерываем цикл если нашли города
        if (!answer.empty() && len < best) {
            break;
        }
    }
    
    cout << answer.size() << endl;
    for (string& city : answer) {
        city[0] = toupper(city[0]);
        cout << city << endl;
    }

    return 0;
}