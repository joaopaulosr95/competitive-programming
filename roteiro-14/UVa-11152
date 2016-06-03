#include <iostream> // std::cout
#include <algorithm> // std::sort
#include <vector> // std::vector
#include <string>
#include <iterator>
#include <cstdio>
#include <math.h>
#include <iomanip>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

double a,b,c,s,p,r,R,areaSF,areaViolet,areaRoses;

void impPrecision(double areaSF,double areaViolet,double areaRoses){
  std::cout << std::fixed << std::setprecision(4) << areaSF << " " << areaViolet << " " << areaRoses << std::endl;
}

int main(){

    while(cin>>a>>b>>c){
      p=(a+b+c)/2;
      s=sqrt(p*(p-a)*(p-b)*(p-c));
      R=a*b*c/4/s;
      r=sqrt((p-a)*(p-b)*(p-c)/p);
      areaSF=acos(-1)*R*R-s;
      areaRoses=acos(-1)*r*r;
      areaViolet=s-areaRoses;
      
      impPrecision(areaSF,areaViolet,areaRoses);
    }

    return 0;
}
