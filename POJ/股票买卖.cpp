#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	int test;
	scanf("%d", &test);
	while(test--){
		int n;
		scanf("%d", &n);
		int price[n];
		for(int i = 0; i < n; ++i) scanf("%d", &price[i]);
		int dp1[n];
		int dp2[n];
		int min1 = price[0];
		dp1[0] = 0;
		for(int i = 1; i < n; ++i){
			dp1[i] = max(dp1[i-1], price[i]-min1);
			if(price[i]<min1) min1 = price[i];
		}
		int max2 = price[n-1];
		dp2[n-1] = 0;
		for(int i = n-2; i >= 0; --i){
			dp2[i] = max(dp2[i+1], max2-price[i]);
			if(price[i]>max2) max2 = price[i];
		}
		int ans = 0;
		for(int i = 0; i < n; ++i){
			ans = max(ans, dp1[i]+dp2[i]);
		}
		printf("%d\n", ans);
	}
}
