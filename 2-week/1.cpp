#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    int n, m, newm, j = 0, z = 0, t;
    float q;
    vector<vector<float>> general;

    cout << "How much variables? ";
    cin >> n;
    cout << "How much equations? ";
    cin >> m;

    float **SLAU = new float*[m];
    for (int i = 0; i < n + 1; i++){
        SLAU[i] = new float[n];
    }

    for (int i = 0; i < m; i++){
    for (int k = 0; k < n + 1; k++){
        if (k == n){
            cout << "Enter free coefficient: ";
        }
        else{
            cout << "Enter coefficient: ";
        }
        cin >> SLAU[i][k];
    }}

    float *x = new float[n];

    float *var = new float[n+1];

    while (j < n and z < m){
        t = 0;
        for (int i = z; i < m; i ++){ //ищем ненулевой элемент в j-м столбце и переносим его в начало (без использованных строк)
            if (t == 0 and SLAU[i][j] != 0){
                for (int r = 0; r < n + 1; r++){
                var[r] = SLAU[i][r];
                SLAU[i][r] = SLAU[z][r];
                SLAU[z][r] = var[r];
                }
                t = 1;
            }
        }
        for (int i = z + 1; i < m; i ++){
            if (t == 1){
                q = SLAU[i][j]/SLAU[z][j];
                for (int k = j; k < n + 1; k++){
                    SLAU[i][k] -= q*SLAU[z][k];

                }
            }
        }
        z++;
        j++;
    }

    delete[] var;

    for (int i = 0; i < m; i++){
    for (int k = 0; k < n + 1; k++){
        cout << SLAU[i][k] << " ";
    }
        cout << "\n";
    }

    //Проверка на наличие лнз строк или несоблюдения условия совместности

    float *modul = new float[m];

    for (int i = 0; i < m; i++){
    for (int k = 0; k < n + 1; k++){
        if (k == n and modul[i] == 0 and SLAU[i][n] != 0){
            cout << "System has no solution" << endl;
            exit(0);
        }
        modul[i] += abs(SLAU[i][k]);
    }
    if (modul[i] == 0){
        m--;
    }
    }

    delete[] modul;

    if (n == m){
        cout << "System has a single unique solution" << endl;

        for (int k = n - 1; k >= 0; k--){
            q = SLAU[k][n];
            for (int i = n; i > k; i--){
            q -=SLAU[k][i] * x[i];
            }
            x[k] = q / SLAU[k][k];
        }
        for (int k = 0; k < n; k++){
            cout << "x[" << k << "] = " << x[k] << endl;
        }
    }

    else if (n > m){
        cout << "System has infinity solutions" << endl;
    }


    else {
        cout << "System has no solution" << endl;
    }

    return 0;
}
