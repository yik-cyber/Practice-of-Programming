#include<bits/stdc++.h>
using namespace std;

int n, m, ans;
char dis[110][11];
int dp[110][110][110];
int status[110], counts[110], maps[110];

int count_one(int x){
    int cnt = 0;
    while (x>0){
        if(x&1) cnt++;
        x = x >> 1;
    }
    return cnt;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < m; j++){
            cin >> dis[i][j];
            if(dis[i][j] == 'P') sum += 1<<(m-j-1);
        }
        maps[i] = sum;
    }
    int end = 1 << m;
    int tot = 0;
    for(int i = 0; i < end; i++){
        if(i&(i<<1) || i&(i<<2)) continue; //compare with the former number
        status[tot] = i;
        counts[tot++] = count_one(i);
    }
    for(int i = 0; i < tot; i++){
        if((maps[0] | status[i]) == maps[0]) dp[0][i][0] = counts[i];
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < tot; j++){
            if((maps[i]|status[j]) == maps[i]){
                for(int k = 0; k < tot; k++){
                    if((status[j]&status[k])==0){
                        for(int l = 0; l < tot; l++){
                            if((status[l]&status[k]) == 0 && ((status[l]&status[j])==0)){
                                dp[i][j][k] = max(dp[i][j][k], dp[i-1][k][l]+counts[j]);
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i = 0;i < n; i++){
        for(int j = 0; j < tot; j++){
            for(int k = 0; k < tot; k++){
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans << "\n";
}
