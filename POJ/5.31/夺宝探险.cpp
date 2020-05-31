#include<bits/stdc++.h>
using namespace std;

int maze[30][30];
int m, n, k;
int ans = 0;
set<int> t;

void dfs(int x, int y){
    bool ok = true;
    if (x+1<m && t.count(maze[x+1][y]) == 0){
        ok = false;
        t.insert(maze[x+1][y]);
        dfs(x+1, y);
        t.erase(maze[x+1][y]);
    }
    if (y+1<n && t.count(maze[x][y+1]) == 0){
        ok = false;
        t.insert(maze[x][y+1]);
        dfs(x, y+1);
        t.erase(maze[x][y+1]);
    }
    if (x-1>=0 && t.count(maze[x-1][y]) == 0){
        ok = false;
        t.insert(maze[x-1][y]);
        dfs(x-1, y);
        t.erase(maze[x-1][y]);
    }
    if (y-1>=0 && t.count(maze[x][y-1]) == 0){
        ok = false;
        t.insert(maze[x][y-1]);
        dfs(x, y-1);
        t.erase(maze[x][y-1]);
    }
    if (ok){
        ans = max(ans, int(t.size()));
    }

}
int main(){
    cin >> m >> n >> k;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> maze[i][j];
    t.insert(maze[0][0]);
    dfs(0, 0);
    cout << ans;
}
