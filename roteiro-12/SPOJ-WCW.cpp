#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
    int T, N, v[10001], exchanges;
    
    cin >> T;
    while (T--)
    {
        exchanges = 0;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> v[i];
            v[i] -= 1;
        }

        for (int i = 0; i < N; )
        {
            if (v[i] != i)
            {
                exchanges += 1;
                swap(v[v[i]], v[i]);
            }
            else
                i++;
        }
        cout << exchanges << "\n";
        
    }
    return 0;
}
