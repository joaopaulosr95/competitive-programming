#include <iostream> // std::cout
#include <algorithm> // std::sort
#include <vector> // std::vector
#include <string>
#include <iterator>
#include <cstdio>
#include <math.h>
#include <iomanip>

using namespace std;

int N,M;
double V;

int main(){

  while(cin >> V >> N >> M){
      if(V==0 && N==0 && M==0) {
        break;
      }

      if(N%10000==M%10000) std::cout << std::fixed << std::setprecision(2) << V*3000 << std::endl;
      else if(N%1000==M%1000) std::cout << std::fixed << std::setprecision(2) << V*500 << std::endl;
      else if(N%100==M%100) std::cout << std::fixed << std::setprecision(2) << V*50 << std::endl;

      else {
        N=N%100;
        M=M%100;
          if(N%4!=0 && M%4!=0 && (N/4==M/4)) std::cout << std::fixed << std::setprecision(2) << V*16 << std::endl;
          else if ((N%4==0 && N/4==(M/4)+1) || (M%4==0 && M/4==(N/4)+1)) std::cout << std::fixed << std::setprecision(2) << V*16 << std::endl;
          else std::cout << std::fixed << std::setprecision(2) << V*0 << std::endl;

      }
  }
  return 0;
}
