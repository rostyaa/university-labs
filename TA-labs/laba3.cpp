#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include<windows.h>

// функція для генерації масиву випадкових чисел від 0 до 100
std::vector<int> generateRandomArray(int size) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 101; // числа від 0 до 100
    }
    return arr;
}

// функція сортування підрахунком
void countingSort(std::vector<int>& arr) {
    int max_val = *max_element(arr.begin(), arr.end());
    std::vector<int> count(max_val + 1, 0);

    for (int num : arr) {
        count[num]++;
    }

    int index = 0;
    for (int i = 0; i < count.size(); i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

// допоміжна функція для створення купи
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// головна функція для пірамідального сортування
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// головна функція для поразрядного сортування
void radixSort(std::vector<int>& arr) {
    int m = *max_element(arr.begin(), arr.end());
    for (int exp = 1; m / exp > 0; exp *= 10) {
        std::vector<int> output(arr.size());
        int i, count[10] = { 0 };

        for (i = 0; i < arr.size(); i++)
            count[(arr[i] / exp) % 10]++;

        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (i = arr.size() - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (i = 0; i < arr.size(); i++)
            arr[i] = output[i];
    }
}

// функція для виміру часу сортування
void measureSortTime(void (*sortFunction)(std::vector<int>&), std::vector<int>& arr) {
    unsigned long start, end;
    start = clock();
    sortFunction(arr);
    end = clock();
    std::cout << "Час виконання: " << (end - start) / double(CLOCKS_PER_SEC) << " секунд" << std::endl;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Ukr");

    srand(static_cast<unsigned int>(time(nullptr))); // ініціалізація генератора випадкових чисел

    std::vector<int> sizes = { 1000, 3000, 9000, 27000, 81000 };

    for (int size : sizes) {
        std::cout << "Розмір масиву: " << size << std::endl;
        std::vector<int> arr = generateRandomArray(size);

        std::cout << "Counting Sort: ";
        measureSortTime(countingSort, arr);

        arr = generateRandomArray(size); // генеруємо масив знову для чесного тестування
        std::cout << "Heap Sort: ";
        measureSortTime(heapSort, arr);

        arr = generateRandomArray(size); // і знову генеруємо масив
        std::cout << "Radix Sort: ";
        measureSortTime(radixSort, arr);

        std::cout << std::endl;
    }

    return 0;
}
