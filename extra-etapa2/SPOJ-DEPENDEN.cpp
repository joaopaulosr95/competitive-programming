#include <iostream>

using namespace std;

const int MAX = 105;

int N, d;
bool M[MAX][MAX], visited[MAX];

void dfs(int u)
{
    visited[u] = true;
    for (int v = 0; v < N; v++)
    {
        if (M[u][v] == true && !visited[v])
        {
            d += 1;
            dfs(v);
        }
    }
}

int main ()
{
    int T, maxd, mostExpensive;
    while (cin >> N && N != 0)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                M[i][j] = 0;

        for (int i = 0; i < N; i++)
        {
            cin >> T;
            while (T--)
            {
                int j;
                cin >> j;
                M[i][--j] = 1;
            }
        }

        maxd = 0; 
        for (int i = 0; i < N; i++)
        {
            d = 0;
            //--------------- DFS ---------------//
            for (int j = 0; j < N; j++)
                visited[j] = false;

            dfs(i);
            //-----------------------------------//
            if (d > maxd)
            {
                maxd = d;
                mostExpensive = i + 1;
            }
        }
        cout << mostExpensive << "\n";
    }
    return 0;
}
