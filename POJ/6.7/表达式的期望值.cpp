/*因为是位运算。所以每次运算位是独立的，只需要计算每一位的期望值，再总和位表达式的期望值
  已知前j-1个操作&数的期望值为E[j-1]，我们要计算前j个操作&数字的期望值，将前j-1个看作是值为E[j-1]的数（因为是期望值所以可以直接替代）
  然后E[j] = prob[j]*E[j-1](消失的情况) + (1-prob[j]) * tE(没有消失的情况)
  tE有三种情况分别为O[J]为|, &, ^， 根据A[j]第i位的值而定，这个计算就比较简单，代码里有
*/


  #include<bits/stdc++.h>
using namespace std;

int A[210];
char O[210];
double prob[210];
double ans;
int cnt;

int main(){
	int n;
	cnt = 1;
	while(cin >> n){
		for(int i = 0; i <= n; i++) cin >> A[i];
		for(int i = 1; i <= n; i++) cin >> O[i];
		for(int i = 1; i <= n; i++) cin >> prob[i];
		
		ans = 0;
		for(int i = 0; i <= 20; i++){
			double E = (A[0]>>i) & 1; //initial E for i-th
			for(int j = 1; j <= n; j++){
				double tE;
				if (O[j] == '|'){
					tE = (1-prob[j]) * ((A[j]>>i)&1? 1:E);
				}
				else if (O[j] == '&'){
					tE = (1-prob[j]) * ((A[j]>>i)&1? E:0);
				}
				else if (O[j] == '^'){
					tE = (1-prob[j]) * ((A[j]>>i)&1? 1-E:E);
				}
				E = prob[j]*E + tE;
			}
			ans += double(1<<i)*E;
		}
		printf("Case %d:\n%.6f\n", cnt, ans);
		cnt++;
	}
}
