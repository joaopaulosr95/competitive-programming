#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <string>
#include <iterator>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){


  double A,B,AB;
  double x1,y1,x2,y2,angCmD,angEnF;
	double ca,am,cam;

    while(cin>>x1>>y1>>x2>>y2>>angCmD>>angEnF){
      B=pow(x1-x2,2);
      A=pow(y1-y2,2);
       AB=sqrt(B+A);
		  am=(1/tan(angCmD*acos(-1)/180));
	  	ca=(1/tan(angEnF*acos(-1)/180));
      cam=AB*(am+ca);

       std::cout << std::fixed << std::setprecision(3) << cam << std::endl;
    }
}
