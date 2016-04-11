#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;
const int INF = INT_MAX;
const int MAX = 52;

int Graph[MAX][MAX];
int Residual[MAX][MAX];
int parent[MAX];

//------------------- Ford-Fulkerson ------------------//
int findMaxFlow (int source, int sink)
{
    int from, to, k, maxF, flowCost;
    bool visited[MAX];
    queue<int> toVisit;
    
    for (from = 0; from < MAX; from++)
    { 
        for (to = 0; to < MAX; to++)
            Residual[from][to] = Graph[from][to];
    }
    maxF = 0;
    while (true)
    {
        //-------------------- BFS --------------------//
        for (from = 0; from < MAX; from++)
            visited[from] = false;
        toVisit.push(source);
        visited[source] = true;
        parent[source] = -1; 
        
        while (!toVisit.empty())
        {
            int toV = toVisit.front();
            toVisit.pop();
            for (k = 0; k < MAX; k++)
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
            maxF += flowCost;
        }
    }
    return maxF == INF ? 0 : maxF;
}
//-----------------------------------------------------//

int main ()
{
    int i, j, N, flow;
    char from, to;
    
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            Graph[i][j] = 0;

    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> from >> to >> flow;
        //To correct ASCII interval between 91 and 96
        //we remove 6 from 'from' and 'to' variables
        if (from >= 97 && from <= 122)
            from -= 6;
        if (to >= 97 && to <= 122)
            to -= 6;
        Graph[from - 65][to - 65] = Graph[from - 65][to - 65] += flow;
    }

    flow = findMaxFlow (0, 25);
    cout << flow << endl;
}
