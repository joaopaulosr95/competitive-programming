#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, pair<int, int> > Edge;
typedef vector<Edge> Graph;

vector<int> __trees;

bool cmp(const Edge& u, const Edge& v)
{
    if (u.first == v.first)
    {
        if (u.second.first == v.second.first)
            return u.second.second < v.second.second;
        else
            return u.second.first < v.second.first;
    }
    else
        return u.first < v.first;
}

bool cmpSol(const Edge& u, const Edge& v)
{
    if (u.second.first == v.second.first)
        return u.second.second < v.second.second;
    else
        return u.second.first < v.second.first;
}

int kfind (int u)
{
    int i = u;
    while (i != __trees[i])
        i = __trees[i];
    return i;
}

int kunion (int u, int v)
{
    __trees[kfind(u)] = kfind(v);
}


int main ()
{
    int N, M, testN, i, from, to, w;
    Graph G, S; 

    testN = 1;
    while (cin >> N >> M && N != 0)
    {
        Graph().swap(G);
        Graph().swap(S);
        vector<int>().swap(__trees);
        for (i = 0; i < N; i++)
            __trees.push_back(i);

        for (i = 0; i < M; i++)
        {
            cin >> from >> to >> w;
            if (from > to)
                swap (from, to);
            //cout << from << " " << to << " " << w << endl;
            Edge e = make_pair(w, make_pair(from, to));
            //cout << e.second.first << " " << e.second.second << " " << e.first << endl;
            G.push_back(e);
        }

        //------------- KRUSKAL-------------//
        sort(G.begin(), G.end(), cmp);
        /*for (i = 0; i < G.size(); i++)
            cout << G[i].second.first << " " << G[i].second.second << " " << G[i].first << endl;
        cout << endl;*/
        for (i = 0; i < M; i++)
        {
            /*cout << "from: " << G[i].second.first << " to: " << G[i].second.second << endl;
            cout << kfind(G[i].second.first) << " " << kfind(G[i].second.second) << endl;*/
            if (kfind(G[i].second.first) != kfind(G[i].second.second))
            {
                //cout << "Added!" << endl;
                S.push_back(G[i]);
                kunion(G[i].second.first, G[i].second.second);
            }
        }
        //----------------------------------//
        sort(S.begin(), S.end(), cmpSol); 
        cout << "Teste " << testN++ << endl;
        for (i = 0; i < S.size(); i++)
            cout << S[i].second.first << " " << S[i].second.second << endl;
        cout << endl;
    }
    return 0;
}
