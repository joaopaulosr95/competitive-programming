/*
* File:   SPOJ-DESVIO.cpp.cpp
* Author: barreto
*
* Created on April 16, 2016, 9:53 PM
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <climits>

using namespace std;

int dijkstra(int grafo[250][250],int a,int b,int n) {
	bool aberto[250];
	int restando,i,j,custo[250];
	
	for (i = 0; i < n; i++) {
		aberto[i] = false;
		custo[i] = INT_MAX;
	}
	custo[a] = 0;
	aberto[a] = true;
	do{
		restando = n;
		for (i = 0; i < n; i++) {
			if (aberto[i]) {
				for (j = 0; j < n; j++) {
					if (grafo[i][j] != INT_MAX && custo[j]>custo[i] + grafo[i][j]) {
						custo[j] = custo[i] + grafo[i][j];
						aberto[j] = true;
					}
					aberto[i] = false;
				}
			}
			else {
				restando--;
			}
		}
	}while(restando);
	return custo[b];
}

int main(){
	int i,j,n, m, c, k, u, v, p;
	int cidade[250][250];

	for (;;) {
		cin >> n >> m >> c >> k;
		if (!n && !m && !c && !k)break;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				cidade[i][j] = INT_MAX;
		for (i = 0; i < m; i++) {
			cin >> u >> v >> p;
			if (u < c && v < c) {
				if (u == v - 1)
					cidade[u][v] = p;
				if(v == u - 1)
					cidade[v][u] = p;
			}
			if (u < c && v >= c)
				cidade[v][u] = p;
			if (v < c && u >= c)
				cidade[u][v] = p;
			if (u >= c && v >= c)
				cidade[u][v] = cidade[v][u] = p;
		}
	cout << dijkstra(cidade, k, c-1, n) << endl;
	}
}
