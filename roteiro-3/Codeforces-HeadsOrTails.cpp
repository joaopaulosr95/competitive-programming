#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <string>
#include <iterator>

using namespace std;

int main()
{
    int x,y,a,b; // x e y vezes que joga. a e b, minimo de cara

    cin >> x >> y >> a >> b;

    int i,j,minimo;
    int totalpossivel=0;

    for(i=a;i<=x;i++){
        minimo=std::min(y,i-1);

    	for(j= b;j<=std::min(i-1,minimo);j++){
        	totalpossivel++;
    	}
    }
    cout << totalpossivel << endl;

    for(i=a;i<=x;i++){
        minimo=std::min(y,i-1);

    	for(j= b;j<=minimo;j++){
        	cout << i << " " << j << endl;
    	}
    }

    return 0;
}
