#include <iostream>
using namespace std;


int main()
{
	int * largada, * chegada;
	int n,out,i,j;
	
	while( cin >> n)
	{
		if (n <2 || n>24) break;
		out = 0;
		largada = new int [n];
		chegada = new int [n];
		for(i=0; i<n; i++)
		{
			cin >> largada[i];
		}
		for(i=0; i<n; i++)
		{
			cin >> chegada[i];
		}
		for(i=0; i<n ;i++)
		{
			for( j=i; j<n;j++)
			{
				if(chegada[i] == largada [j])break;
				out++;
			}
			for(; j!=i; j--)
			{
				largada [j] = largada [j-1];
			}
		}
		cout << out <<endl;
		delete largada;
		delete chegada;
	}
	return 0;
}
