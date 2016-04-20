#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cctype>

using namespace std;

const int MAX = 100;
vector<int> fibonacci {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 
    233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 
    46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 
    2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 
    63245986, 102334155, 165580141, 267914296, 433494437, 701408733, 
    1134903170, 1836311903};

int main ()
{
    int T, N, code, pos, max;
    string cipher;
    map<int,int> fibmap;

    cin >> T;
    while(T--)
    {
        cin >> N;
        max = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> code;
            vector<int>::iterator it = find(fibonacci.begin(), 
                    fibonacci.end(), code);
            pos = distance(fibonacci.begin(), it);
            fibmap.insert(make_pair(code, pos));
            //cout << "Code: " << code << " Pos: " << pos << endl;
            if (max < code)
                max = code;
        }

        cin.ignore(1);
        getline(cin, cipher);
        //cout << cipher << "\n";

        for (vector<int>::iterator it = fibonacci.begin(); 
                it != fibonacci.end() && *it <= max; it++)
        {
            map<int,int>::iterator mit = fibmap.find(*it);
            if (mit != fibmap.end() && isupper(cipher[mit->second]))
                cout << cipher[mit->second];
            else
                cout << ' ';
        }
        cout << "\n";
        fibmap.clear();
        cipher.clear();
    }
    return 0;
}
