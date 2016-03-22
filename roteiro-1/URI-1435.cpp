#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    int M[100][100], N, L1, L2, sub, i, j;
    
    while (cin >> N && N != 0)
    {
        if (N == 1)
            cout << "  1" << endl;
        else
        {
            for (i = 0; i < N; i++)
                for (j = 0; j < N; j++)
                    M[i][j] = 1;
    
            L1 = 1;
            L2 = N-1;
            while (L2 > 0)
            {
                for (i = L1; i < L2; i++)
                    for (j = L1; j < L2; j++)
                        M[i][j] = L1+1;
                L1++;
                L2--;
            }

            for (i = 0; i < N; i++)
            {
                for (j = 0; j < N; j++)
                {
                    cout << setw(3) << M[i][j];
                    if (j == N-1)
                        cout << endl;
                    else
                        cout << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}
 
