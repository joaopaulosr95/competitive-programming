#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int x[1000],y[1000],i,j,n;
	double r;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d %d",x+i, y+i);
	r=hypot(x[0]-x[1],y[0]-y[1]);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j && r>hypot(x[i]-x[j],y[i]-y[j]))
				r=hypot(x[i]-x[j],y[i]-y[j]);
		}
	}
	printf("%.3f",r);
}
