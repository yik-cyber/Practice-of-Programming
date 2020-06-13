#include<bits/stdc++.h>
using namespace std;

int cheese[100010];
long long f[100010];
int n, t, ans;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> cheese[i];
        }
        f[0] = 0;
        for(int i = 1; i <= n; i++){
            f[i] = max(f[i-1], f[i-2]+cheese[i]);
        }
        cout << f[n] << "\n";
    }
}
