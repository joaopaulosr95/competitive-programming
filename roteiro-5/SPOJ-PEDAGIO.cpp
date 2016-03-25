#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main ()
{
  int testNumber, C, E, L, P, adjMatrix[51][51], k, fromV, toV, dist[51];
  vector<int> solution;
  bool visited[51];

  testNumber = 1;
  while ((cin >> C >> E >> L >> P) &&
      (C != 0 && E != 0 && L != 0 && P != 0))
  {
    for (fromV = 1; fromV <= E; fromV++)
      for (toV = 1; toV <= E; toV++)
        adjMatrix[fromV][toV] = 0;
    
    for (k = 1; k <= E; k++)
    {
      cin >> fromV >> toV;
      adjMatrix[fromV][toV] = 1;
      adjMatrix[toV][fromV] = 1;
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
    
    //----------------------------------------//
    for (k = 1; k <= C; k++)
    {
      visited[k] = false;
      dist[k] = 99999999;
    }
    
    dist[L] = 0;
    priority_queue< pair<int,int> > toVisit;
    toVisit.push(make_pair(0,L));
    while (!toVisit.empty())
    {
      toV = toVisit.top().second;
      toVisit.pop();

      for (k = 1; k <= C; k++)
      {
        if (adjMatrix[toV][k] == 1 && dist[toV] + 1 <= dist[k])
        {
          dist[k] = dist[toV] + 1;
          toVisit.push(make_pair(dist[k],k));
        }
      }
    }

    for (k = 1; k <= C; k++)
      if (dist[k] <= P && k != L)
        solution.push_back(k);
    //----------------------------------------//

    sort(solution.begin(),solution.end());
    cout << "Teste " << testNumber++ << endl;
    for (k = 0; k < solution.size(); k++)
      cout << solution[k] << " ";
    cout << endl;

    vector<int>().swap(solution);
  }
  return 0;
}
