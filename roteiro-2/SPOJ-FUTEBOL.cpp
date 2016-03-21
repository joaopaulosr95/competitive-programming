#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct team {
    char name[15];
    int points;
    int games;
    int goals_pro;
    int goals_con;
    int goals_bal;
    double percentage;
};

int main ()
{
    map<int,struct team> soccer;
    int T, G, i;
    char x;

    while (cin >> T >> G && (T != 0 && G != 0))
    {
        
    }
    return 0;
}
