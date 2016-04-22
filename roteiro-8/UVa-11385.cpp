#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cctype>

using namespace std;

const int fibonacci[45] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144,
    233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657,
    46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269,
    2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169,
    63245986, 102334155, 165580141, 267914296, 433494437, 701408733,
    1134903170, 1836311903};

map<int,char> createMap()
{
    map<int,char> m;
    for (int i = 0; i < 45; i++)
        m[fibonacci[i]] = ' ';
    return m;
}

int main ()
{
    int T, N, code, pos, max;
    map<int,char> fibmap;
    vector<int> fibcodes;
    string cipher;

    cin >> T;
    while(T--)
    {
        cin >> N;
        max = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> code;
            fibcodes.push_back(code);
            if (max < code)
                max = code;
        }

        cin.ignore(1);
        getline(cin, cipher);
        //cout << cipher << "\n";

        fibmap = createMap();
        for (int i = 0, j = 0, k = 0; i < cipher.length() &&
            j < fibcodes.size(); i++)
        {
            if (isupper(cipher[i]))
            {
                fibmap[fibcodes[i-k]] = cipher[i];
                j++;
            }
            else
                k++;
        }

        for (int i = 0; fibonacci[i] <= max; i++)
            cout << fibmap[fibonacci[i]];
        cout << "\n";

        cipher.clear();
        map<int,char>().swap(fibmap);
        vector<int>().swap(fibcodes);
    }
    return 0;
}
