#include<bits/stdc++.h>
using namespace std;

bool visit[7];
char s1[7], s2[7];
int n;

void dfs(int x){
	if (x == n+1){
		for(int i = 1; i <= n; i++){
			cout << s2[i];
		}
		cout << "\n";
	}
	
	for(int i = 1; i <= n; i++){
		if (!visit[i]){
			visit[i] = true;
			s2[x] = s1[i-1];
			dfs(x+1);
			visit[i] = false;
		}
	}
}
int main(){
	cin >> s1;
	n = strlen(s1);
	dfs(1);
}
