#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int num[n+1];
    for(int i = 1; i <= n; i++){
        scanf("%d", &num[i]);
    }
    int f[n+1][k+1];
    f[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < k; j++){
            f[i][j] = (f[i-1][(abs(j-num[i]%k))%k]) | f[i-1][(j+num[i]%k)%k];
        }
    }
    if (f[n][0] == 0) printf("NO");
    else printf("YES");
}
