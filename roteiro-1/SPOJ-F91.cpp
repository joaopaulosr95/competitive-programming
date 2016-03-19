#include <iostream>

using namespace std;

int F91 (int N)
{
    if (N <= 100)
        return F91(F91(N+11));
    else if (N >= 101)
        return N-10;
}

int main ()
{
    int cases, N, x;
    
    while (cin >> N && N != 0)
        cout << "f91(" << N << ") = " << F91(N) << endl;
    return 0;
}
