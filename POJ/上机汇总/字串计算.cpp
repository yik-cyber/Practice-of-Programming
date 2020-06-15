#include<bits/stdc++.h>
using namespace std;

map<string, int> counts;


int main(){
    string s, tmp;
    cin >> s;
    int len = s.length();
    for(int i = 1; i <= len; i++){
        for(int j = 0; j < len-i+1; j++){
            tmp = s.substr(j, i);
            if (counts.count(tmp) == 0) counts.insert(make_pair(tmp, 1));
            else counts[tmp] += 1;
        }
    }
    for(auto p = counts.begin(); p != counts.end(); p++){
        if(p->second > 1) cout << p->first << " " << p->second << "\n";
    }
    return 0;
}
