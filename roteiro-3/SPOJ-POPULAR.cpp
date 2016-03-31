#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
    int n, candidate, v;
    vector<int> votes;

    while (cin >> n && n != 0)
    {
        votes.resize(n);
        fill(votes.begin(), votes.end(), 0);
        
        for (int i = 0; i < n; i++)
        {
            for (candidate = 0; candidate < n; candidate++)
            {
                cin >> v;
                votes[candidate] = votes[candidate] + v;
            }
            
        }
        sort(votes.rbegin(), votes.rend());
        cout << votes[0] << endl;
    }
}
