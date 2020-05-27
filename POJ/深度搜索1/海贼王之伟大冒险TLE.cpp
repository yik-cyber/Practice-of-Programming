#include<bits/stdc++.h>
using namespace std;

int n;
int path[20][20];
bool visit[20];
int ans = 0x3f3f3f3f;

void dfs(int x, int time, int num){
	if (time >= ans) return;
	if (visit[n] && num < n) return;
	if (x == n && num == n){
		ans = min(ans, time);
		return;
	}	
	
	for(int i = 1; i <= n; i++){
		if (visit[i]) continue;
		visit[i] = true;
		dfs(i, time + path[x][i], num+1);
		visit[i] = false;
	}
	return;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &path[i][j]);
		}
	}
	memset(visit, false, sizeof(visit));
	visit[1] = true;
	dfs(1, 0, 1);
	printf("%d\n", ans);
}
