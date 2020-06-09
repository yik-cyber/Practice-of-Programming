#include<bits/stdc++.h>
using namespace std;

int n, w;
int item[20];
int ans = 21;
int cab[20];
void dfs(int cnt, int now){
    if (cnt >= ans) return;
    if (now == n){
        ans = min(ans, cnt);
    }

    for(int i = 1; i <= cnt; i++){
        if (cab[i]+item[now] <= w){
            cab[i]+=item[now];
            dfs(cnt, now+1);
            cab[i]-=item[now];
        }
    }
    cab[cnt+1] = item[now];
    dfs(cnt+1, now+1);
    cab[cnt+1] = 0;
}

int main(){
	cin >> n >> w;
	for(int i = 0; i < n; i++){
		cin >> item[i];
	}
	sort(item, item + n);
	reverse(item, item+ n );
	dfs(0,0);
	cout << ans << "\n";
}
