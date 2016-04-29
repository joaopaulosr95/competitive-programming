#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
    long int N, cards[10010], L1[10010], L2[10010];

    while (cin >> N)
    {
        for (long int i = 0; i < N; i++)
        {
            cin >> cards[i];
            L1[i] = L2[i] = 0;
        }
        
        for (long int i = 0; i < N; i++)
        {
            for (long int k = 0; k < N - i; k++)
            {
                if (i % 2)
                    L1[k] = max(L2[k + 1] + cards[k], 
                            L2[k] + cards[k + i]);
                else
                    L2[k] = min(L1[k + 1], L1[k]);
            }
        }
        cout << L1[0] << "\n";
    }
}
