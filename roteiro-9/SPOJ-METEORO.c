#include <stdio.h>
#include <stdlib.h>

int main(){
        int i,x1,y1,x2,y2,y,x,n,cairam,teste;

        for(teste=1,cairam=0;;cairam=0,teste++){
                scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&n);
                if( !(x1||y1||x2||y2) )return 0;
                for(i=0;i<n;i++){
                        scanf("%d %d",&x,&y);
                        if(x>=x1 && x<=x2 && y<=y1 &&y>=y2)cairam++;
                }
                printf("Teste %d\n%d\n\n",teste,cairam);
        }
}
