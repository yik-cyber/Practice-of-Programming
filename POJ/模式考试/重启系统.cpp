#include <bits/stdc++.h>
using namespace std;

int n;
int f[1010], g[1010];
int num[1010];

int main(){
    scanf("%d", &n);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &num[i]);
    }
    for(int i = n; i >= 1; i--){
        f[i] = 1;
        for(int j = i+1; j <= n; j++){
            if(num[j]<=num[i]) f[i] = max(f[i], f[j]+1);
        }
    }
    for(int i = 1; i <= n; i++){
        g[i] = 1;
        for(int j = 1; j < i; j++){
            if(num[j]>=num[i]) g[i] = max(g[i], g[j]+1);
        }
    }

    for(int i = 1; i <= n; i++){
        int tmax = g[i];
        for(int j = i+1; j <= n; j++){
            tmax = max(tmax, g[i]+f[j]);
        }
        ans = max(ans, tmax);
    }
    printf("%d", ans);
}
