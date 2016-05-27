#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <string>
#include <iterator>
#include <cstdio>
#include <math.h>

using namespace std;

int main(){
	long long int x1,y1;
	long long int x2,y2;
	long long int x3,y3;

	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	long long int cord2 = ((x2-x1)*(y3-y2));
	long long int cord1 = ((x3-x2)*(y2-y1));


	if((cord2-cord1)<0) cout << "RIGHT" << endl;
	else if ((cord2-cord1)>0) cout << "LEFT" << endl;
	else if ((cord2-cord1)==0) cout << "TOWARDS" << endl;


	return 0;

}
