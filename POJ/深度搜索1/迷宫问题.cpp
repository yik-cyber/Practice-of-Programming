#include<bits/stdc++.h>
using namespace std;

bool visit[6][6];
int maze[6][6];
struct Path{
	Path(int _x, int _y):x(_x), y(_y){
	}
	int x, y;
};
ostream& operator<<(ostream& out, Path p){
	out << "(" << p.x << ", " << p.y <<")";
	return out;
}
int ans = 26;
vector<Path> best_paths, paths;

void dfs(int x, int y, int cnt){
	if (cnt > ans) return;
	if (x == 4 && y == 4){
		paths.push_back(Path(x, y));
		if (cnt < ans){
			best_paths = paths;
		}
		return;
	}
	visit[x][y] = true;
	paths.push_back(Path(x, y));
	if (x+1<5 && maze[x+1][y] == 0 && !visit[x+1][y]) dfs(x+1, y, cnt++);
	if (y+1<5 && maze[x][y+1] == 0 && !visit[x][y+1]) dfs (x, y+1, cnt++);
	visit[x][y] = false;
	paths.pop_back();
	return;
}

int main(){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			cin >> maze[i][j];
		}
	}
	memset(visit, false, sizeof(visit));
	dfs(0, 0, 1);
	for(int i = 0; i < best_paths.size(); i++){
		cout << best_paths[i] << "\n";
	}
}
