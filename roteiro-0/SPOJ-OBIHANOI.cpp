#include <iostream>
#include <cmath>

using namespace std;

/*
void hanoi (long long int n, long long int src, long long int dst, long long int tmp, long long int *moves)
{
    if (n > 0)
    {
        hanoi(n-1, src, tmp, dst, moves);
        hanoi(n-1, tmp, dst, src, moves);
        (*moves)++; 
    }
}
*/

int main ()
{
    long long int n = -1, test = 1;
    unsigned long long int moves = 0;
    
    while (1)
    {
        cin >> n;
        if (n == 0) break;
       
        // hanoi(n, 1, 3, 2, &moves);
        cout << "Teste " << test++ << endl;
        
        //Solucao rapida
        moves = pow(2,n);
        cout << moves-1 << endl;
        
        moves = 0;
    }
    return 0;
}
 
