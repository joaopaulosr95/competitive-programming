#include <iostream>

using namespace std;

int main ()
{
  int E, L, i, j, k, N;
  bool adjMatrix[101][101];

  N = 1;
  while ((cin >> E >> L) && (E != 0 && L != 0))
  {
    for (i = 1; i <= E; i++)
      for (j = 1; j <= E; j++)
        adjMatrix[i][j] = false;

    for (i = 1; i <= L; i++)
    {
      cin >> j >> k;
      adjMatrix[j][k] = adjMatrix[k][j] = true;
    }

    for (i = E; i > 0; i--)
      for (j = E; j > 0; j--)
        if (adjMatrix[i][j])
          for (k = 1; k <= E; k++)
            if (adjMatrix[j][k])
              adjMatrix[i][k] = true;

    k = 0;
    for (i = 1; i <= E; i++)
      if (adjMatrix[1][i])
        k++;

    cout << "Teste " << N++ << endl;
    if (k == E)
      cout << "normal" << endl;
    else
      cout << "falha" << endl;
    cout << endl;
  }
  return 0;
}
