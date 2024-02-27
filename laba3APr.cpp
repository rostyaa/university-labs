#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

//варіант 30
//у введеному списку з 10 прізвищ визначити найкоротше

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int numNames = 10;

    string names[numNames];

    cout << "Введіть список з 10 прізвищ:\n";
    for (int i = 0; i < numNames; ++i) {
        cout << "Прізвище " << i + 1 << ": ";
        cin >> names[i];
    }

    int shortestNameIndex = 0;
    for (int i = 1; i < numNames; ++i) {
        if (names[i].length() < names[shortestNameIndex].length()) {
            shortestNameIndex = i;
        }
    }

    cout << "Найкоротше прізвище: " << names[shortestNameIndex]
        << " (довжина " << names[shortestNameIndex].length() << " символів)\n";

    return 0;
}
