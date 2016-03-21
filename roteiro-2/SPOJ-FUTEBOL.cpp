#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <map>

using namespace std;

// tolower() applied to whole string
string strToLow (const string &a)
{
    int i;
    string low = a;

    for (i = 0; i < a.size(); i++)
        low[i] = tolower(a[i]);

    return low;
}

struct team
{
    string name;
    int points;
    double points_perc;
    int games;
    int goals_pro;
    int goals_con;
    int goals_bal;

    team (string N)
    {
        name = N;
        points = 0;
        points_perc = 0;
        games = 0;
        goals_pro = 0;
        goals_con = 0;
        goals_bal = 0;
    }

    void addGame (int GP, int GC)
    {
        games = games + 1;
        goals_pro = goals_pro + GP;
        goals_con = goals_con + GC;
        goals_bal = goals_pro - goals_con;
        if (GP > GC)
            points = points + 3;
        else if (GP == GC)
            points = points + 1;
    }

    void setPP()
    {
        if (games > 0)
            points_perc = 1.0 * ((100 * points) / (3 * games));
        else
            points_perc = -1.0;
    }

    void printInfo(int pos)
    {
        if (pos == -1)
            cout << "    ";
        else
            cout << setw(2) << pos << "."; 

        cout << setw(16) << name;
        cout << setw(4) << points << games << goals_pro << goals_con << goals_bal;
        if (games > 0)
            cout << setw(7) << fixed << setprecision(2) << points_perc;
        else
            cout << "    N/A";

        cout << endl;
    }

    //Define the 'equal-equal' operator to handle the struct variables
    bool operator == (const struct team &T)
    {
        return T.points == this->points && 
            T.goals_pro == this->goals_pro &&
            T.goals_bal == this->goals_bal && 
            strToLow(T.name) == strToLow(this->name);
    }
};

// Compare function to help std::sort
bool compare (const struct team& T1, const team& T2)
{
    if (T1.points != T2.points)
        return T1.points < T2.points;
    else if (T1.goals_bal != T2.goals_bal)
        return T1.goals_bal < T2.goals_bal;    
    else if (T1.goals_pro != T2.goals_pro)
        return T1.goals_pro < T2.goals_pro;
    else
    {
        string a = strToLow(T1.name),
                b = strToLow(T2.name);
        return a > b;
    }
}

// Main program
int main ()
{
    map<string,int> teams;
    vector<struct team> teamsInfo(28);
    int T, G, i, T1g, T2g;
    string T1name, T2name;
    char c;
    
    while (cin >> T >> G && (T != 0 && G != 0))
    {
        for (i = 0; i < T; i++)
        {
            cin >> T1name;
            struct team T1(T1name);
            teams[T1name] = i;
            teamsInfo.push_back(T1);
        }
        for (i = 0; i < G; i++)
        {
            cin >> T1name >> T1g >> c >> T2g >> T2name;
            teamsInfo[teams[T1name]].addGame(T1g, T2g);
            teamsInfo[teams[T2name]].addGame(T2g, T1g);    
        }
        sort(teamsInfo.begin(), teamsInfo.end(), compare);
        for (i = 0; i < T; i++)
        {
            if (i > 0 && teamsInfo[i] == teamsInfo[i+1])
                teamsInfo[i].printInfo(-1);
            else
                teamsInfo[i].printInfo(i+1);
        }
        cout << endl;
        
        teams.clear();
        teamsInfo.clear();
    }
    return 0;
}
