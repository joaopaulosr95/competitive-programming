#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <string>
#include <iterator>

using namespace std;

int matx[] = {-1, 0, 0, 1};
int maty[] = {0, -1, 1, 0};
int N, M,largura,comprimento;
int matrizCaverna[11][11];


int search(int l, int c)
{
    
    int iniciomat = 0;
    int finalmat = 0;
    int larguras[100], comprimentos[100], origem[100];
    int distancia = 0;

    larguras[finalmat]=l;
    comprimentos[finalmat]=c;
    origem[finalmat]=0;
    finalmat++;

    while (iniciomat!=finalmat){
            
        l=larguras[iniciomat];
        c=comprimentos[iniciomat];
        distancia=origem[iniciomat];
        iniciomat++;

        if (matrizCaverna[l][c] == 0) return distancia;
        else if (matrizCaverna[l][c] == 1)
        {
            for (int i = 0; i < 4; i++){
                int aux1=l+mx[i];
                int aux2=c+my[i];
                if (matrizCaverna[aux1][aux2]<2 && aux1 >= 0 && aux1 < N && aux2 >= 0 && aux2< M){
                    
                    
                    larguras[finalmat]=aux1;
                    comprimentos[finalmat]=aux2;
                    origem[finalmat]=distancia++;
                    finalmat++;
                }

            }
            }

        matrizCaverna[l][c] = 2;
                }
    
        return -1;
        
                }

int main()
{
    int i, j,aux3,aux4;
    
    cin >> N >> M;
    
    for (i=0;i < N;i++){
            
        for (j=0;j<M;j++;){
            
            cin >> matrizCaverna[i][j];
            if (matrizCaverna[i][j] == 3){
                aux3=i;
                aax4=j;
                matrizCaverna[i][j]=1;
    
            }
        }
        }

            cout << search(x,y) << endl;
            
            
        return 0;
}


