#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void quick(int r[], int esq, int dir){
	int pivo = esq,i,ch,j;
	for(i=esq+1;i<=dir;i++){
		j = i;
		if(r[j] < r[pivo]){
		 ch = r[j];
		 while(j > pivo){	
			r[j] = r[j-1];
			j--;
		 }
		 r[j] = ch;
		 pivo++;		
		}  
	}
	if(pivo-1 >= esq){
		quick(r,esq,pivo-1);
	}
	if(pivo+1 <= dir){
		quick(r,pivo+1,dir);
	}
 }


int main(){
	int i,n,r[1000];
	float sum;
	
	sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",r+i);
	}
	quick(r,0,n-1);
	if(!n%2)n--;
	for(i=0;i<n;i++){
		if(i%2)
			sum-=r[i]*r[i];
		else
			sum+=r[i]*r[i];
	}
	if(sum<0)
		printf("%.10f",sum*M_PI*-1);
	else
		printf("%.10f",sum*M_PI);
}
