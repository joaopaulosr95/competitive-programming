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


int confReq(int N, int W){
	if (N>0 && N<100 && W>-10 && W<2000) aux=1;
	else aux=0;
}

int impResult(int minCost){
    int N,W;
    confReq(N,W);
	if (aux!=1) cout << minCost << endl;
	else cout << "ERRO" ;
	}

int main()
{
    int N,W,idComp, costPC, dRemet, pDestin, costWire;
    while(true){
	cin >> N >> W;
	confReq(N,W);
    if (N+W == 0 && (aux!=1) )
        break;
        mach = N-1;
        cenSer = N;
    for (int i = 0; i < 2*N; i++)
        for (int j = 0 ;j < 2*N; j++)
       	res[i][j] = -1;


    for (int i = 1; i < N-1; i++){
	cin >> idComp >> costPC;
        idComp--;
        res[idComp][idComp+N] = res[idComp+N][idComp] = costPC;
		  }

        for (int i = 0; i < W; i++){
        cin >> dRemet >> pDestin >> costWire;
        dRemet--;
        pDestin--;
        res[dRemet+N][pDestin] = res[pDestin+N][dRemet] = costWire;

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
    for (int v = 0; v < 2*N; v++){
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
