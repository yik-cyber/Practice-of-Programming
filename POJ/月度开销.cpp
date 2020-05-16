/*这题有点哈皮，最开始一直TLE，也不知道为什么，可能是用了max函数的原因，总之挺无理的
  后面看了大佬的答案，才知道原来还有valarray这个数据结构，记下了，谢谢大佬
  题目本身就是一个很常规的二分，找合法下届的问题
*/
#include<cstdio>
#include<valarray>
using namespace std;

valarray<int> money;
int N, M, tot;

bool check(int maxm){
	int sum = money[0];
	int cnt = 1;
	for(int i = 1; i < N; ++i){
		if(sum + money[i] > maxm){
			cnt++;
			sum = money[i];
		}
		else sum += money[i];
	}
	return cnt <= M;
}

int main(){
	scanf("%d %d", &N, &M);
	money.resize(N);
	int maxn = 0;
	tot = 0;
	for(int i = 0; i < N; ++i){
		scanf("%d", &money[i]);
	}
	int l = money.max(), r = 2e8;
	while(l < r){
		int mid = (l+r)>>1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", r);
	return 0;
}
