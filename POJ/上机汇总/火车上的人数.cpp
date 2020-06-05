#include <bits/stdc++.h>
using namespace std;
int a, n, m, x;
int f[20];

int main(){
    cin >> a >> n >> m >> x;
    f[1] = a;
    int out;
    for(int i = 0; i <= m; i++){
        f[2] = i;
        int sum = a;
        for(int j = 3; j < n; j++){
            f[j] = f[j-1] + f[j-2];
            sum += f[j-2];
            if (j == x) out = sum;
        }
        if (sum == m) break;
    }
    cout << out;
}
