#include <iostream>

using namespace std;

int main ()
{
    int N, C, V, nMAX;

    while (cin >> N && N != 0)
    { 
        nMAX = 0;

        for (int i = 0; i < N; i++)
        {
            cin >> C >> V;
            nMAX += V / 2;
        }

        cout << nMAX / 2 << "\n";
    }

    return 0;
}
