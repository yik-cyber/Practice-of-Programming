/*最开始按照求最长上升序列的方法做，两个循环，TLE，后来换了个思路*/

#include <bits/stdc++.h>
using namespace std;


int main(){
    int test;
    scanf("%d", &test);
    while (test--){
        int n;
        scanf("%d", &n);
        int money[n+1];
        for(int i = 1; i <= n; i++) scanf("%d", &money[i]);
        int f[n+1];
        f[1] = money[1];
        f[0] = 0;
        int tmpmax = 0;
        for(int i = 2; i <= n; i++){
            f[i] = max(f[i-2]+money[i], f[i-1]);
        }
        printf("%d", f[n]);
    }
}
