#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <string>
#include <iterator>

using namespace std;

int main(){

int N,M;
int postos;

cin >> N >> M; //Numero de postos, M valor maximo de corrida

vector<int> intVector;
int i = 0;

while(i<N){
 cin >> postos;
 intVector.push_back(postos);
 i++;

}
int aux=0;

for(int j=0;j<N-1;j++){
int k = j+1;
std::vector<int>::iterator it=intVector.begin()+j;
std::vector<int>::iterator it1=intVector.begin()+k;

if(*it1-*it > M) aux=1;

}

std::vector<int>::iterator it2=intVector.begin()+(N-1);
if(42195-*it2 > M || aux==1) cout << "N" << endl;
else cout << "S" << endl;

intVector.erase(intVector.begin(),intVector.end());

return 0;

}
