#include<bits/stdc++.h>
using namespace std;

int mountain[1010];
int f[1010], g[1010];
int n, ans;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &mountain[i]);

    for(int i = 1; i <= n; i++){
        f[i] = 1;
        for(int j = i-1; j >= 0; j--){
            if(mountain[j] < mountain[i]) f[i] = max(f[i], f[j]+1);
        }
    }
    for(int i = n; i > 0; i--){
        g[i] = 1;
        for(int j = i+1; j <= n; j++){
            if(mountain[j] < mountain[i]) g[i] = max(g[i], g[j]+1);
        }
    }
    for(int i = 1; i <= n; i++){
        ans = max(ans , f[i]+g[i]-1);
    }
    printf("%d", ans);
    return 0;
}
