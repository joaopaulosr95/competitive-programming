#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int l,c,r1,r2;
    for(;;){
        scanf("%d %d %d %d",&l,&c,&r1,&r2);
        if(!(l||c||r1||r2))break;
        if(2*r1>l || 2*r1>c|| 2*r2>l || 2*r2>c){
            printf("N\n");
            continue;
        }
        if(hypot(l-r1-r2,c-r1-r2)>=r1+r2)
            printf("S\n");
        else
            printf("N\n");
    }
    return 0;
}
