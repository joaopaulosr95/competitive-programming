#include <iostream>
#include <iomanip>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 99999;
const int NMAX = 110;

int main ()
{
    int N, M, i, from, to, w,
        dist[NMAX],
        adj[NMAX][NMAX];
    queue<int> toVisit;

    while ((cin >> N >> M) && N != 0)
    {
        for (i = 1; i <= N; i++)
        {
            for (w = 1; w <= N; w++)
                adj[i][w] = INF;
            dist[i] = INF;
        }

        for (i = 1; i <= M; i++)
        {
            cin >> from >> to >> w;
            if (from == to)
                w = 0;
            adj[from][to] = w;
        }
		
		/*for (i = 1; i <= N; i++)
        {
            for (w = 1; w <= N; w++)
                cout << setw(5) << adj[i][w] << " ";
            cout << endl;
        }*/

        cin >> from >> to;
        if (from == to)
            cout << "0" << endl;
        else
        {
            //------------------ DIJKSTRA -----------------//
    	    dist[from] = 0;
    	    toVisit.push(from);
    	    while (!toVisit.empty())
    	    {
    	      w = toVisit.front();
    	      toVisit.pop();
    	      for (i = 1; i <= N; i++)
    	      {
    	        if (adj[w][i] < INF && dist[w] + adj[w][i] < dist[i])
    	        {
    	          dist[i] = dist[w] + adj[w][i];
    	          toVisit.push(i);
    	        }
    	      }
    	    }
    		//---------------------------------------------//
    		/*for (i = 1; i <= N; i++)
                cout << setw(6) << dist[i] << " ";
            cout << endl;*/

            if (dist[to] == INF)
    			cout << "-1" << endl;
    		else
    			cout << dist[to] << endl;
        }
    }

    return 0;
}
