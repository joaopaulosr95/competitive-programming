#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <string>
#include <iterator>
#include <cstdio>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){
	int N,M;
	double V,aux;
	while((cin >> V >> N >> M) && (!V==0 && !N==0 && !M==0)){
    if(N%10000==M%10000) {aux=3000*V;cout << "if 1" << endl;}
    else if(N%1000==M%1000){ aux=500*V;cout <<"if 2" << endl;}
    else if(N%100==M%100) {aux=50*V; cout << "if 3" << endl;}
    else {
     N=N%100;
     M=M%100;

     if(N%4==M%4){
            cout << "if 4" << endl;
        if(N%4!=0 && (N/4==M/4)) aux=16*V;
        else if(N%4==0 && ((N/4)+1==(M/4) || (N/4)==(M/4)+1)) aux=16*V;
        else aux=0;
     }

    }




	std::cout << std::fixed << std::setprecision(2) << aux << std::endl;

	}

	return 0;
}
