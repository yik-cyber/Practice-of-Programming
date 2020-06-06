#include<bits/stdc++.h>
using namespace std;

int f[1010];
int n, ans;
int num[1010];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &num[i]);
	}
	for(int i = 0; i < n; i++){
		f[i] = num[i];
		for(int j = i-1; j >= 0; j--){
			if (num[j] < num[i]){
				f[i] = max(f[i], f[j]+num[i]);
			}
		}
		ans = max(ans, f[i]);
	}
	printf("%d",ans);
}
