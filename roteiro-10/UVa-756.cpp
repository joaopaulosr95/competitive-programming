#include <iostream>

/* 
 * a |  m | 	  M       |	  	M % m	  |		inv M   | a *(M % m) * (inv M)
 * --|----|---------------|---------------|-------------|--------------------
 * p | 23 | 28 * 33 = 924 | 924 % 23 =  4 | inv 4  = 6  | p * 924 *  6
 * e | 28 | 23 * 33 = 759 | 759 % 28 =  3 | inv 3  = 19 | e * 759 * 19
 * i | 33 | 23 * 28 = 644 | 644 % 33 = 17 | inv 17 = 2  | i * 644 *  2
 * 
 * 23 * 28 * 33 = 21252
 * Solution: x = [(p*924*6) + (e*759*19) + (i*644*2)] (mod 21252)
 * Especific solution: (x - d + 21252) % 21252
 */

using namespace std;

int main ()
{
	int p, e, i, d, testN, x;
	
	testN = 0;
	while ((cin >> p >> e >> i >> d) && 
		(p != -1 && e != -1 && i != -1 && d!= -1))
	{
		x = (p * 924 * 6) + (e * 759 * 19) + (i * 644 * 2);
		x = (x - d + 21252);
		x %= 21252;

		if (x == d)
			x += 21252;

		cout << "Case " << ++testN;
		cout << ": the next triple peak occurs in " << x << " days.\n";
	}
	return 0;
}
