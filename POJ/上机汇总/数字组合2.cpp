#include<bits/stdc++.h>
using namespace std;

int f[1010];
int num[25];
int n, t;

int main() {
    scanf("%d %d", &n, &t);
    for (int i = 1; i <= n; i++) scanf("%d", &num[i]);

    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = t; j >= num[i]; j--) {
            f[j] += f[j-num[i]];
        }
    }
    printf("%d", f[t]);
}
