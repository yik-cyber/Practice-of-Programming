/*最开始因为初始化dp的时候数组没开大一直RE，233
* 想法是把倒数第二步到的岛屿全部记录下来再计算一次他们到最后一个岛的时间，选取最小的就可以了，之前的顺序不重要，用状压就行了
*/

#include<bits/stdc++.h>
using namespace std;

struct DP{
	int island;
	int min_time;
};

int t[20][20];
int n;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &t[i][j]);
		}
	}
	int m = 1 << (n-1);
	DP dp[m+10];
	dp[0].island = 0;
	dp[0].min_time = 0;
	vector<DP> last;	
	for(int i = 1; i < m; i++){
		dp[i].min_time = 0x3f3f3f3f;
		for(int j = 0; j < n-1; j++){
			if (!(i & (1<<j))) continue;			
			int pre = i - (1<<j);
			int time = dp[pre].min_time + t[dp[pre].island][j];
			
			if (i == m-1){
				DP tmp; tmp.island = j; tmp.min_time = time;
				last.push_back(tmp);
			}
			if (time < dp[i].min_time){
				dp[i].min_time = time;
				dp[i].island = j;
			}
		}
	}
	int ans = 0x3f3f3f3f;
	for(int i = 0; i < int(last.size()); i++){
		ans = min(ans, last[i].min_time + t[last[i].island][n-1]);
	}
	printf("%d\n", ans);
}
