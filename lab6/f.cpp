#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Student { // Структура STUDENT
    string last_name, first_name;
    double gpa;
};


// Функция для сортировки
bool cmp(const Student &a, const Student &b) {
    if (a.gpa != b.gpa)
        return a.gpa < b.gpa; // по возрастанию GPA
    if (a.last_name != b.last_name) // сортировка по фамилии
        return a.last_name < b.last_name;
    return a.first_name < b.first_name; // сортировка по имени
}
int main() {
    int n;
    cin >> n;

    map<string, double> grades = { // мап со всеми оценками
        {"A+", 4.00}, {"A", 3.75}, {"B+", 3.50}, {"B", 3.00},{"C+", 2.50}, {"C", 2.00}, {"D+", 1.50}, {"D", 1.00},{"F", 0.00}
    };

    vector<Student> students;

    for (int i = 0; i < n; i++) {
        string last_name, first_name;
        int num_sub;
        cin >> last_name >> first_name >> num_sub;

        double total_points = 0.0;
        double total_credits = 0;

        for (int i = 0; i < num_sub; i++) {
            string grade;
            int credit;
            cin >> grade >> credit;
            total_points += grades[grade] * credit;
            total_credits += credit;
        }

        double gpa = total_points / total_credits;
        students.push_back({last_name, first_name, gpa});
        
    }


    sort(students.begin(), students.end(), cmp);

    cout << fixed << setprecision(3);
    for (auto &student : students) {
        cout << student.last_name << ' ' << student.first_name << ' ' << student.gpa << endl;
    }

    return 0;
}