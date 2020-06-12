#include<bits/stdc++.h>
using namespace std;

char maze[110][110];
int num[110][110];

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> maze[i][j];
			if (maze[i][j]=='*'){
				if (i-1>=0 && j-1 >= 0) num[i-1][j-1]++;
				if (i-1>=0) num[i-1][j]++;
				if (i-1>=0 && j+1 < m) num[i-1][j+1]++;
				if (j-1 >= 0) num[i][j-1]++;
				if (j+1 < m) num[i][j+1]++;
				if (i+1<n && j-1>=0) num[i+1][j-1]++;
				if (i+1<n) num[i+1][j]++;
				if (i+1 < n && j+1 < m) num[i+1][j+1]++;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if (maze[i][j] != '*') cout << num[i][j];
			else cout << "*";
		}
		cout << "\n";
	}
	return 0;
}
