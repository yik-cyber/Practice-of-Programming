#include<bits/stdc++.h>
using namespace std;

int price[100010];
int f[100010];
int s[100010];
int n;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++) scanf("%d", &price[i]);
		
		f[1] = 0;
		int minp = price[1];
		for(int i = 2; i <= n; i++){
			f[i] = max(f[i-1], price[i] - minp);
			minp = min (minp, price[i]);	
		}
		
		s[n] = 0;
		int maxp = price[n];
		for(int i = n-1; i >= 1; i--){
			s[i] = max(s[i+1], maxp - price[i]);
			maxp = max (maxp, price[i]);
		}
		
		int ans = 0;
		for(int i = 1; i <= n; i++){
			ans = max(ans, f[i]+s[i]);
		}
		printf("%d\n", ans);
	}
}
