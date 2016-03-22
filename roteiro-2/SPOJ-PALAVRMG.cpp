#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main ()
{
    string input;
    int words, i, j;
    bool ordered;

    cin >> words;
    while (words)
    {
        ordered = true;
        cin >> input;

        for (i = 0; i < input.size() - 1; ++i)
        {
            if (tolower(input[i]) >= tolower(input[i+1]))
            {
                ordered = false;
                break;
            }
        }
        if (ordered == true)
            cout << input << ": O" << endl;
        else
            cout << input << ": N" << endl;
        words--;
    }
    return 0;
}
