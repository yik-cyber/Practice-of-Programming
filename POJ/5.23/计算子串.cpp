#include <bits/stdc++.h>
using namespace std;

string str[50010];
map<string, int> substrs;

int main(){
    string s;
    cin >> s;
    int n = 0;
    for(int i = 1; i <= s.size(); i++){
        for(int j = 0; j < s.size() && i + j <= s.size(); j++){
            string tmp = s.substr(j, i);
            if (substrs.count(tmp) == 0) {
                substrs.insert({tmp, 1});
                str[n++] = tmp;
            }
            else substrs[tmp]++;
        }
    }
    sort(str, str + n);
    for(int i = 0; i < n; i++){
        if (substrs[str[i]] > 1) cout << str[i] << " " << substrs[str[i]] << "\n";
    }

}
