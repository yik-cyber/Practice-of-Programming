#include <vector>
#include <set>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    set<int> record;
    multiset<int> number;
    string cmd;
    int n, x, cnt = 0;
    cin>>n;
    while(n--){
        cin>>cmd>>x;
        if(cmd == "add"){
            number.insert(x);
            record.insert(x);
            cnt = number.count(x);
            printf("%d\n", cnt);
        }
        else if(cmd == "del"){
            cnt = number.count(x);
            number.erase(x);
            printf("%d\n", cnt);
        }
        else{
            int history = record.count(x);
            cnt = number.count(x);
            printf("%d %d\n", history, cnt);
        }
    }
}
