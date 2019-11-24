//
// Created by Niujx on 2019/11/24.
//

#include <iostream>
#include "Matrix.h"

template class Matrix<short>;
template class Matrix<int>;
template class Matrix<ll>;

template<typename T>
Matrix<T>::Matrix(int n, int m) {
    M.clear();
    M.resize(n, vector<T>(m, 0));
    for (int i=0;i<min(n,m);i++)
        M[i][i]=1;
}

template<typename T>
Matrix<T>::Matrix(vector<vector<T>> &matrix) {
    M.clear();
    M = matrix;
}

template<typename T>
void Matrix<T>::clear() {
    M.clear();
}

template<typename T>
void Matrix<T>::display() {
    std::cout << "Matrix's begin:" << std::endl;
    for (int i = 0; i < M.size(); i++) {
        for (int j = 0; j < M[0].size(); j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
    std::cout << "Matrix's end." << std::endl;
}


