/* 
 * File:   SPOJ-MESA.cpp
 * Author: barreto
 *
 * Created on April 9, 2016, 3:16 PM
 */
#include <stdio.h> //Tomei TLL na iostream TT

using namespace std;

bool senta(int c,bool amigos[100][100],int n, char lugar[100]){
	int i;
	
	for(i=0;i<n;i++){
		if(amigos[c][i] == false)continue;
		if(lugar[i]){
			if(lugar[i] == lugar[c])
				return false;
			else
				continue;
		}
		if(lugar[c] == 'e')
			lugar[i]='d';
		else
			lugar[i]='e';
		if(senta(i,amigos,n,lugar) == false)return false;
	}
	return true;
}

bool verifica(bool amigos[100][100],int n){
	int i;
	char lugar[100];
	
	for(i=0;i<n;i++)
		lugar[i]=0;
	for(i=0;i<n;i++){
		if(lugar[i])continue;
		lugar[i]='e';
		if(senta(i,amigos,n,lugar) == false)return false;
	}
	return true;
}

int main() {
	int i,j,n,m,u,v,instancia;
	bool amigos[100][100];
	
	for(instancia=1;fscanf(stdin,"%d", &n) &&  !feof(stdin);instancia++){
		fscanf(stdin,"%d",&m);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				amigos[i][j]=false;
			}
		}
		for(i=0;i<m;i++){
			scanf("%d %d", &u, &v);
			v--;
			u--;
			amigos[u][v]=true;
			amigos[v][u]=true;
		}
		if(verifica(amigos,n))
			printf("Instancia %d\nsim\n", instancia);
		else
			printf("Instancia %d\nnao\n", instancia);
	}
	return 0;
}
