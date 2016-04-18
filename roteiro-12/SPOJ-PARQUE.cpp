#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

const int MAX = 110;

int main ()
{
    cout.sync_with_stdio(false);
    string seq1, seq2;
    int testN, i, j, lcs[MAX][MAX], lenseq1, lenseq2;
    stack<char> sol;

    testN = 0;
    while (cin >> seq1 >> seq2 && seq1 != "#")
    {
        lenseq1 = seq1.length();
        lenseq2 = seq2.length();

        for (i = 0; i <= lenseq1; i++)
            lcs[i][0] = 0;
        for (i = 0; i <= lenseq2; i++)
            lcs[0][i] = 0;

        //--------------- LCS ---------------//
        for (i = 1; i <= lenseq1; i++)
        {
            for (j = 1; j <= lenseq2; j++)
            {
                if (seq1[i-1] == seq2[j-1])
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                else
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
        //-----------------------------------//

        i = lenseq1;
        j = lenseq2;
        while (i && j){
            if (seq1[i-1] == seq2[j-1])
            {
                sol.push(seq1[--i]);
                j--;
            }
            else
            {
                if (lcs[i][j] == lcs[i-1][j])
                    sol.push(seq1[--i]);
                else
                    sol.push(seq2[--j]);
            }
        }

        while (1)
        {
            if (i)
                sol.push(seq1[--i]);
            else if (j)
                sol.push(seq2[--j]);
            else
                break;
        }

        cout << "Teste " << ++testN << "\n";
        while (!sol.empty())
        {
            cout << sol.top();
            sol.pop();
        }
        cout << "\n\n";
    }
    return 0;
}
