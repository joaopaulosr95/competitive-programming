#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 10005;

int main() 
{
    int n, k, m, x, y, total;
    vector<int> adj[MAX], last;
    bool visited[MAX];
    queue<pair<int,int> > toV;

    while(cin >> n >> k >> m && n != 0) 
    {
        for(int i = 0; i < n; i++)
        {
            adj[i].clear();
            visited[i] = false;
        }

        // Inserir na fila da bfs as pessoas que sabiam no dia 1
        for(int i = 0; i < k; i++)
        {
            cin >> x;
            --x;
            toV.push(make_pair(x, 1));
        }

        // Ler as relacoes de amizade e criar a aresta bidirecional
        for(int i = 0; i < m; i++) 
        {
            cin >> x >> y;
            --x;
            --y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        total = 0;
        //--------------- BFS ---------------//
        while(!toV.empty()) 
        {
            pair<int,int> u = toV.front(); 
            toV.pop();

            if(visited[u.first]) continue;
            visited[u.first] = true;

            if(u.second > total)
            {
                last.clear();
                total = u.second;
            }
            last.push_back(u.first);

            for(vector<int>::iterator it = adj[u.first].begin(); 
                    it != adj[u.first].end(); it++)
            {
                //cout << *it << "\n";
                toV.push(make_pair(*it, u.second + 1));
            }
        }
        //------------------------------------//

        // Ordena a relacao de pessoas 
        sort(last.begin(), last.end());
        
        for(int i = 0; i < last.size() - 1; i++)
            cout << last[i] + 1 << " ";
        cout << last[last.size() - 1] + 1 << "\n";
    }
    return 0;
}
