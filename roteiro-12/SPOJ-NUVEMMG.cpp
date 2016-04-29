#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

const int MAXL = 501;
const int MAXK = 501;
const int INF = 1000000000;

vector<pair<int,int> > servers;

int main()
{
    int K, L, D, P, budget[MAXL][MAXK], mincost;

    while (cin >> K >> L && (K != 0 && L != 0))
    {
        for (int i = 0; i < K; i++)
        {
            cin >> D >> P;
            servers.push_back(make_pair(D, P));
        }

        sort(servers.begin(), servers.end());
        /*for (vector<pair<int,int> >::iterator it = servers.begin(); it != servers.end(); it ++)
            cout << it->first << " " << it->second << "\n";*/

        for (int i = 0; i < MAXL; i++)
            for (int j = 0; j < MAXK; j++)
                budget[i][j] = INF;
        //cout << "OK\n";

        for (int i = 1; i <= K; i++)
            budget[i-1][0] = i * servers[i-1].second;
        //cout << "OK\n";
        
        for (int i = 1; i < L; i++)
        {
            for (int j = i; j < K; j++)
            {
                mincost = INF;
                for (int z = 1; j-z >= 0; z++)
                        mincost = min(mincost,
                            budget[j-z][i-1] + z * servers[j].second);
                    //cout << "mincost: " << mincost << "\n";
                budget[j][i] = mincost;
            }
        }

        cout << budget[K-1][L-1] << "\n";

        vector<pair<int,int> >().swap(servers);
    }

    return 0;
}
