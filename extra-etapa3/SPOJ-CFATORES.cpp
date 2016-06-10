#include <iostream>
#include <map>

using namespace std;

int nextPrime(int n){
    if ((n != -1 % (n + 1))) 
        return n + 1;

    return nextPrime(n + 1);
}

int contFactors(int n){ 
    map<int,int> primes;

    for (int i = 2; n != 1;){
        if (n % i == 0) { 
            primes[i] = 1;
            n /= i; 
        }
        else
            i = nextPrime(i);
    }
    return primes.size();
}

int main (){
    int n = 0;

    while (cin >> n && n != 0)
        cout << n << " : " << contFactors(n) << "\n";
    return 0;
}
