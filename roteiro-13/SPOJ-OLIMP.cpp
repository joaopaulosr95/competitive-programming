#include <iostream>
#include <climits>
#include <string.h>
#include <queue>
#define N 50



using namespace std;

class Fluxo {
public:
	int distancia[N];
	int capacidade[N];
	int q;

	inline void restart(int n) {
		q = 0;
		for (int i = 0;i < n;i++) {
			distancia[i] = false;
		}
	}
	void insert(int d, int c) {
		capacidade[q] = d;
		distancia[q] = c;
		q++;
	}
};

bool bfs(int rGraph[N][N], int s, int t, int caminho[], int n)
{
	bool visitados[N];
	int i, j;
	queue <int> q;

	for (i = 0;i < n;i++)
		visitados[i] = false;
	q.push(s);
	visitados[s] = true;
	caminho[s] = -1;
	while (!q.empty()){
		i = q.front();
		q.pop();
		for (j = 0; j<n; j++){
			if (visitados[j] == false && rGraph[i][j] > 0){
				q.push(j);
				caminho[j] = i;
				visitados[j] = true;
			}
		}
	}
	return (visitados[t] == true);
}

int fordFulkerson(int graph[N][N],Fluxo *fluxo, int s, int t, int n)
{
	int i, j, distancia, fluxo_maximo, fluxo_caminho;
	int rGraph[N][N], caminho[N];;

	fluxo_maximo = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			rGraph[i][j] = graph[i][j]; 
	while (bfs(rGraph, s, t, caminho, n)){
		fluxo_caminho = INT_MAX;
		for (j = t; j != s; j = caminho[j]){
			i = caminho[j];
			fluxo_caminho = min(fluxo_caminho, rGraph[i][j]);
		}
		for (distancia=0, j = t; j != s; j = caminho[j],distancia++){
			i = caminho[j];
			rGraph[i][j] -= fluxo_caminho;
			rGraph[j][i] += fluxo_caminho;
		}
		fluxo_maximo += fluxo_caminho;
		fluxo->insert(fluxo_caminho, distancia);
	}
	return fluxo_maximo;
}

int main() {
	int i,dias,viajaram, j, n, m, a, o, d, s, grafo[N][N];
	Fluxo fluxo;

	while (scanf("%d %d %d", &n, &m, &a) && n && m && a) {
		fluxo.restart(n);
		for (i = 0;i < n;i++) {
			for (j = 0;j < n;j++) {
				grafo[i][j] = 0;
			}
		}
		for (i = 0;i < m;i++) {
			scanf("%d %d %d", &o, &d, &s);
			o--;
			d--;
			grafo[o][d] = s;
		}
		fordFulkerson(grafo, &fluxo,0, n - 1, n);
		dias = 0;
		viajaram = 0;
		while (viajaram < a) {
			viajaram = 0;
			for (i = 0;i < fluxo.q;i++) {
				viajaram += (dias >= fluxo.distancia[i] ? (dias - fluxo.distancia[i] + 1) : 0)*fluxo.capacidade[i];
			}
			dias++;
		}
		printf("%d\n", dias - 1);
	}
	return 0;
}
