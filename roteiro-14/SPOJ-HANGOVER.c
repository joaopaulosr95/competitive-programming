#include <stdio.h>
#include <stdlib.h>

int main(){
	double sum;
	float target;
	int cards;
	
	while(scanf("%f",&target)){
		if(target == 0)break;
		for(sum=0.0,cards=0;sum<target;cards++){
			sum+=1/(double)(cards+2);
		}
	printf("%d card(s)\n",cards);
	}
	return 0;
}
