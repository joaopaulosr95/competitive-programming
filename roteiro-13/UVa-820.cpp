#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;
const int INF = INT_MAX;
const int MAXV = 100;

int Graph[MAXV][MAXV];
int Residual[MAXV][MAXV];
int parent[MAXV];

//------------------- Ford-Fulkerson ------------------//
int findMaxFlow (int source, int sink, int size)
{
    int from, to, k, MAXF, flowCost;
    bool visited[size];
    queue<int> toVisit;
    
    for (from = 0; from < size; from++)
    { 
        for (to = 0; to < size; to++)
            Residual[from][to] = Graph[from][to];
    }
    MAXF = 0;
    while (true)
    {
        //-------------------- BFS --------------------//
        for (from = 0; from < size; from++)
            visited[from] = false;
        toVisit.push(source);
        visited[source] = true;
        parent[source] = -1; 
        
        while (!toVisit.empty())
        {
            int toV = toVisit.front();
            toVisit.pop();
            for (k = 0; k < size; k++)
            {
                if (!visited[k] && Residual[toV][k])
                {
                    toVisit.push(k);
                    parent[k] = toV;
                    visited[k] = true;
                }
            }
        }
        //---------------------------------------------//
        if (!visited[sink])
            break;
        else
        {
            flowCost = INT_MAX;
            for (to = sink; to != source; to = parent[to])
            {
                from = parent[to];
                flowCost = min (flowCost, Residual[from][to]);
            }
            for (to = sink; to != source; to = parent[to])
            {
                from = parent[to];
                Residual[from][to] -= flowCost;
                Residual[to][from] += flowCost;
            }
            MAXF += flowCost;
        }
    }
    return MAXF == INF ? 0 : MAXF;
}
//-----------------------------------------------------//

int main ()
{
    int i, j, N, flow, from, to, testN;
    
    testN = 0;
    cin >> N;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            Graph[i][j] = 0;

    while (cin >> from >> to >> flow)
    {
        Graph[from-1][to-1] = Graph[from-1][to-1] += flow;
    }
    flow = findMaxFlow (0, N-1, N);
    cout << "Network " << ++testN << "\n";
    cout << "The bandwidth is " << flow << endl;
}
