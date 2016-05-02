#include <iostream>
#include <cstdio>

using namespace std;


int main ()
{
    char ch;
    
    while (scanf("%c", &ch) != EOF)
    {
        if (ch >= 65 && ch <= 67)
            cout << "2";
        else if (ch >= 68 && ch <= 70)
            cout << "3";
        else if (ch >= 71 && ch <= 73)
            cout << "4";
        else if (ch >= 74 && ch <= 76)
            cout << "5";
        else if (ch >= 77 && ch <= 79)
            cout << "6";
        else if (ch >= 80 && ch <= 83)
            cout << "7";
        else if (ch >= 84 && ch <= 86)
            cout << "8";
        else if (ch >= 87 && ch <= 90)
            cout << "9";
        else
            cout << ch;
    }

    return 0;
}
