#include <iostream>
using namespace std;
int main(){
    int a, n, m, x;
    cin >> a >> n >> m >> x;
    int up[n];
    int tot[n];
    tot[1] = tot[2] = a;
    up[1] = a;
    for(int i = 0; i <= m; ++i){
        up[2] = i;
        for(int j = 3; j < n; ++j){
            up[j] = up[j-1]+up[j-2];
            tot[j] = tot[j-1] + up[j-2];
        }
        if (tot[n-1] == m) break;
    }
    cout<<tot[x];
}
