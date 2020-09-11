/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: juan
 *
 * Created on September 10, 2020, 6:50 PM
 */

#include <cstdlib>
#include "Factorizacion.h"
#include "Tools.hpp"
using namespace std;

/*
 * 
 */


void produceEntry(int n, vector < vector <double> > &M){
    M.assign(n, vector<double> (n, 0.0));
    
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (i == j)
                M[i][j] = 2;
            
            if (i == j-1 || i == j+1)
                M[i][j] = -1;
        }
    }
}

void ejercicio1(){
    vector< vector <double>> M;
    vector< vector <double>> H;
    int n = 100;
    H.assign(n, vector<double>(n, 0.0));
    produceEntry(n,M);
    cout << M << endl;
    Factorizar(M, H);  
    MatrixLU_Mult(H,M);
    WriteMatrix(H, "OUT/L_100.txt");
    WriteMatrix(M, "OUT/Ht*H_100.txt");
    cout << M << endl;
}

void ejercicio2(){
    vector< vector <double>> M;
    vector< vector <double>> H;
    int n = 50;
    H.assign(n, vector<double>(n, 0.0));
    produceEntry(n,M);
    cout << M << endl;
    FactorizarTriD(M, H);  
    MatrixLU_Mult(H,M);
    WriteMatrix(H, "OUT/L_50.txt");
    WriteMatrix(M, "OUT/Ht*H_50.txt");
    cout << M << endl;
}

void ejercicio3(){
    vector< vector <double>> M;
    vector< vector <double>> H;
    int n = 4;
    H.assign(n, vector<double>(n, 0.0));
    produceEntry(n,M);
    cout << M << endl;
    FactorizarTriD(M, H);  
    MatrixLU_Mult(H,M);
    WriteMatrix(H, "OUT/L_4.txt");
    WriteMatrix(M, "OUT/Ht*H_4.txt");
    cout << M << endl;
}


int main(int argc, char** argv) {
    ejercicio2();
    return 0;
}

