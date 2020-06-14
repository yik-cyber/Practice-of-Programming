#include<bits/stdc++.h>
using namespace std;

int dis[260][260];
int color[260][260];
int cnt;
int h, w, m;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

void dfs(int x, int y){
    if(color[x][y]) return;
    color[x][y] = cnt;

    int nx, ny;
    int cl = dis[x][y];
    for(int i = 0; i < 4; i++){
        nx = x+dx[i];
        ny = y+dy[i];
        if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
        if (abs(dis[nx][ny]-cl) <= m) dfs(nx, ny);
    }
}

int main(){
    while(cin >> h >> w >> m && h != 0 && w !=0 ){
        memset(color, 0, sizeof(color));
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> dis[i][j];
            }
        }
        cnt = 1;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(!color[i][j]){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt-1 << "\n";
    }
}
