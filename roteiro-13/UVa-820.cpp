#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;
const int INF = INT_MAX;
const int MAXV = 110;

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
    return MAXF;
}
//-----------------------------------------------------//

int main ()
{
    int testN, N, i, j, 
        s, t, c, 
        from, to, flow;
    
    testN = 0;
    while (cin >> N && N != 0)
    {
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                Graph[i][j] = 0;

        cin >> s >> t >> c;
        s--;
        t--;
        while (c)
        {
            cin >> from >> to >> flow;
            from--;
            to--;
            Graph[from][to] = Graph[to][from] += flow;
            c--;
        }
        flow = findMaxFlow (s, t, N);
        cout << "Network " << ++testN << "\n";
        cout << "The bandwidth is " << flow << ".\n\n";
    }
    return 0;
}
