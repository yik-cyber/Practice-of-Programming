#include<bits/stdc++.h>
using namespace std;

char maze[260][260];
bool status[260][260][6];
int n, m, h;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
struct Node{
	int x, y, l, t;
	Node(int _x, int _y, int _l, int _t):x(_x),y(_y),l(_l), t(_t){
	}
	Node(){
	}
};

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m >> h;
		memset(status, false, sizeof(status));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> maze[i][j];
			}
		}
		queue<Node> myque;
		myque.push(Node(0,0,h,0));
		status[0][0][h] = true;
		while(!myque.empty()){
			Node p = myque.front();
			myque.pop();
			
			if (p.x == n-1 && p.y == m-1){
				cout << p.t << "\n";
				break;
			}
			int nx, ny, nl, nt;
			nt = p.t+1;
			for(int i = 0; i < 4; i++){
				nx = p.x + dx[i];
				ny = p.y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (maze[nx][ny] == '#') continue;
				if (maze[nx][ny] == '*' && p.l > 1 && !status[nx][ny][p.l-1]){
					myque.push(Node(nx,ny,p.l-1,nt));
					status[nx][ny][p.l-1] = true;;
				}
				if (maze[nx][ny] == '.' && !status[nx][ny][p.l]){
					myque.push(Node(nx,ny,p.l,nt));
					status[nx][ny][p.l] = true;
				}
			}
		}
	}
	return 0;
}
