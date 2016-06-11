#include <iostream> 
#include <string> 
#include <sstream> 
#include <cctype>

using namespace std; 

int main() { 

    string line, word;
    unsigned char ch;
    bool result;

    while(getline(cin, line)) { 

        bool res = true; 
        stringstream delim(line); 
        delim >> word; 

        if(word[0] == '*') 
            return 0; 

        else 
            ch = tolower(word[0]); 

        while(delim >> word) { 
            if(ch != tolower(word[0])) { 
                cout << "N\n"; 
                res = false; 
                break; 
            } 
        } 
        if(res == true) 
            cout << "Y\n"; 
    } 
    return 0; 
}
