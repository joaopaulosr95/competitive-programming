#include <iostream>

using namespace std;

void descobre(bool c[2000][2000], bool descobertos[],int n,int v){
	int i;

	for(i=0;i<n;i++){
		if(c[v][i]){
			if(descobertos[i]==true)
				continue;
			descobertos[i]=true;
			descobre(c,descobertos,n,i);
		}
	}
	return;
}

bool verifica(bool c[2000][2000],int n){
	int i,j;
	bool descobertos[2000];

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			descobertos[j]=false;
		}
		descobre(c,descobertos,n,i);
		for(j=0;j<n;j++){
			if(descobertos[j] == false)
				return false;
		}
	}
	return true;
}

int main(int argc, char** argv) {
	int p,v,w,i,j,n,m;
	bool c[2000][2000];

	while(cin>>n && n>= 2 && n<=2000){
		cin>>m;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				c[i][j]=false;
			}
		}
		for(i=0;i<m;i++){
			cin>>v;
			cin>>w;
			cin>>p;
			v--;
			w--;
			c[v][w]=true;
			if(p==2)
				c[w][v]=true;
		}
		if(verifica(c,n)){
			cout<<"1"<<endl;
		}else{
			cout<<"0"<<endl;
		}		
	}
	return 0;
}
