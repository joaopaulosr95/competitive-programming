#include <iostream>
#include <cstdlib>

using namespace std;

int eucl (int a, int b)
{
    return b == 0 ? a : eucl(b, a % b);
}

int main ()
{
    int N, x1, y1, x2, y2;

    cin >> N;
    while (N--)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        cout << 1 + eucl(abs(x2 - x1), abs(y2 - y1)) << "\n";
    }
    return 0;
}

