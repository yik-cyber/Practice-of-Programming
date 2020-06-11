#include<bits/stdc++.h>
using namespace std;

struct hw{
	string name;
	int ddl, cost;
}hw[16];

struct DP{
	int present;
	int last_status;
	int min_score;
	int days;
}dp[1<<15];


vector<string> Get_Path(int now_status){
	vector<string> paths;
	while(now_status > 0){
		paths.push_back(hw[dp[now_status].present].name);
		now_status = dp[now_status].last_status;
	}
	reverse(paths.begin(), paths.end());
	return paths;
}

int main(){
	int n;
	int ans;
	cin >> n;
	while(n--){
		int m;
		cin >> m;
		for(int i = 0; i < m; i++){
			cin >> hw[i].name >> hw[i].ddl >> hw[i].cost;
		}
		int end = 1 << m;
		dp[0].last_status = -1;
		dp[0].min_score = 0;
		dp[0].present = -1;
		dp[0].days = 0;
		
		for(int i = 1; i < end; i++){
			int i_min_score = 0x3f3f3f3f;
			for(int j = 0; j < m; j++){
				if (!((i>>j)&1)) continue;
				int last_status = i - (1<<j);
				int prev_days = dp[last_status].days;
				int out_days = prev_days+hw[j].cost-hw[j].ddl;
				int min_score = dp[last_status].min_score + (out_days>0? out_days:0);
				
				if (min_score < i_min_score){
					dp[i].min_score  = i_min_score = min_score;
					dp[i].last_status = last_status;
					dp[i].present = j;
					dp[i].days = prev_days + hw[j].cost;
				}
				if (min_score == i_min_score){
					vector<string> p1 = Get_Path(i);
					vector<string> p2 = Get_Path(last_status);
					p2.push_back(hw[j].name);
					if (p2 < p1){
						dp[i].last_status = last_status;
						dp[i].days = prev_days + hw[j].cost;
						dp[i].present = j;
					}
				}
			}
		}
		vector<string> path = Get_Path(end-1);
		cout << dp[end-1].min_score << "\n";
		for(vector<string>::iterator p = path.begin(); p != path.end(); p++){
			cout << *p << "\n";
		}
	}
}
