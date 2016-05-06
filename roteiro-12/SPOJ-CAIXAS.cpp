#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <string>
#include <iterator>

using namespace std;

int main(){

    int N,P;
    int tam,cnt=0;
    int cntauxEsquerda=0,cntauxDireita=0;
    int **matriz;
    int guardaLinha,guardaColuna;
    cin >> N >> P;
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

    int aux=0;
    for(int r=0;r<P;r++){
        while(matriz[r][aux]!=0){
            if(matriz[r][aux]==1){
                guardaLinha=r;
                guardaColuna=aux;
                while(matriz[r][aux]!=0){
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

    if(cntauxEsquerda<=cntauxDireita) cnt=cntauxEsquerda;
    else cnt=cntauxDireita;

    cout << cnt << endl;

    for (int w = 0; w < P; w++) { 
        delete matriz[w];      
    }


    return 0;

}
