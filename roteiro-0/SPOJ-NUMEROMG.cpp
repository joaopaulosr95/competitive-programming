#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;
const string __ALPHABET = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";


unsigned int base36decode (string input)
{
    int i;
    unsigned int base10 = 0;
    size_t baseIndex;

    for (i = 0; i < input.length(); i++)
    {
        input[i] = toupper(input[i]);
        baseIndex = __ALPHABET.find(input[i]);
        base10 += baseIndex * pow(36,input.length()- i);
    }
    return base10;
}

string base36encode (unsigned int base10)
{
    string base36;
    
    do
    {
        base36 = __ALPHABET[base10 % 36] + base36;
    } while(base10 /= 36);
    base36.pop_back();
    return base36;
}

int main ()
{
    string a, b;

    while (cin >> a >> b && ( a != "0" && b != "0" ))
        cout << base36encode(base36decode(a) + base36decode(b)) << endl;
    return 0;
}

