#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

void findPartitions(int n, vector<int>& partition, int start) {
    if (n == 0) {
        for (int i = 0; i < partition.size(); ++i) {
            cout << partition[i];
            if (i < partition.size() - 1) {
                cout << " + ";
            }
        }
        cout << endl;
        return;
    }

    for (int i = start; i <= n; ++i) {
        partition.push_back(i);
        findPartitions(n - i, partition, i);
        partition.pop_back();
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int number = 10;

    cout << "Розбиття числа " << number << ":\n";

    vector<int> partition;
    findPartitions(number, partition, 1);

    return 0;

}
