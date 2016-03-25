#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <string>
#include <iterator>

using namespace std;

int main()
{
    int n,aux;
    float input,resultado;
    int i=0;
    cin >> n;
    vector<float> floatVector;//vetor pra lista de numeros
    while(i!=n){
            cin >> input;
            floatVector.push_back(input);
            i++;
    }

        std::sort (floatVector.begin(), floatVector.end());
        aux = n/2;

        if(n%2==0){
            std::vector<float>::iterator it=floatVector.begin()+aux-1;
            std::vector<float>::iterator it2=floatVector.begin()+aux;
            resultado=((*it+*it2)/2);

        }

      else {
        std::vector<float>::iterator it=floatVector.begin()+aux;
        resultado=*it;
      }
    floatVector.erase(floatVector.begin(),floatVector.end());
    cout << resultado << endl;


    return 0;
}
