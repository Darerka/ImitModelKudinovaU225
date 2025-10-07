#include <iostream>
#include <cstdlib>  
#include <ctime>    
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int n, m, p;
    cout << "Введите размеры матриц A и B:" << endl;
    cout << "Матрица A имеет размер n x m" << endl;
    cout << "Матрица B имеет размер m x p" << endl;
    cout << "Введите n, m и p: ";
    cin >> n >> m >> p;

    
    if (n <= 0 || m <= 0 || p <= 0) {
        cout << "Ошибка: размеры должны быть положительными числами." << endl;
        return 1;
    }

    cout << "\nПроверка совместимости матриц..." << endl;
    cout << "Матрица A имеет " << m << " столбцов, "
        << "а матрица B имеет " << m << " строк." << endl;
    cout << "Матрицы можно перемножить " << endl;

    // Выделение памяти
    int** A = new int* [n];
    int** B = new int* [m];
    int** C = new int* [n];

    for (int i = 0; i < n; i++) A[i] = new int[m];
    for (int i = 0; i < m; i++) B[i] = new int[p];
    for (int i = 0; i < n; i++) C[i] = new int[p];

    srand(time(0));

    cout << "\nМатрица A:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = rand() % 10;
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nМатрица B:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            B[i][j] = rand() % 10;
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < m; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nРезультат (A x B):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    
    for (int i = 0; i < n; i++) delete[] A[i];
    for (int i = 0; i < m; i++) delete[] B[i];
    for (int i = 0; i < n; i++) delete[] C[i];
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
