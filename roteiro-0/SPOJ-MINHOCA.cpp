#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
    int N, M, i, j, campo[100][100];
    unsigned long long int soma[201], gtr = 0;
    
    cin >> N >> M;
    
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            cin >> campo[i][j];

    for (i = 0; i < N+M; i++)
       soma[i] = 0; 

    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            soma[i] += campo[i][j];

    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            soma[i+N] += campo[j][i];
    
    sort (soma, soma+201);
        gtr = soma[200];

    cout << gtr << endl; 
}
