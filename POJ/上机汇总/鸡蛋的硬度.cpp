/*f[i][j]表示有i层楼j个鸡蛋在最坏情况下的最少扔鸡蛋次数。我们可以选择从1-i层楼扔鸡蛋，f[i][j] = min(在1-i扔鸡蛋最坏情况下的最少次数)
  再考虑在具体的某一k层扔鸡蛋，鸡蛋要么碎掉，要么不碎，如果碎掉需要继续在1-k-1层扔鸡蛋，即为f[k-1][j-1]+1，如果没碎，需要在k+1-i扔鸡蛋，这种情况
  等价于f[i-k][j]+1，我们无法控制鸡蛋是否摔碎，所以取二者中最大的，代表最坏情况。
  最后f[i][j] = min (k = 1...i max(f[k-1][j-1], f[i-k][j])+1 )
  初始化就是f[i][j] = i，最坏最坏的情况，每一层都要扔
*/


#include<bits/stdc++.h>
using namespace std;

int n, t, ans;
int f[110][15];

int main(){
	while(cin >> n >> t){

		for(int i = 1; i <= n; i++){
			f[i][1] = i;
			for(int j = 2; j <= t; j++){
				f[i][j] = i;
				for(int k = 1; k <= i; k++){
					f[i][j] = min(max(f[k-1][j-1], f[i-k][j])+1, f[i][j]);
				}
			}
		}
		cout << f[n][t] << "\n";
	}
}
