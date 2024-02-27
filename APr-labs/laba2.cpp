//варіант 30
//знайти скалярні добутки першого рядка матриці на всі інші
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

using namespace std;

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int rows, cols;

    cout << "Введіть кількість рядків матриці: ";
    cin >> rows;
    cout << "Введіть кількість стовпців матриці: ";
    cin >> cols;

    if (rows < 2 || cols < 2) {
        cout << "Помилка: розмірність матриці повинна бути не менше 2x2." << endl;
        return 1;
    }

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
    cout << "Матриця:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    int* scalarProducts = new int[rows];
    for (int i = 0; i < rows; i++) {
        scalarProducts[i] = 0;
        for (int j = 0; j < cols; j++) {
            scalarProducts[i] += matrix[0][j] * matrix[i][j];
        }
    }

    cout << "Скалярні добутки першого рядка на всі інші рядки: " << endl;
    for (int i = 0; i < rows; i++) {
        cout << "Рядок " << i + 1 << ": " << scalarProducts[i] << endl;
    }


    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] scalarProducts;

    return 0;
}
