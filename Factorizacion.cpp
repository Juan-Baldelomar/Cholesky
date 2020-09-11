

#include "Factorizacion.h"
#include <bits/stdc++.h>
#include "Tools.hpp"

void Factorizar(vector< vector<double> >&A, vector< vector<double> >&H) {

    int n = A.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            double acc = 0;

            if (i != j) {
                //h_ij
                for (int k = 0; k < j; k++) {
                    acc += H[i][k] * H[j][k];
                }
                H[i][j] = (A[i][j] - acc) / H[j][j];
            }
        }

        double acc = 0;
        // h_ii
        for (int k = 0; k < i; k++) {
            acc += H[i][k] * H[i][k];
        }

        H[i][i] = sqrt(A[i][i] - acc);

    }

    //calcular transpuesta
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            H[i][j] = H[j][i];
        }
    }
}

void FactorizarTriD(vector< vector<double> >&A, vector< vector<double> >&H) {
    int n = A.size();

    for (int i = 0; i < n; i++) {
        // no need for acc, hir*hjr = 0

        // h_ij
        if (i != 0)
            H[i][i - 1] = A[i][i - 1] / H[i - 1][i - 1];
        // h_ii
        H[i][i] = sqrt(A[i][i] - H[i][i - 1] * H[i][i - 1]);
    }

    //calcular transpuesta
    for (int i = 0; i < n-1; i++) {
        H[i][i+1] = H[i+1][i];
    }
}