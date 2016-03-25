#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
  vector<int> input;
  int N, i, x, total, q, moves;

  while (cin >> N && N != -1)
  {
    total = 0;
    moves = 0;
    for (i = 0; i < N; i++)
    {
      cin >> x;
      input.push_back(x);
      total += x;
    }
    if (total % N)
      cout << "-1" << endl;
    else
    {
      for (i = 0; i < N; i++)
      {
        q = total / N;
        if (input[i] > q)
          moves += input[i] - q;
      }
      cout << moves << endl;
    }
    input.clear();
  }
  return 0;
}
