#include <iostream>
#include <cctype>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if(n == 0) 
    	return false;
    if(n != 2)
        for(int i = 2; i <= sqrt(n); i++)
            if(n % i == 0) 
            	return false;
    return true;
}

int main() {
    int sum;
    string input;

    while(cin >> input) {
        sum = 0;
        for( int i=0; i<input.size(); i++ )
            if(input[i] >= 65 && input[i] <= 90)
                sum += input[i] - int('A') + 27;
            else if (input[i] >= 9 && input[i] <= 122)
                sum += input[i] - int('a') + 1;

        if(isPrime(sum))
        	cout << "It is a prime word.\n";
       	else
       		cout << "It is not a prime word.\n";
    }

    return 0;
}
