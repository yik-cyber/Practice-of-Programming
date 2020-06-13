#include<bits/stdc++.h>
using namespace std;

int f[25][1010];
int num[25];
int n, t;

int main() {
    scanf("%d %d", &n, &t);
    for (int i = 1; i <= n; i++) scanf("%d", &num[i]);

    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i][0] = 1;
        for (int j = 1; j <= t; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= num[i]) f[i][j] += f[i - 1][j - num[i]];
        }
    }
    printf("%d", f[n][t]);
}
