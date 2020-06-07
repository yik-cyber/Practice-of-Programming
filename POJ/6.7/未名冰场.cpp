#include<bits/stdc++.h>
using namespace std;

char maze[110][110];
bool visits[110][110];
int n, m;
int cnt;
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

void dfs(int x, int y){
	if(visits[x][y] || maze[x][y] == '*') return;
	visits[x][y] = true;
	int nx, ny;
	for(int i = 0; i < 8; i++){
		nx = x+dx[i]; ny = y+dy[i];
		if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		dfs(nx, ny);
	}
}

int main(){	
	while(cin >> n >> m && n > 0 && m > 0){
		memset(visits, false, sizeof(visits));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> maze[i][j];
			}
		}
		cnt = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(!visits[i][j] && maze[i][j] == '@'){
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
}
