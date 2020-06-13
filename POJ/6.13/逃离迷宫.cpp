#include<bits/stdc++.h>
using namespace std;

char maze[15][15];
bool status[15][15];
int m, t;
struct Node{
    int x, y, t;
    Node(int _x, int _y, int _t):x(_x), y(_y), t(_t){}
    Node(){}
};
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int main(){
    int n;
    cin >> n;
    while(n--){
        queue<Node> myque;
        cin >> m >> t;
        memset(status, false, sizeof(status));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                cin >> maze[i][j];
                if (maze[i][j] == 'S'){
                    myque.push(Node(i, j, 0));
                    status[i][j] = true;
                }
            }
        }
        int ans = t+1;
        while (!myque.empty()){
            Node p = myque.front();
            myque.pop();

            if (maze[p.x][p.y] == 'E'){
                ans = p.t;
                break;
            }
            int nx, ny, nt = p.t+1;
            for(int i = 0; i < 4; i++){
                nx = p.x + dx[i];
                ny = p.y + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= m) continue;
                if (maze[nx][ny] != '#' && !status[nx][ny]){
                    myque.push(Node(nx, ny, nt));
                    status[nx][ny] = true;
                }
            }
        }
        if (ans <= t) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}
