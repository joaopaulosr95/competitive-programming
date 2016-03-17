#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

const string BASE = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int decode (string b36)
{
    string input = b36.toupper().reverse();
    long b10 = 0;
    

    return b10;
}

string encode (long b10)
{
    stack<char> b64();
    string result;

    while (b10 != 0)
    {
        b64.Push(BASE[b10 % 36];
        b10 =/ 36;
    }   
    result = b64.ToArray();
    return result;
}

void sum (string a36, b36)
{
    
}

int main ()
{
    string a36, b36, sum36;
    long a10, b10, sum36;

    while (cin << a36 << b36 && ( a36 != "0" && b36 != "0" ))
    {
        /*
         *  Transforma base36 para base10
         *  Soma
         *  Converte base10 para base36
         */
        sum(a36,b36);
    }
    return 0;
}
