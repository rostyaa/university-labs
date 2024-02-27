#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct Student {
    string name;
    string faculty;
    string group;
    int absences;

    Student() : absences(0) {}
    Student(int numAbsences) : absences(numAbsences) {}
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "Введіть кількість студентів: ";
    cin >> n;

    Student* students = new Student[n];

    for (int i = 0; i < n; ++i) {
        cout << "Студент " << (i + 1) << ":\n";
        cout << "ПІБ: ";
        cin.ignore();
        getline(cin, students[i].name);
        cout << "Факультет: ";
        getline(cin, students[i].faculty);
        cout << "Група: ";
        getline(cin, students[i].group);
        cout << "Кількість пропусків: ";
        cin >> students[i].absences;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].absences < students[j + 1].absences) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    cout << "10 студентів з найбільшою кількістю пропусків:\n";
    for (int i = 0; i < 10 && i < n; ++i) {
        cout << students[i].name << ", " << students[i].faculty << ", "
            << students[i].group << ", Пропуски: " << students[i].absences << "\n";
    }

    delete[] students;
    return 0;
}
