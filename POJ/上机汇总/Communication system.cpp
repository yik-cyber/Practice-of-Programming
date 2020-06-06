/*枚举，因为b是所有选中设备中带宽最小的，所以枚举b，然后贪心，每次每个满足要求的设备选择价格最小的*/
#include<bits/stdc++.h>
using namespace std;

struct Device{
	int bw;
	int pr;
}dev[110][110];
int num[110];
int t, n, m, b, p;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int minb = 2e8, maxb = 0;
		for(int i = 1; i <= n; i++){
			scanf("%d", &num[i]);
			for(int j = 1; j <= num[i]; j++){
				scanf("%d %d", &dev[i][j].bw, &dev[i][j].pr);
				minb = min(minb, dev[i][j].bw);
				maxb = max(maxb, dev[i][j].bw);
			}
		}
		double ans = 0;
		for(b = minb; b <= maxb; b++){
			int sump = 0;
			for(int i = 1; i <= n; i++){
				int minc = 2e8;
				for(int j = 1; j <= num[i]; j++){
					if (dev[i][j].bw >= b){
						minc = min(minc, dev[i][j].pr);
					}
				}
				sump += minc;
			}		
			ans = max(ans, 1.0*b/sump);
		}
		printf("%.3f\n", ans);
	}
}
