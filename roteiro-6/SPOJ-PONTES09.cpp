#include <iostream>
#include <climits>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int INF = INT_MAX;

int main ()
{
	int N, M, i, fromV, toV, weight,
		dist[1001], 
		adjMatrix[1001][1001];
	queue<int> toVisit;

	cin >> N >> M;
    for (fromV = 0; fromV <= N+1; fromV++)
    {
        dist[fromV] = INF;
        for (toV = 0; toV <= N+1; toV++)
            adjMatrix[fromV][toV] = -1;
    }

    for (i = 0; i < M; i++)
    {
        cin >> fromV >> toV >> weight;
        //cout << fromV << " " << toV << " " << weight << endl;
        adjMatrix[fromV][toV] = weight;
        adjMatrix[toV][fromV] = weight;
    }

    /*for (fromV = 0; fromV <= N+1; fromV++)
    {
        for (toV = 0; toV <= N+1; toV++)
            cout << setw(3) << adjMatrix[fromV][toV] << " ";
        cout << endl;
    }*/

    //------------------ DIJKSTRA -----------------//
	dist[0] = 0;
    toVisit.push(0);
    while (!toVisit.empty())
    {
        toV = toVisit.front();
        //cout << "Escolhido: " << toV << endl;
        toVisit.pop();
        for (i = 0; i <= N+1; i++)
        {
            //cout << i << endl;
            if (adjMatrix[toV][i] != -1 && 
                dist[toV] + adjMatrix[toV][i] < dist[i])
            {
                dist[i] = dist[toV] + adjMatrix[toV][i];
                toVisit.push(i);
            }
        }
    }
	//---------------------------------------------//
    
    /*for (i = 0; i <= N+1; i++)
        cout << dist[i] << " ";
    cout << endl;*/
    cout << dist[N+1] << endl;
	return 0;
}
