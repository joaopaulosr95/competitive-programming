#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <string>
#include <string.h>
#include <cstdio>
#include <math.h>

using namespace std;

int tam;
long long total=0;
std::string str;

int main(){
    cin >> str;
    tam = str.length()+10000;
    std::vector<long> cnt(tam);

    for(unsigned int i=0;i<str.length();i++) cnt[str[i]]++;
    for(int i=0;i<tam;i++) total=total+(pow(cnt[i],2));

    cout << total << endl;

    return 0;
}
