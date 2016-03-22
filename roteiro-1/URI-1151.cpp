#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    int n, i, sum = 1, fib[2] = {0,1}, r;

    cin >> n;
    if (n == 0)
        cout << "0" << endl;
    else if (n == 1)
        cout << "1" << endl;
    else
        cout << "0 1 ";
        for (i = 1; i < n-1; i++)
        {
            r = fib[0] + fib[1];
            fib[0] = fib[1];
            fib[1] = r;
            if (i < n-2)
                cout << r << " ";
            else
                cout << r << endl;
        }
}
 
