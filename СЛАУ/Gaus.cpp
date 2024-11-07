#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void outData(int numEq, double** A, double* Y) { // вывод данных
    for(int i = 0; i < numEq; i++){
        for(int j = 0; j < numEq; j++){
            cout << A[i][j] << "*x" << j;
            if(j < numEq - 1){
                cout << " + ";
            }
        }
        cout << " = " << Y[i] << endl;
    }
}

void Triangle(int i, int k, int numEq, double** A, double* Y) {
    double coeff = A[k][i] / A[i][i];
    for(int j = i; j < numEq; j++){
        A[k][j] -= coeff * A[i][j];
    }   
    Y[k] -= coeff * Y[i];
}

void Gauss(double** A, double* Y, int numEq){
    double* X = new double[numEq];
    for(int i = 0; i < numEq; i++) {
        // поиск максимального элемента a[i][1] в матрице А
        double maxEl = abs(A[i][i]);
        int maxRow = i;
        for(int j = i + 1; j < numEq; j++){
            if(abs(A[j][i]) > maxEl) {
                maxEl = abs(A[j][i]);
                maxRow = j;
            }
        }
        // меняем строку с макс элементом на начальную
        swap(A[maxRow], A[i]);
        swap(Y[maxRow], Y[i]);
        // приведение к треугольной форме
        vector<thread> thr;
        for(int k = i + 1; k < numEq; k++) {
            thr.push_back(thread(Triangle, i, k, numEq, A, Y));
        }

        for(auto& th: thr) {
            th.join();
        }
    }
    // обратный ход
    for(int i = numEq-1; i >= 0; i--) {
        X[i] = Y[i] / A[i][i];
        for(int k = i - 1; k >= 0; k--) {
            Y[k] -= A[k][i] * X[i];
        }
    }

    // вывод результатов
    for(int i = 0; i < numEq; i++){
        cout << "x[" << i << "] = " << X[i] << endl;
    }
    
    // outData(numEq, A, Y);
}

int main() {
    int numEq;
    cout << "Введите количество уравнения: ";
    cin >> numEq;
    double** A = new double* [numEq];
    double* Y = new double[numEq];

    // ввод данных для матрицы А
    for(int i = 0; i < numEq; i++){
        A[i] = new double [numEq];
        for(int j = 0; j < numEq; j++){
            cout << "a[" << i << "]" << "[" << j << "]: ";
            cin >> A[i][j];
        }
    }
    // ввод данных для матрицы Y
    for(int i = 0; i < numEq; i++){
        cout << "y[" << i << "]: ";
        cin >> Y[i];
    }
    outData(numEq, A, Y);
    cout << endl;
    Gauss(A, Y, numEq);


    return 0;
}