#include<bits/stdc++.h>
using namespace std;

int n, m;
char dis[100][10];
bool valid[100][1<<10];
int f[100][1<<10][1<<10];
set<int> S;

int count_one(int x){
    int cnt = 0;
    while(x > 0){
        if(x&1) cnt++;
        x = x>>1;
    }
    return cnt;
}
int main(){
    memset(valid, false, sizeof(valid));
    cin >> n >> m;
    int i, j, k, u;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            cin >> dis[i][j];
        }
    }
    int end = 1<<m;
    int t;
    int indx;
    bool in_s;
    for(i = 0; i < end; i++){
        indx = -10;
        in_s = true;
        for(j = 0; j < m; j++){
            if((i>>j)&1 && ((i>>j+1)&1 || (i>>j+2)&1)) in_s = false;
        }
        if(in_s) S.insert(i);
    }

    bool val;
    for(int i = 0; i < n; i++){
        for(auto p = S.begin(); p != S.end(); p++){
            t = *p;
            val = true;
            for(int j = 0; j < m; j++){
                if((t>>j)&1){
                    if(dis[i][j] == 'H'){
                        val = false;
                        break;
                    }
                }
            }
            if(val) valid[i][t] = true;
        }
    }
    memset(f, -2e8, sizeof(f));
    f[0][0][0] = 0;
    int ans = 0;
    for(i = 0; i < n; i++){
        for(auto p = S.begin(); p != S.end(); p++){
            j = *p;
            if(!valid[i][j]) continue;
            for(auto q = S.begin(); q != S.end(); q++){
                k = *q;
                if(!valid[i-1][k] || !(j&k)) continue;
                for(auto l = S.begin(); l != S.end(); l++){
                    u = *l;
                    if(!valid[i-2][u] || !(k&u)) continue;
                    f[i][j][k] = max(f[i-1][k][u] + count_one(j), f[i][j][k]);

                }
                if (i == n-1) ans = max(f[i][j][k], ans);
            }
        }
    }
    cout << ans << "\n";
}
