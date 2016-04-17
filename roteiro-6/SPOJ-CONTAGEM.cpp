#include <cstdio>
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <string>
#include <iterator>
#include <cstring>


int main() {
    
    char palavra[61];
    unsigned long long int result;

	int num = 0;

    while (scanf("%s", palavra) != EOF) {

		result=0;

        int siz3=strlen(palavra);

        for (int i=0; i<siz3; i++) {

            result=result*2+palavra[i]-'a';

	   }

        printf("Palavra %d\n", ++num);
        printf("%llu\n\n", result);
    }

    return 0;
}
