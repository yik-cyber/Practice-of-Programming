#include<bits/stdc++.h>
using namespace std;

char maze[9][9];
bool visit[9];
int n, k;
int ans;

void dfs(int x, int num){
	if (num == k){
		ans++;
		return;
	}
	if (x == n) return;
	
	for(int r = x; r < n; r++){
		for(int i = 0; i < n; i++){
		if(maze[r][i] == '#' && !visit[i]){
			visit[i] = true;
			dfs(r+1, num+1);
			visit[i] = false;
		   }
	    }
	}
	return;
}

int main(){
	while(scanf("%d %d", &n, &k)){
		if (n == -1 && k == -1) break;
		memset(visit, false, sizeof(visit));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> maze[i][j];
			}
		}
		ans = 0;
		dfs(0, 0);
		printf("%d\n", ans);
	}
}
