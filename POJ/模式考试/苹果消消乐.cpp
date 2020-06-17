#include<bits/stdc++.h>
using namespace std;

int peach[110];

int main(){
    int t;
    cin >> t;
    while (t--){
        memset(peach, 0, sizeof(peach));
        int n, m, ans = 0;
        cin >> n >> m;
        m = min(m, n);
        for(int i = 1; i <= n; i++){
            cin >> peach[i];
        }
        peach[0] = 0;
        peach[n+1] = 101;
        int l = 1, r = m;
        while (r <= n){
            ans = max(ans, peach[r+1]-peach[l-1]-1);
            l++;
            r++;
        }
        cout << ans << "\n";
    }
}
