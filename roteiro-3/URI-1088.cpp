#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int main ()
{
  vector<int> input;
  int n, i, moves, x;
  
  while (cin >> n && n != 0)
  {
    moves = 0;
    for (i = 0; i < n; i++)
    {
      cin >> x;
      x -= 1; //Para compensar os indices que começam em 0
      input.push_back(x);
    }
    for (i = 0; i < n;)
    {
      if (input[i] != i)
      {
        moves += (2 * (input[i] - i) - 1);
        iter_swap(input.begin()+i, input.begin()+input[i]);
      }
      else
        i++;
    }
    if (moves % 2 == 0)
      cout << "Carlos" << endl;
    else
      cout << "Marcelo" << endl;
    input.clear();
  }
  return 0;
}
