#include <bits/stdc++.h>

#include <utility>
using namespace std;


int n, m, k;
int maze[21][21];
bool status[21][21];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int ans = 0;
set<int> tp;

void dfs(int x, int y){

    int nx, ny;
    for(int i = 0; i < 4; i++){
        nx = x+dx[i];
        ny = y+dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(status[nx][ny]) continue;
        if(tp.count(maze[nx][ny])) continue;

        tp.insert(maze[nx][ny]);
        ans = max(ans, int(tp.size()));
        dfs(nx, ny);
        tp.erase(maze[nx][ny]);
        status[nx][ny] = false;
    }

}


int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> maze[i][j];
        }
    }
    tp.insert(maze[0][0]);
    dfs(0,0);
    cout << ans;
}
