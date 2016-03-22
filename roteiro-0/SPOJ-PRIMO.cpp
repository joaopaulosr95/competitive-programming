#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    int n = 0, x, isprime = 1, i = 2;

    cin >> x;
    if (x < 0)
        x = -x;
    if (x < 2)
        cout << "sim" << endl;
    else
    {
        for (i = 2; i <= sqrt(x); i++)
        {
            if (x % i == 0)
            {
                isprime = 0;
                break;
            }
        }
    
        if (isprime == 1)
            cout << "sim" << endl;
        else
            cout << "nao" << endl;
    }
    return 0;
}
 
