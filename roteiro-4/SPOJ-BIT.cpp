#include <iostream>

using namespace std;

int main ()
{
    int v, testN, i, cells[4] = {50,10,5,1};

    testN = 1;
    while (cin >> v && v != 0)
    {
        cout << "Teste " << testN++ << endl;
        for (i = 0; i < 4; i++)
        {
            cout << v/cells[i];
            if (i <= 3)
               cout << " ";
            v = v % cells[i];
        }
        cout << endl << endl;
    }
    return 0;
}
