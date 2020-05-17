#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int height[n];
	for(int i = 0; i < n; ++i) scanf("%d", &height[i]);
	int dp1[n];
	int dp2[n];
	for(int i = 0; i < n; ++i){
		dp1[i] = 1;
		for(int j = i - 1; j >= 0; --j){
			if(height[j] < height[i]) dp1[i] = max(dp1[i], dp1[j]+1);
		}
	}
	for(int i = n-1; i >= 0; --i){
		dp2[i] = 1;
		for(int j = i + 1; j < n; ++j){
			if(height[j] < height[i]) dp2[i] = max(dp2[i], dp2[j]+1);
		}
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		ans = max(dp1[i]+dp2[i]-1, ans);
	}
	printf("%d", ans);
}
