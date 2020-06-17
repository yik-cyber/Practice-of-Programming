#include<bits/stdc++.h>
using namespace std;

int m, n;
int maze[110][110];
int status[110][110];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
vector<int> nums;

struct Node{
    int x, y, k, t;
    Node(int _x, int _y, int _k, int _t):x(_x), y(_y), k(_k), t(_t){}
    Node(){}
};
queue<Node> myque;

int main(){
    int t;
    cin >> t;
    while (t--){
        memset(status, -1, sizeof(status));
        nums.clear();
        myque = queue<Node>();
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++) {
                cin >> maze[i][j];
                if (maze[i][j] > 1) nums.push_back(maze[i][j]);
            }
        }
        sort(nums.begin(), nums.end());
        int cnt = nums.size();

        bool is_out = false;
        if(maze[1][1] == nums[0]){
            myque.push(Node(1,1,1,0));
            status[1][1] = 1;
        }
        else{
            myque.push(Node(1,1,0,0));
            status[1][1] = 0;
        }
        while (!myque.empty()){
            Node p = myque.front();
            myque.pop();

            if (p.k == cnt){
                is_out = true;
                cout << p.t << "\n";
                break;
            }

            int nx, ny, nk, nt = p.t+1;
            for(int i = 0; i < 4; i++){
                nx = p.x + dx[i];
                ny = p.y + dy[i];
                nk = p.k;
                if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
                int tk = maze[nx][ny];
                if(tk == 0) continue;
                if(nums[nk] == tk) nk++;
                if(status[nx][ny] >= nk) continue;
                status[nx][ny] = nk;
                myque.push(Node(nx,ny,nk,nt));

            }
        }
        if(!is_out) cout << -1 << "\n";
    }
}
