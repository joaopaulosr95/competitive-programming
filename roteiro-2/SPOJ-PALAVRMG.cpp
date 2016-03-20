#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main ()
{
    string input;
    int words, i, j;
    bool ordered = true;

    cin >> words;
    while (words)
    {
        cin >> input;
        for (i = 0; i < input.size(); i++)
            input[i] = tolower(input[i]);

        for (i = 0; i < input.size() - 1; ++i)
        {
            if (input[i] >= input[i+1])
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
