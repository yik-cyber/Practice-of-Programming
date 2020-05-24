#include <bits/stdc++.h>
using namespace std;

const int N = 260;
long long f[N+1][N+1];

int main(){
    f[1][1] = 1;
    f[2][1] = 2;
    f[2][2] = 1;
    for (int i = 0; i <= N; i++){
        f[0][i] = 1;
    }
    for(int i = 3; i <= N; i++){

        for (int j = i / 2; j <= i ; j++){
            f[i][j] = 1;
        }
        for(int j = i / 2; j>=1; j--)
            f[i][j] = f[i-j*2][j] + f[i][j+1];
    }
    int n;

    while(scanf("%d", &n) && n != 0){
        printf("%d %lld\n", n, f[n][1]);
    }
    return 0;
}
