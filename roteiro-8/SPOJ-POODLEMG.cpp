#include <iostream>

using namespace std;

int main ()
{
    int N, P, count;

    while (cin >> N >> P && (N != 0 && P != 0))
    {
        if (N % P == 0)
            count = N / P;
        else
            count = (N / P) + 1;
        
        if (count <= 6)
            cout << "Poodle\n";
        else 
        {
            if (count >= 20)
                count = 14;
            else
                count -= 6;

            cout << "P";
            for (int i = 0; i < count; i++)
                cout << "o";
            cout << "oodle\n";
        }
    }
    
    return 0;
}
