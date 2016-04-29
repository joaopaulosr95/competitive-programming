#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

bool compare(pair<char,int> a, pair<char, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main()
{
    int N;
    string input;
    pair<char,int> alphabet[26];

    for (int i = 0; i < 26; i++)
        alphabet[i] = make_pair('A' + i, 0);
        
    cin >> N;
    while (N--)
    {
        getline(cin, input);
        for (int i = 0; i < input.length(); i++)
        {
            if (toupper(input[i]) >= 'A' && toupper(input[i]) <= 'Z')
                alphabet[toupper(input[i]) - 'A'].second += 1;
            //else if (idx >= 97 && idx <= 122)
            //    alphabet[idx - 97].second += 1;
        }
        sort(alphabet, alphabet + 26, compare);
    }
    for (int i = 0; i < 26; i++)
    {   
        if (alphabet[i].second == 0)
            break;
        cout << alphabet[i].first << " " << alphabet[i].second << "\n";
    }

    return 0;
}
