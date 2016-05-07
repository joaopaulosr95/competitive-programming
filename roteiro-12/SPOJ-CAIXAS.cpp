#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <string>
#include <iterator>

using namespace std;

int main(){

    int N,P;
    int matriz[1000][1000];
    int guardaLinha,guardaColuna,tam;
    while(cin >> N >> P && N!=0 && P!=0){
    int cnt=0;
    int cntauxEsquerda=0,cntauxDireita=0;
  // matriz= new int *[P];

    for(int i=0;i<1000;i++){

        for(int j=0;j<1000;j++){

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
                    aux++;
                    //cout << "Linha é " << guardaLinha << "e Coluna é " << guardaColuna << endl;
                        if(matriz[r][aux]!=0){
                            cnt++;
                            aux++;
                                                }
                                                }
            aux++;
        }
    }


   // cout << "CNT até aqui é " << cnt << endl;


    int colunaNova=guardaColuna;
    if(guardaLinha!=0){
    while(matriz[guardaLinha-1][colunaNova]!=0){
        colunaNova++;
        cntauxDireita++;
    }}
    else cntauxDireita=0;

    int colunaNova1=guardaColuna;
    if(guardaLinha!=P){
    while(matriz[guardaLinha+1][colunaNova1]!=0){
        colunaNova1++;
        cntauxEsquerda++;
    }}
    else cntauxEsquerda=0;


    if(cntauxEsquerda<=cntauxDireita) cnt=cnt+cntauxEsquerda;
    else cnt=cnt+cntauxDireita;

    cout << cnt << endl;

  /*  for (int w=0; w < P; w++) {
        for (int y=0; y < N; y++) {
        delete matriz[w][y];
    }*/
      

    //for(int u=0;u<P;u++){
    //delete [] matriz ;
  //  } 

    


    }

    return 0;

}
