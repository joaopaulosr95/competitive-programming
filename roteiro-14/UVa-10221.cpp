#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;
const double PI = 2 * acos(0.0);

int main()
{    
    int S, A;
    string type;

    double ang, arcDistance, chordDistance, earthDistance = 6440, R;

    while(cin >> S >> A >> type)
    {
        if(type.compare("deg") == 0) 
            ang = A * PI / 180;

        else if(type.compare("min") == 0)
            ang = A * PI / 10800;

        ang = min(ang, 2 * PI - ang);

        R = earthDistance + S;

        chordDistance = R * ang;
        arcDistance = 2 * R * sin(ang / 2);

        cout << fixed << setprecision(6) << chordDistance << " " << arcDistance << "\n";
    }

    return 0;
}
