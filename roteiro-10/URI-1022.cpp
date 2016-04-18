#include <iostream>

using namespace std;

int gcd (int a, int b)
{
    return b == 0 ? a : gcd (b, a % b);
}

int main () 
{
    int N, a, b;

    cin >> N;
    while (N--)
    {
        cin >> a >> b;
        if (a <  b)
            a,b = b,a;
        cout << gcd (a,b) << "\n";
    }

    return 0;
}
