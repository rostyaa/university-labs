#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

template <typename T>
void outputArray(T* arr, int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
template <typename T>
void randArray(T* arr, int size) {
    for (int i = 0; i < size; ++i)
        arr[i] = static_cast<T>(rand()) / (static_cast<T>(RAND_MAX / 500));
}
template <typename T>
void findMinMax(T* arr, int size, T*& pmin, T*& pmax) {
    pmin = &arr[0];
    pmax = &arr[0];
    for (int i = 0; i < size; ++i) {
        if (*pmin > arr[i]) pmin = &arr[i];
        if (*pmax < arr[i]) pmax = &arr[i];
    }
}
template <typename myT>
void mySwap(myT& a, myT& b) {
    myT temp = a;
    a = b;
    b = temp;
}
template <typename T>
T* createArray(int size) {
    if (size < 1) return NULL;
    T* arr = new T[size];
    return arr;
}
template <typename T>
void deleteArray(T*& arr) {
    delete[] arr;
    arr = NULL;
}
int main() {
    srand(time(NULL));

    int size = 10;
    double* arr = createArray<double>(size);

    randArray(arr, size);
    cout << "Initial array:" << endl;
    outputArray(arr, size);

    double* pmin = NULL, * pmax = NULL;
    findMinMax(arr, size, pmin, pmax);
    cout << "min = " << *pmin << endl;
    cout << "max = " << *pmax << endl;

    mySwap(*pmin, *pmax);
    cout << "Array after swapping min and max:" << endl;
    outputArray(arr, size);

    deleteArray(arr);
    return 0;
}

