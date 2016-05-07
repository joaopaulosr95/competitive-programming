/* 
 * File:   SPOJ-NLOGONIA.cpp
 * Author: tbarreto
 *
 * Created on 6 de Maio de 2016, 10:27
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	int i,k,n,m,x,y;
	char direcao[3];
	
	direcao[2]='\0';
	while(scanf("%d %d %d",&k, &n,&m) && k){
		for(i=0;i<k;i++){
			scanf("%d %d",&x,&y);
			if(n==x || m==y){
				printf("divisa\n");
				continue;
			}
			if(y>m)
				direcao[0]='N';
			else
				direcao[0]='S';
			if(x>n)
				direcao[1]='E';
			else
				direcao[1]='O';
			printf("%s\n",direcao);
		}
	}
	return 0;
}
