

#include "Ecuacion_Calor.h"


void solveEC(vector <double> x, double Q, double K, double phi_0, double phi_n, double n, double L ){
    vector< vector < double>> M;
    vector <vector <double>> H;
    vector <double> b;
    
    double cf = (Q * (L/n)*  (L/n))/K; 
    
    M.assign(n-1, vector<double> (n-1, 0.0));
    H.assign(n-1, vector<double> (n-1, 0.0));
    for (int i = 0; i<n-1; i++){
        for (int j = 0; j<n-1; j++){
            if (i == j)
                M[i][j] = 2;
            
            if (i == j-1 || i == j+1)
                M[i][j] = -1;
        }
    }
    
    b.assign(n-1, cf);
    
    b[0] = cf + phi_0;
    b[n-2] = cf + phi_n;
    
    
    FactorizarTriD(M, H);
    
    Triangular_Inferior(H, b, x);
    Triangular_Superior(H, x, x);
    
    for (int i = 1; i<n-3; i++){
        b[i] = cf;
    }
    
    b[0] = cf - phi_0;
    b[n-2] = cf - phi_n;
    
    Try_Sol(M, b,x);
    
    cout << "SOL" << endl;
    cout << x << endl;


}