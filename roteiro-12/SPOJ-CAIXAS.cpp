#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <string>
#include <iterator>

using namespace std;

int main(){

    int N,P;
    int **matriz;
    int guardaLinha,guardaColuna,tam;
    while(cin >> N >> P && N!=0 && P!=0){
    int cnt=0;
    int cntauxEsquerda=0,cntauxDireita=0;
    matriz= new int *[P];

    for(int i=0;i<P;i++){

        matriz[i]=new int[N];

        for(int j=0;j<N;j++){

            matriz[i][j]= 0;

        }

    }


    for(int k=0;k<P;k++){
        cin >> tam;

        for(int l=0;l<tam;l++){
            cin >> matriz[k][l];
        }

    }

   /* for (int l1=0;l1<P;l1++){
    	cout << endl;
    	for (int c1=0;c1<N;c1++){
    		cout << matriz[l1][c1] << " " ;

    	}
    }*/


    for(int r=0;r<P;r++){
    	int aux=0;
        while(matriz[r][aux]!=0){

                if(matriz[r][aux]==1){
                    guardaLinha=r;
                    guardaColuna=aux;
                        if(matriz[r][aux]!=0){
                            cnt++;
                            aux++;
                                                }
                                                }
            aux++;
        }
    }


    int colunaNova=guardaColuna;
    while(matriz[guardaLinha-1][colunaNova]!=0){
        colunaNova++;
        cntauxDireita++;
    }

    int colunaNova1=guardaColuna;
    while(matriz[guardaLinha+1][colunaNova1]!=0){
        colunaNova1++;
        cntauxEsquerda++;
    }


    if(cntauxEsquerda<=cntauxDireita) cnt=cnt+cntauxEsquerda;
    else cnt=cnt+cntauxDireita;

    cout << cnt << endl;

    for (int w=0; w < N; w++) {
        delete matriz[w];
    }
    delete [] matriz ;
    }


    return 0;

}
