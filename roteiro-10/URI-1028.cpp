#include <iostream> // std::cout
#include <algorithm> // std::sort
#include <vector> // std::vector
#include <string>
#include <iterator>

using namespace std;

int N,F1,F2;

void mdc(int a, int b){
  int mod;
  while(!b==0){
    mod =a%b;
    a = b;
    b = mod;
  }
  cout << a << endl;
}

int main(){
  cin >> N;
  while(N--){
    cin >> F1 >> F2;
    mdc(F1,F2);
  }

  return 0;
}
