#include <iostream>

using namespace std;

const int MAX = 1000000;

int main (){

    int K, L, M, N;
    bool pd[MAX];
    cin >> K >> L >> M;

    for (int i = 0; i <= MAX; i++)
        pd[i] = false;

    for (int i = 1; i <= MAX; i++)
        if (pd[i-1] == false ||
            (i-L >= 0 && pd[i-L] == false) || 
            (i-K >= 0 && pd[i-K] == false))
            pd[i] = true;

    for (int i = 0; i < M; i++){
        cin >> N;

        if (pd[N] == true)
            cout << "A";
        else 
            cout << "B";
    }

    cout << "\n";
    return 0;
}
