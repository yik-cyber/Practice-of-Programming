#include<cstdio>
#include <cstring>
#include<algorithm>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int f[m+1];
    int w[n+1];
    int v[n+1];
    for(int i = 1; i <= n; i++) scanf("%d %d", &v[i], &w[i]);
    memset(f, 0, sizeof(f));
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= v[i]; j--){
                f[j] = max(f[j], f[j-v[i]] + w[i]);
        }
    }
    printf("%d", f[m]);
}
