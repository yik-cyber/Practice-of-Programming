#include<bits/stdc++.h>
using namespace std;

char maze[510][510];
bool paint[510][510];
int r, c;

void dfs(int x, int y){
    if(maze[x][y] == 'O') paint[x][y] = true;
    else return;

    if (x+1 < r && !paint[x+1][y]) dfs(x+1, y);
    if (y+1 < c && !paint[x][y+1]) dfs(x, y+1);
    if (x-1 >= 0 && !paint[x-1][y]) dfs(x-1, y);
    if (y-1 >= 0 && !paint[x][y-1]) dfs(x, y-1);
    return;
}

int main(){
    int n;
    cin >> n;
    while (n--){
        memset(maze, '\0', sizeof(maze));
        memset(paint, false, sizeof(paint));
        cin >> r >> c;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                cin >> maze[i][j];

        for(int i = 0; i < c; i++){
            if(maze[0][i] == 'O') dfs(0, i);
            if(maze[r-1][i] == 'O') dfs(r-1, i);
        }
        for(int j = 1; j < r-1; j++){
            if(maze[j][0] == 'O') dfs(j, 0);
            if(maze[j][c-1] == 'O') dfs(j, c-1);
        }

        for(int i = 1; i < r-1; i++){
            for(int j = 1; j < c-1; j++){
                if(maze[i][j] == 'O' && !paint[i][j]) maze[i][j] = 'X';
            }
        }
        for (int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++){
                cout << maze[i][j];
            }
            cout<<"\n";
        }
        cout << "\n";
    }
}
