#include <bits/stdc++.h>
using namespace std;

int t,m,ans;
int p[110], n[110];
int f[110][3];

int main(){
    cin >> t >> m;
    for(int i = 1; i <= t; i++){
        cin >> p[i] >> n[i];
    }
    for(int i = 1; i <= t; i++){
        f[i][0] = max(f[i-1][0]+p[i], f[i-1][1]+n[i]-m);
        f[i][1] = max(f[i-1][0]+p[i]-m, f[i-1][1]+n[i]);
    }
    ans = max(f[t][0], f[t][1]);
    cout << ans;
}
