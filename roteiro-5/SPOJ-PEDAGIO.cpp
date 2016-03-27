#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main ()
{
  int testNumber, C, E, L, P, k, fromV, toV, dist[51];
  bool adjMatrix[51][51];
  vector<int> solution;
  queue<int> toVisit;

  testNumber = 1;
  while ((cin >> C >> E >> L >> P) &&
      (C != 0 && E != 0 && L != 0 && P != 0))
  {
    for (fromV = 1; fromV <= C; fromV++)
      for (toV = 1; toV <= C; toV++)
        adjMatrix[fromV][toV] = false;

    for (k = 1; k <= E; k++)
    {
      cin >> fromV >> toV;
      adjMatrix[fromV][toV] = adjMatrix[toV][fromV] = true;
    }
/*    for (fromV = 1; fromV <= C; fromV++)
    {
      for (toV = 1; toV <= C; toV++)
      {
        cout << adjMatrix[fromV][toV] << " ";
      }
      cout << endl;
    }
    cout << endl;
*/
    //------------------ DIJKSTRA -----------------//
    for (k = 1; k <= C; k++)
      dist[k] = 99999999;  
    dist[L] = 0;
    toVisit.push(L);
    while (!toVisit.empty())
    {
      toV = toVisit.front();
      toVisit.pop();
      for (k = 1; k <= C; k++)
      {
        if (adjMatrix[toV][k] && k != L && dist[k] == 99999999)
        {
          dist[k] = dist[toV] + 1;
          toVisit.push(k);
        }
      }
    }
    for (k = 1; k <= C; k++)
      if (dist[k] <= P && k != L)
        solution.push_back(k);
    //---------------------------------------------//
    //sort(solution.begin(),solution.end());
    cout << "Teste " << testNumber++ << endl;
    for (k = 0; k < solution.size(); k++)
    {
      if (k == 0)
        cout << solution[k];
      else
        cout << " " << solution[k];
    }
    cout << endl << endl;
    vector<int>().swap(solution);
  }
  return 0;
}
