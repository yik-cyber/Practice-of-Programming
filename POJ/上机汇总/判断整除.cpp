#include <bits/stdc++.h>
using namespace std;


int n, k;
bool f[10010][110];
int num[10010];

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
        num[i] %= k;
    }
    f[0][0] = true;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++){
            f[i][j] = (f[i-1][abs(j-num[i]%k)] | f[i-1][(j+num[i])%k]);
        }
    }
    if(f[n][0]) cout << "YES" <<"\n";
    else cout << "NO" << "\n";
}
