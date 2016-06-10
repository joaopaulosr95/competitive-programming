#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c;

    while(cin >> a >> c >> b) {
        if((12.0 / c) >= (sqrt(144 + pow(a,2))/b))
            cout << "S\n";
        else
            cout << "N\n";
    }
    return 0;
}
