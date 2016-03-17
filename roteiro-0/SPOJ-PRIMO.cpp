#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    int n = 0, x, i;

    cin >> x;
    if (x % 2 == 0)
        cout << "nao" << endl;
    else
    {
        for (i = 3; i < sqrt(x); i++)
        {
            if (x % i == 0)
                n++;
            if (n > 1)
            {
                cout << "nao" << endl;
                return -1;
            }
        }
        cout << "sim" << endl;
    }
     
    return 0;
}
