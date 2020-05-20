#include<cstdio>
#include <cstring>
#include<algorithm>
#include <set>
using namespace std;



int main(){
    int n, x;
    scanf("%d %d", &n, &x);
    int coin[n+1];
    for(int i = 1; i <= n; i++) scanf("%d", &coin[i]);
    int f[x+1];
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = x; j >= coin[i]; j--){
            f[j] +=  f[j-coin[i]];
        }
    }
    int g[x+1];
    set<int> used;
    for(int i=1;i<=n;++i){
        memset(g,0,sizeof(g));
        for(int j=0;j<=x;++j){
            if(j<coin[i])
                g[j]=f[j];
            else g[j]=f[j]-g[j-coin[i]];
        }
        if(!g[x]){
            used.insert(coin[i]);
        }
    }
    printf("%d\n", used.size());
    set<int>::iterator p = used.begin();
    if (p != used.end()){
        printf("%d", *p);
        p++;
        for(; p != used.end(); p++) printf(" %d", *p);
    }
    return 0;
}
