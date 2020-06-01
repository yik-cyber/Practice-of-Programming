#include <bits/stdc++.h>
using namespace std;

set<int> dp[7][7];
int num[7];

int main(){
	int n, sum = 1;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> num[i];
		sum *= i;
	}
	bool can = false;
	for(int l = 0; l < sum; l++){
		next_permutation(num+1, num+n+1);
		for(int i = 1; i <= n; i++){
			dp[i][i].insert(num[i]);
			for(int j = i+1; j <= n; j++){
				for(int k = i; k <= j- 1; k++){
					
					for(set<int>::iterator x = dp[i][k].begin(); x != dp[i][k].end(); x++){
						for(set<int>::iterator y = dp[k+1][j].begin(); y != dp[k+1][j].end(); y++){
							dp[i][j].insert(*x + *y);
							dp[i][j].insert(*x - *y);
							dp[i][j].insert((*x)*(*y));
							if(*y != 0 && (*x) % (*y) == 0) dp[i][j].insert((*x)/(*y));
						}
					}
				}
			}
		}
		if (dp[1][n].count(42)){
			cout << "YES" << "\n";
			return 0;
		}
	}
	cout << "NO" <<"\n";
	return 0;
}
