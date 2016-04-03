#include <iostream>
#include <cstdlib>

using namespace std;
//By Tales Barreto

int main(){
	int i,j,n,k,m, musico[101][101],x,y,z,e[3];

	cin>>n;
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			musico[i][j]=0;
		}
	}
	e[0]=1;
	e[1]=2;
	e[2]=3;
	cin>>m;
	for(i=0;i<m;i++){
		cin>>x;
		cin>>y;
		cin>>z;
		musico[x][y]=z;
		musico[y][x]=z;
	}
	for(z=0,i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j)continue;
			for(k=1;k<=n;k++){
				if(k==j || k==i)continue;
				if(musico[i][j]+musico[j][k]+musico[i][k] > z &&(
						musico[i][j] && musico[j][k] ||
						musico[i][k] && musico[k][j] ||
						musico[k][i] && musico[i][j]					
						)){
					z = musico[i][j] + musico[j][k] + musico[i][k];
					e[0]=i;
					e[1]=j;
					e[2]=k;
				}
			}
		}
	}
	cout << e[0]<<" "<<e[1]<<" "<<e[2];
	return 0;
}
