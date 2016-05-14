#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <functional>

using namespace std;

const int MAX = 100050;

int main ()
{
	int N, neighboor[MAX], time, end, aval;

	while (cin >> N && N != 0)
	{
		//neighboor.resize(N);
		//memset(neighboor, 0, MAX);

		for (int i = 0; i < N; i++)
			cin >> neighboor[i];

		sort(neighboor, neighboor + N, greater<int>());

		time = end = 0;
		aval = 1;

		for (int i = 0, nend; i < N;)
		{
			if (aval == 0)
			{
				time = -1; 
				break;
			}

			i += aval;            
			if (i - 1 > N - 1)
				nend = N - 1;
			else
				nend = i - 1;

			aval = 0;
			for (int k = nend; k >= end; k--)
			{
				if (--neighboor[k] >= 0)
				{
					++aval;
					nend = k - 1;
				}
			}
			time += 1;
			end = nend;
		}
		cout << time << "\n";
		//neighboor.clear();
	}
	return 0;
}
