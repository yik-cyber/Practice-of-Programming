#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		int len = s.size();
		int zero[len+1], one[len+1];
		zero[0] = one[0] = 0;
		bool is_one = false;
		for(int i = 1; i <= len; i++){
			if (s[i-1] == '1') is_one = true;
			else is_one = false;
			zero[i] = zero[i-1] + (is_one? 0:1);
			one[i] = one[i-1] + (is_one? 1:0);
		}
		int ans = 0x3f3f3f3f;
		if (one[len] == 0) ans = 0; //这里其实不用单独列出，不过列出了可以节省时间（）
		else{
			for(int i = 1; i <= len; i++){
				ans = min(ans, one[i] + zero[len] - zero[i]);
			}
		}
		cout << ans << "\n";
	}
}
