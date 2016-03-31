#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

vector<int> __trees;

struct Edge
{
    int from;
    int to;
    int weight;

    Edge (int from, int to, int weight)
    {
        this->from = from; 
        this->to = to; 
        this->weight = weight;
    }
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
    int i = u;
    while (i != __trees[i])
        i = __trees[i];
    return i;
}

int kUnion (int u, int v)
{
    __trees[kFind(u)] = kFind(v);
}

int main ()
{
    int testN, N, M, i, from, to, w;
    vector<struct Edge> graph;
    vector< pair<int,int> > solution;
    
    testN = 1;
    while ((cin >> N >> M) && N != 0)
    { 
        vector<struct Edge>().swap(graph);
        vector<int>().swap(__trees);
        vector< pair<int,int> >().swap(solution);
        
        for (i = 0; i < M; i++)
        {
            cin >> from >> to >> w;
            struct Edge E (from,to,w);
            graph.push_back(E);
        }

        //------------------- KRUSKAL -------------------//
        //cout << "Ordenando" << endl;
        sort(graph.begin(), graph.end(), cmp);
        for (i = 0; i < N; i++)
            __trees.push_back(i);
        for (i = 0; i < M; i++)
        {
            if (kFind(graph[i].from) != kFind(graph[i].to))
            {
                //cout << "Aresta unindo " << graph[i].from << " e " << graph[i].to << endl;
                kUnion(graph[i].from, graph[i].to);
                if (graph[i].from < graph[i].to)
                    solution.push_back(make_pair(graph[i].from, graph[i].to));
                else
                    solution.push_back(make_pair(graph[i].to, graph[i].from));
            }
        }
        //-----------------------------------------------//
        sort(solution.begin(), solution.end(), cmpSol);
        //solution.erase( unique(solution.begin(), solution.end()), solution.end() );
        cout << "Teste " << testN++ << endl;
        for (i = 0; i < solution.size(); i++)
            cout << solution[i].first << " " << solution[i].second << endl;
        cout << endl;

    }

    return 0;
}
