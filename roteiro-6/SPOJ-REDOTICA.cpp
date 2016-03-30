#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> __trees;
struct Edge
{
    int from;
    int to;
    int weight;
};

bool cmp (const struct Edge& E1, const struct Edge& E2)
{
    return E1.weight < E2.weight;
}

bool cmpSol (const pair<int,int>& a, const pair<int,int>& b)
{
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}

int kFind (int u)
{
    int i;
    
    for (i = u; __trees[i] != i; i = __trees[i]);
    __trees[u] = i;
    return i;
}

void kUnion (int u, int v)
{
    __trees[kFind(u)] = kFind(v);
}

int main ()
{
    int testN, N, M, i;
    struct Edge tmp;
    vector<struct Edge> graph;
    vector< pair<int,int> > solution;
    
    testN = 1;
    while ((cin >> N >> M) && (N != 0 && M != 0))
    {
        for (i = 0; i < M; i++)
        {
            cin >> tmp.from >> tmp.to >> tmp.weight;
            graph.push_back(tmp);
        }

        //------------------- KRUSKAL -------------------//
        cout << "Ordenando" << endl;
        sort(graph.begin(), graph.end(), cmp);
        for (i = 0; i < N; i++)
            __trees.push_back(i);
        for (i = 0; i < M; i++)
        {
            if (kFind(graph[i].from) != kFind(graph[i].to))
            {
                cout << "Aresta unindo " << graph[i].from << " e " << graph[i].to << endl;
                kUnion(graph[i].from, graph[i].to);
                solution.push_back(make_pair(graph[i].from, graph[i].to));
            }
        }
        //-----------------------------------------------//
        cout << "Teste << " << testN++ << endl;
        sort(solution.begin(), solution.end(), cmpSol);
        for (i = 0; i < solution.size(); i++)
            cout << solution[i].first << " " << solution[i].second << endl;
        cout << endl;
        vector<int>().swap(__trees);
        vector< pair<int,int> >().swap(solution);

    }

    return 0;
}
