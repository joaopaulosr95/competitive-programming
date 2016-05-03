#include <iostream>

using namespace std;

int main ()
{
    long long N;
    while (cin >> N && N >= 0)
        cout << (((N * N) + N ) / 2) + 1 << "\n";
    return 0;
}
