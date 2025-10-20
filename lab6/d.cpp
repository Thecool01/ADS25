#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Date {
    int day, month, year;
    string original;
};

bool sorting(const Date &a, const Date &b) { // Сравнительная функция
    if (a.year != b.year) return a.year < b.year;
    if (a.month != b.month) return a.month < b.month;
    return a.day < b.day;
}

int main() {
    int n;
    cin >> n;
    vector<Date> dates;

    for (int i = 0; i < n; i++) {
        string date_string;
        cin >> date_string;

        int day = stoi(date_string.substr(0, 2));   // первые 2 символа — день
        int month = stoi(date_string.substr(3, 2)); // следующие 2 — месяц
        int year = stoi(date_string.substr(6, 4));  // последние 4 — год

        dates.push_back({day, month, year, date_string});
    }

    sort(dates.begin(), dates.end(), sorting);

    for (auto &d : dates)
        cout << d.original << endl;

    return 0;
}
