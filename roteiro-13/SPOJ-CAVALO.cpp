#include <iostream>     // std::cout
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;


int pred[203];
int g[203][203],f[203][203];
bool vist[203];

bool buscaP(int s, int t, int size){
    vist[s] = true;
    int v;
    if(s == t){ 
    return true;
        }
    for(v = 0; v < size; v++){
        if(g[s][v] - f[s][v] > 0 && !vist[v])
        {
            pred[v] = s;
            if(buscaP(v, t, size)){
			return true;
			}
        }
    }
    return false;
}

int ff_flow(int size, int s, int t){
    
    int deltaPath;
    int i, c;
    for(i = 0; i < size; i++){
        memset(f[i], 0, sizeof(int)*size);
		
    }
    pred[s] = s;
    memset(vist, false, sizeof(bool)*size);
    bool aux = buscaP(s, t, size);
    while(aux){
        deltaPath = INT_MAX;
        for(c = t; pred[c] != c; c = pred[c]){
            deltaPath = min(deltaPath, g[pred[c]][c] - f[pred[c]][c]);
      }
      for(c = t; pred[c] != c; c = pred[c]){
            f[pred[c]][c] += deltaPath;
            f[c][pred[c]] -= deltaPath;
      }
        memset(vist, false, sizeof(bool)*size);
        aux = buscaP(s, t, size);
    }
    int sum = 0;
    for(i = 0; i < size; i++)
    {
        sum += f[i][t];
    }
    return sum;
}

int main()
{
    int cav,sold,afin, num;
    for(num = 1; true; num++)
    {
		cin >> cav >> sold >> afin;
        if(std::cin.eof()){ 
        	break;
        }
		cout << "Instancia " << num << endl;
        int c, i;


        for(i = 0; i < cav + sold + 2; i++)
        {
            memset(g[i], 0, sizeof(int)*(cav+sold+2));
        }

        for(i = 1; i <= cav; i++){
			cin >> c;
            g[sold + i][cav + sold + 1] = c;
        }

        int u, v;

        for(i = 0; i < afin; i++)
        {
			cin >> u >> v;
            g[v][ sold + u] = 1;
        }

        for(i = 1; i <= sold; i++)
        {
            g[0][i] = 1;
        }

	cout << ff_flow(sold + cav + 2, 0, sold + cav + 1) << endl << endl;
    }
    return 0;
}
