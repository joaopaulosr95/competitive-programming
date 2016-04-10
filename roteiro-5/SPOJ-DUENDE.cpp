#include <iostream>

using namespace std;


int matX[] = {-1,  0, 0, 1};
int matY[] = { 0, -1, 1, 0};

int matrizCaverna[11][11];
int N, M;



bool garanteIf(int larg, int comp)
{
    return larg >= 0 && larg < N && comp >= 0 && comp < M;
}


int search(int larg, int comp)
{
    int dBeg = 0;
	int dEnd = 0;
	int matDis = 0;
    int width[1000], lenght[1000], camOrig[1000];
    
    width[dEnd] = larg;
    lenght[dEnd] = comp;
    camOrig[dEnd] = 0;
    dEnd++;
    
    while (dBeg != dEnd){
	
        larg = width[dBeg];
        comp = lenght[dBeg];
        matDis = camOrig[dBeg];
        dBeg++;
        
        if (matrizCaverna[larg][comp] == 0) return matDis;
        else if (matrizCaverna[larg][comp] == 1)
        {
            for (int i = 0; i < 4; i++)
            {
                if (garanteIf(larg + matX[i], comp + matY[i]) && matrizCaverna[larg + matX[i]][comp + matY[i]] < 2){
				
                    width[dEnd] = larg + matX[i];
                    lenght[dEnd] = comp + matY[i];
                    camOrig[dEnd] = matDis + 1;
                    dEnd++;
                }
					}
          }
         
        matrizCaverna[larg][comp] = 2;
    }
    
    return -1;
}

int main(){

    int aux1, aux2;
	
    cin >> N >> M;
	
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++){
		
            cin >> matrizCaverna[i][j];
            if (matrizCaverna[i][j] == 3){
			
                aux1 = i;
                aux2 = j;
                matrizCaverna[i][j] = 1;
            }
				}
		}

    cout << search(aux1, aux2) << endl;
    return 0;
}


	
