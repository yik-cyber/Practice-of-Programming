/*注意递推式的计算8*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    long long f[n + 10];
    memset(f, 0, sizeof(f));//整体移动6位
    f[5] = f[6] = 1;
    for(int i = 7; i <= n+6; i++){
        f[i] = 2*f[i-1] - f[i-m-1];
    }
    printf("%lld", f[n+6]);
}
