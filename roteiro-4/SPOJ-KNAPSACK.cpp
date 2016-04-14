#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int> > items; //<Weight,Value>

int solve (int size, int nitems)
{
    int knapsack[nitems+1][size+1], i, k;
    
    for (i = 0; i <= nitems; i++)
    {
        for (k = 0; k <= size; k++)
        {
            if (i == 0 || k == 0)
               knapsack[i][k] = 0;
            else if (items[i-1].first <= k)
                knapsack[i][k] = max(items[i-1].second + knapsack[i-1][k - items[i-1].first], 
                                knapsack[i-1][k]);
            else
                knapsack[i][k] = knapsack[i-1][k];
        }
    }
    
    return knapsack[nitems][size];
}

int main ()
{
    int size, nitems, i, W, V;

    cin >> size >> nitems;
    for (i = 0; i < nitems; i++)
    {
        cin >> W >> V;
        items.push_back(make_pair(W,V));
    }
    
    cout << solve(size, nitems) << endl;
}
