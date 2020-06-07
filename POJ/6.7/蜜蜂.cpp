#include<bits/stdc++.h>
using namespace std;
long long f[55];
void solve(){
	f[2] = 1;
	f[3] = 2;
	for(int i = 4; i < 50; i++){
		f[i] = f[i-1]+f[i-2];
	}
}
int main(){
	int n;
	cin >> n;
	solve();
	while(n--){
		int a, b;
		cin >> a >> b;
        cout << f[b-a+1] << "\n";
	}
}
