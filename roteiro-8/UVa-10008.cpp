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
    char ch;
    pair<char,int> alphabet[26];

    for (int i = 0; i < 26; i++)
        alphabet[i] = make_pair('A' + i, 0);
        
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        while (cin >> ch && ch != '\n')
        {
            if (toupper(ch) >= 'A' && toupper(ch) <= 'Z')
                alphabet[toupper(ch) - 'A'].second += 1;
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
