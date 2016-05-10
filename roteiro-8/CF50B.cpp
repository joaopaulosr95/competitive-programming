#include <iostream>     
#include <string.h>

using namespace std;

int main(){

	string palavra;
	int cnt=0;
		cin >> palavra;
		int tam = palavra.size();
		char array[tam];
		strcpy(array, palavra.c_str());
		
		for(int i=0;i<tam;i++){
			for(int j=0;j<tam;j++){
				if(array[i]==array[j]) cnt++;
			}
		}
	cout << cnt << endl;

}
