#include <iostream>

using namespace std;

int main ()
{
    int n, x, sum = 0;

    cin >> n;
    while (n > 0)
    {
        cin >> x;
        sum += x;
        n--;
    }
    cout << sum << endl;
    return 0;
}
