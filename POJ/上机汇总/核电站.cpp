#include <bits/stdc++.h>
using namespace std;


long long f[60];
int n, m;
int main(){
    cin >> n >> m;
    f[0] = 1;
    for(int i = 1; i <= n; i++){
        if(i<m){
            f[i] = 2*f[i-1];
        }
        else if (i == m) f[i] = 2*f[i-1] - f[0];
        else{
            f[i] = 2*f[i-1] - f[i-m-1];
        }
    }
    cout << f[n];
}
