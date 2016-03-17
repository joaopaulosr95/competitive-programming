#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    int n, i, sum = 1, fib[2] = {0,1}, r;

    cin >> n;
    if (n == 0)
        cout << "The Fibonacci number for 0 is 0" << endl;
    else if (n == 1)
        cout << "The Fibonacci number for 1 is 1" << endl;
    else
    {
        for (i = 0; i < n-1; i++)
        {
            r = fib[0] + fib[1];
            fib[0] = fib[1];
            fib[1] = r;
        }
        cout << "The Fibonacci number for " << n << " is " << r << endl; 
    }
}
