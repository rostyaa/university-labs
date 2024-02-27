#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include<windows.h>

using namespace std;

//функція для генерації масиву випадкових чисел
vector<int> generateRandomArray(int size, int range) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % range;
    }
    return arr;
}

//функція для сортування методом CountingSort
void countingSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    vector<int> count(range);
    vector<int> output(arr.size());

    for (int i = 0; i < arr.size(); i++) {
        count[arr[i] - minVal]++;
    }

    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

//функція для сортування методом HeapSort
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

//функція для сортування методом RadixSort
int getMax(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

void countSort(vector<int>& arr, int exp) {
    const int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr);

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countSort(arr, exp);
    }
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Ukr");

    srand(static_cast<unsigned>(time(nullptr)));

    int size, range;
    cout << "Введіть розмір масиву: ";
    cin >> size;
    cout << "Введіть діапазон чисел: ";
    cin >> range;

    vector<int> arr = generateRandomArray(size, range);

    cout << "Початковий масив:" << endl;
    for (const int& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> arrCopy = arr;  //для збереження копії масиву

    //сортування CountingSort
    cout << "Сортування методом CountingSort:" << endl;
    countingSort(arr);
    for (const int& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    arr = arrCopy;  //відновлення початкового масиву

    //сортування HeapSort
    cout << "Сортування методом HeapSort:" << endl;
    heapSort(arr);
    for (const int& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    arr = arrCopy;

    //сортування RadixSort
    cout << "Сортування методом RadixSort:" << endl;
    radixSort(arr);
    for (const int& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
