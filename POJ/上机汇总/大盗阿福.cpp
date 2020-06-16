#include <bits/stdc++.h>
using namespace std;

int money[100010];
int f[100010];
int n,t;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> money[i];
        f[0] = 0; f[1] = money[1];
        for(int i = 2; i <= n; i++){
            f[i] = max(f[i-1], f[i-2]+money[i]);
        }
        cout << f[n] << "\n";
    }
}
