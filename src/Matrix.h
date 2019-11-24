//
// Created by Niujx on 2019/11/24.
//
// example:
// vector<vector<int>> m(10,vector<int>(10, 1));
//
// Matrix<int> base(m);
// base.display();
//
// base=base^3;
// base.display();
//

#ifndef ALGORITHMWAREHOUSE_MATRIX_H
#define ALGORITHMWAREHOUSE_MATRIX_H

#include <vector>

using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

template<typename T>
class Matrix {

public:
    vector<vector<T>> M;

    Matrix(int n, int m);

    explicit Matrix(vector<vector<T>> &matrix);

    void clear();

    void display();

    friend Matrix operator*(Matrix a, Matrix b) {
        Matrix ans(a.M.size(), b.M[0].size());

        for (int i = 0; i < a.M.size(); i++) {
            for (int j = 0; j < b.M[0].size(); j++) {
                ans.M[i][j] = 0;
                for (int k = 0; k < b.M.size(); k++)
                    ans.M[i][j] += a.M[i][k] * b.M[k][j] % MOD;
            }
        }
        return ans;
    }

    friend Matrix operator^(Matrix base, long long k) {
        Matrix ans(base.M.size(), base.M[0].size());

        while (k) {
            if (k & 1) ans = ans * base;
            base = base * base;
            k >>= 1;
        }
        return ans;
    }
};

#endif //ALGORITHMWAREHOUSE_MATRIX_H
