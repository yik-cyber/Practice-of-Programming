#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        int f[110]{0};
        int g[110]{0};
        int len = s.length();
        int j;
        for(int i = 0; i < len; i++){
            if (s[i] == s[i+1]){
                int k = i, l = i+1;
                for(;k >=0 && l < len; k--, l++){
                    if (s[k] != s[l]) break;
                }
                g[i] = i-k;
            }
            for(j = 1; i-j >= 0 && i+1 < len; j++){
                if (s[i-j] != s[i+j]) break;
            }
            f[i] = j-1;
        }
        int ans1 = 0, ans2 = 0, ans1_i = 0, ans2_i = 0;
        for(int i = len-1; i >= 0; i--){
            if (f[i] >= ans1){
                ans1 = f[i];
                ans1_i = i;
            }
            if (g[i] >= ans2){
                ans2 = g[i];
                ans2_i = i;
            }
        }
        string sub;
        if (2*ans1+1 > ans2*2) sub = s.substr(ans1_i - ans1, 2*ans1+1);
        else sub = s.substr(ans2_i - ans2 + 1, 2 * ans2);
        cout << sub << "\n";
    }
}
