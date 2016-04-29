#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <string>
#include <iterator>

using namespace std;

void contaMoedas(vector<int> moedas, int m, int n){
int aux;
std::vector<int>::iterator it=moedas.begin();
int valorOriginal = m;
for(int z=0;((m/(*it))-z)>0;z++){
	int j=1;
	int total=0;
	std::vector<int>::iterator atual=moedas.begin()+z;
	int primeirovalor = m/(*atual);
	int flag=0;
while(j!=n){
	
	if(primeirovalor!=0 &&  flag==0) {
		primeirovalor = primeirovalor-z;
		total = total + primeirovalor;
		aux=m%(primeirovalor*(*atual));
		m=aux;
	}
	else if(flag!=1 && flag!=0) break;
std::vector<int>::iterator it=moedas.begin()+(j);
total = total + (m/(*it));
aux=(m%(*it));
	
//cout << *it << endl;
 //total= total + (m/(*it))-z;
 //cout << total << endl;
 //aux=(m%(*it))+((*it)*z);
//cout << aux << endl;

 if(aux==0){ //m é coberto só pela moeda
 	cout << "if1" << endl;
	 cout << total << endl;
	 break;
 }
 else if(aux<m){
	 cout << "if2" << endl;
	 m=aux;
	 j++;
	 flag=1;
 }
 else if(aux==m){
 	cout << "if3" << endl;
	 j++;
	 flag=1;
 }
if (j==n){
cout << "Impossivel " << endl; 
m=valorOriginal;
}
////cout << "Isso é o numero de cedulas" << (m/(*it)) << endl;
}
}
}


int main(){
	int m, n; //m é o preço, n é o numero de moedas
	int moedaX;
	//while(cin >> m >> n && m!=0){
	//	cin >> n;
	  cin >> m >> n;
		vector<int> moedas;
		int i=0;
		while(i<n){
		cin >> moedaX;
		moedas.push_back(moedaX);
		i++;
		}

std::sort(moedas.begin(), moedas.end(), std::greater<int>());
//m=0; se m%*it der *it
contaMoedas(moedas,m,n);

/*



		int j=0;
		int aux;
		while(1){
std::vector<int>::iterator it=moedas.begin()+j;
		 total= total + m/(*it);
		 aux=m%(*it);

		 if(aux==0){ //m é coberto só pela moeda
			 cout << total << endl;
			 break;
		 }
		 else if(aux<m){
			 m=aux;
			 j++;
		 }
		 else if(aux==m){
			 j++;
		 }

if (j==n){
	cout << "Impossivel" << endl;
	break;
}
}
*/
		 /*if(flag==2){
			 cout << total << endl;
			 break;
		}*/

 //cout << total << endl;
	moedas.erase(moedas.begin(),moedas.end());
	return 0;
}
