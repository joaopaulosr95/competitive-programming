#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    double A, R;

    cin >> R;
    A = 3.14159 * R * R;
    cout << "A=" << setprecision(4) << fixed << A << endl;
    return 0;
}
