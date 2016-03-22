#include <iostream>

using namespace std;

int main() 
{
	int n, i;

	cin >> n;
	i = 0;
	cout << n << endl;
	while (n >= 100){
		n -= 100;
		i++;
	}
	cout << i << " nota(s) de R$ 100,00" << endl;
	i = 0;

	while (n >= 50){
		n -= 50;
		i++;
	}
	cout << i << " nota(s) de R$ 50,00" << endl;
	i = 0;

	while (n >= 20){
		n -= 20;
		i++;
	}
	cout << i << " nota(s) de R$ 20,00" << endl;
	i = 0;

	while (n >= 10){
		n -= 10;
		i++;
	}
	cout << i << " nota(s) de R$ 10,00" << endl;
	i = 0;

	while (n >= 5){
		n -= 5;
		i++;
	}
	cout << i << " nota(s) de R$ 5,00" << endl;
	i = 0;

	while (n >= 2){
		n -= 2;
		i++;
	}
	cout << i << " nota(s) de R$ 2,00" << endl;
	i = 0;

	while (n >= 1){
		n -= 1;
		i++;
	}
	cout << i << " nota(s) de R$ 1,00" << endl;
	i = 0;

	return 0;
}
 
