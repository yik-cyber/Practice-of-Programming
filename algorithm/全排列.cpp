#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    char s[7];
    cin >> s;
    int len = strlen(s);
    cout<<s<<"\n";
    while(next_permutation(s, s+len)){
        cout<<s<<"\n";
    }
}
