#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, string> changes_nicknames;

    for (int i = 0; i < n; i++) {
        string old_name, new_name;
        cin >> old_name >> new_name;

        bool found = false;
        for (auto &nick : changes_nicknames) {
            if (nick.second == old_name) { // Если следующее изменение имени совподает со старым
                nick.second = new_name; // То заменяем новым никнеймом
                found = true;
                break;
            }
        }

        if (!found) { 
            changes_nicknames[old_name] = new_name;
        }
    }
    cout << changes_nicknames.size() << endl;
    for (auto &nick : changes_nicknames) {
        cout << nick.first << ' ' << nick.second << endl;
    }
    return 0;
}