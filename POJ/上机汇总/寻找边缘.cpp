#include <bits/stdc++.h>
using namespace std;

char maze[510][510];
bool mark[510][510];
int t, r, c;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

void dfs(int x, int y){
    if(maze[x][y] == 'O') mark[x][y] = true;
    else return;

    int nx, ny;
    for(int i = 0; i < 4; i++){
        nx = x + dx[i];
        ny = y + dy[i];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if(mark[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int main(){
    cin >> t;
    while(t--){
        memset(mark, false, sizeof(mark));
        cin >> r >> c;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> maze[i][j];
            }
        }
        for(int i = 0; i < c; i++){
            if(maze[0][i] == 'O' && !mark[0][i]) dfs(0, i);
            if(maze[r-1][i] == 'O' && !mark[r-1][i]) dfs(r-1, i);
        }
        for(int i = 1; i < r-1; i++){
            if(maze[i][0] == 'O' && !mark[i][0]) dfs(i, 0);
            if(maze[i][c-1] == 'O' && !mark[i][c-1]) dfs(i, c-1);
        }
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(maze[i][j] == 'O' && !mark[i][j]) maze[i][j] = 'X';
                cout << maze[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }
}
