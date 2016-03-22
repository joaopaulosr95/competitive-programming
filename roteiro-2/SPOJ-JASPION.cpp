#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main ()
{
    map<string, string> translate;
    string jap, ptbr, input, output;
    size_t space;
    int T, M, N, i;

    cin >> T;
    while (T > 0)
    {
        cin >> M >> N;
        cin.ignore(1);
        for (i = 0; i < M; i++)
        {
            getline(cin, jap);
            getline(cin, ptbr);
            translate.insert(pair<string, string>(jap,ptbr));
            //cout << jap << " : " << ptbr << endl;
            jap.clear();
            ptbr.clear();
        }
        for (i = 0; i < N; i++)
        {
            getline(cin,input);
            istringstream iss(input);
            while (iss >> jap)
            {
                map<string, string>::iterator found = translate.find(jap);
                if (found != translate.end())
                    output = output + translate[jap] + " ";
                else
                    output = output + jap + " ";
            }
            cout << output << endl;
            output.clear();
            input.clear();
            jap.clear();
        }
        T -= 1;
        translate.clear();
    }
    return 0;
}
 
