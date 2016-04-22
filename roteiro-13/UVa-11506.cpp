#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

#define DEF 107000000

using namespace std;

int cenSer,mach,auxCos,aux;
int res[300][300];
vector<int> vec;

void ff_flow(int v, int minimo){
     if (v == cenSer){
        auxCos = minimo;
        return;
     } else if (vec[v] != -1){
       ff_flow(vec[v],min(minimo,res[vec[v]][v]));
       res[vec[v]][v] = res[vec[v]][v] - auxCos;
       res[v][vec[v]] = res[v][vec[v]] + auxCos;
     }
}


int confereNeW(int M, int W){
	if (M>0 && M<100 && W>-10 && W<2000) aux=1;
	else aux=0;
}

int impResult(int minCost){
    int N,W;
    confereNeW(N,W);
	if (aux!=1) cout << minCost << endl;
	else cout << "ERRO" ;
	}

int main(void)
{
    int M,W;
    while(true){
		cin >> M >> W;
		confereNeW(M,W);
		if (M+W == 0 && (aux!=1) )
           break;
        mach = M-1;
        cenSer = M;
        for (int i = 0; i < 2*M; i++)
            for (int j = 0 ;j < 2*M; j++)
                res[i][j] = -1;


        for (int i = 1; i < M-1; i++){
            int idComp, costPC;
			cin >> idComp >> costPC;
            idComp--;
            res[idComp][idComp+M] = res[idComp+M][idComp] = costPC;
        }

        for (int i = 0; i < W; i++){
            int dRemet, pDestin, costWire;
            cin >> dRemet >> pDestin >> costWire;
            dRemet--;
            pDestin--;
            res[dRemet+M][pDestin] = res[pDestin+M][dRemet] = costWire;

        }


        int minCost = 0;
        while(true){
            auxCos = 0;
            vector<int> dist;
            dist.assign(300, DEF);
            dist[cenSer] = 0;
            queue<int> fila;
            fila.push(cenSer);
            vec.assign(300, -1);
            while (!fila.empty()){
                  int u = fila.front(); fila.pop();
                  if (u == mach){
                     break;
					 }
                 for (int v = 0; v < 2*M; v++){
                     if (res[u][v] > 0 && dist[v] == DEF){
                         dist[v] = dist[u] + 1;
                         fila.push(v);
                         vec[v] = u;
                     }
                 }
            }
            ff_flow(mach,DEF);
            if (auxCos == 0)
               break;
            minCost = minCost+ auxCos;
        }

		impResult(minCost);

    }
    return 0;
}
