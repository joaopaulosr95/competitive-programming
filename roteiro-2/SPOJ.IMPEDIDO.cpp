#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <string>
#include <iterator>



using namespace std;



int main()
{
    int attack,defense;
    int input1,input2;


    while(cin >>attack >>defense && !attack==0 && !defense==0){ //loop at� ler 0 0

    vector<int> intVector;//vetor p atacantes
    vector<int> intVector2;//vetor para defensor
    int i=0;
    int j=0;


    while(i<attack){
        cin >> input1;
        intVector.push_back(input1);//faz vetor de posi�oes dos atacantes
        i++;
    }

   while(j<defense){
        cin >> input2;
        intVector2.push_back(input2);//faz vetor de posi�oes dos defensores
        j++;
    }

    std::sort (intVector.begin(), intVector.end());
    std::sort (intVector2.begin(), intVector2.end());

    std::vector<int>::iterator it=intVector.begin(); //atacante mais perto da area
    std::vector<int>::iterator it2=intVector2.begin()+1; // segundo defensor mais perto da area

    intVector.erase(intVector.begin(),intVector.end()); //desaloca?
    intVector2.erase(intVector2.begin(),intVector2.end()); //desaloca?

    if(*it<*it2){
        cout << "Y" << endl;//est� impedido

    }

    else {cout << "N" << endl;//nao est� impedido

    }

}

}
