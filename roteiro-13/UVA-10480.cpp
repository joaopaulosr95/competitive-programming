#include <cstdio>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>

using namespace std;

int bfs(int rGraph[51][51], int s, int t, int caminho[],int n)
{
	bool visitado[51];
	int i,j;
	queue <int> q;
	
	for(i=0;i<n;i++)
		visitado[i]=false;
	q.push(s);
	visitado[s] = true;
	caminho[s] = -1;
	while (!q.empty())
	{
		j = q.front();
		q.pop();
		for (i=0; i<n; i++)
		{
			if (visitado[i]==false && rGraph[j][i] > 0)
			{
				q.push(i);
				caminho[i] = j;
				visitado[i] = true;
			}
		}
	}
	return (visitado[t] == true);
}
 
void dfs(int rGraph[51][51], int s, bool visitado[],int n)
{
	int i;
	
	visitado[s] = true;
	for (i= 0; i < n; i++)
	   if (rGraph[s][i] && !visitado[i])
		   dfs(rGraph, i, visitado,n);
}
 
void minCut(int cidade[51][51], int s, int t,int n)
{
	int i, j,c;
	bool visitado[51];
	int caminho[51];
	int rGraph[51][51];
	
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			 rGraph[i][j] = cidade[i][j];
	while (bfs(rGraph, s, t, caminho,n))
	{
		c = INT_MAX;
		for (j=t; j!=s; j=caminho[j])
		{
			i = caminho[j];
			c = min(c, rGraph[i][j]);
		}

		for (j=t; j != s; j=caminho[j])
		{
			i = caminho[j];
			rGraph[i][j] -= c;
			rGraph[j][i] += c;
		}
	}
	for(i=0;i<n;i++)
		visitado[i]=false;
	dfs(rGraph, s, visitado,n);
	for (int i = 0; i < n; i++)
	  for (int j = 0; j < n; j++)
		 if (visitado[i] && !visitado[j] && cidade[i][j])
			 printf("%d %d\n",j+1,i+1);
	  printf("\n");
	return;
}

int main(){
	int i,j,n,m,c1,c2,c,cidade[51][51];
	
	while(scanf("%d %d",&n,&m) && n && m){
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				cidade[i][j]=0;
		for(i=0;i<m;i++){
			scanf("%d %d %d",&c1,&c2,&c);
			cidade[c1-1][c2-1]=cidade[c2-1][c1-1]=c;
		}
		minCut(cidade, 0, 1,n);
	}
}
