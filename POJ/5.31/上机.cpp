/*这个状态表示我是想不到的（悲*/
#include<bits/stdc++.h>
using namespace std;

int f[10010], g[10010];
int a[10010], b[10010], c[10010];
int n;

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1; i <= n; i++) cin >> c[i];
	f[1] = a[1]; g[1] = b[1];
	for(int i = 2; i <= n; i++){
		f[i] = max(f[i-1]+b[i], g[i-1]+a[i]);
		g[i] = max(f[i-1]+c[i], g[i-1]+b[i]);
	}
	cout << f[n];
}
