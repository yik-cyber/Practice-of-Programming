#include<cstdio>
#include<string.h>
int main(){
	int n, t;
	scanf("%d %d", &n, &t);
	int num[n];
	for(int i = 0; i < n; ++i) scanf("%d", &num[i]);
	int dp[t+1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = t; j >= num[i]; j--){
			dp[j] += dp[j-num[i]];
		}
	}
	printf("%d", dp[t]);
}
