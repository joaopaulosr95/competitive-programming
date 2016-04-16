#include <iostream>

using namespace std;

const pair<int,int> MAX = make_pair(7,30010);

int main ()
{
    int values[6] = {0,1,5,10,25,50},
        i, j, n;
    unsigned long long int sol[MAX.first][MAX.second];

    for (i = 0; i < MAX.first; i++)
        sol[i][0] = 1;

    for (i = 0; i < MAX.second; i++)
        sol[0][i] = 0;

    //----------------- Coin Change -----------------//
    for (i = 1; i < MAX.first; i++)
    {
        for (j = 1; j < MAX.second; j++)
        {
            if (j < values[i])
                sol[i][j] = sol[i-1][j];
            else
                sol[i][j] = sol[i][j - values[i]] + sol[i-1][j];
        }
    }
    //-----------------------------------------------//
    while (cin >> n)
    {
        if (sol[5][n] != 1)
            cout << "There are " << sol[5][n] << " ways to produce ";
        else
            cout << "There is only 1 way to produce ";
        cout << n << " cents change.\n";
    }

    return 0;
}
