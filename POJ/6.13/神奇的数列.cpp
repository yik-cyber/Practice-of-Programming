#include<bits/stdc++.h>
using namespace std;

int num[210];
int sum[210][210];
int n;

int main(){
    int t;
    cin >> t;
    int cnt = 1;
    while(t--){
        cin >> n;
        memset(sum, 1, sizeof(sum));
        for(int i = 1; i <= n; i++){
            cin >> num[i];
            sum[i][i] = 1;
            for(int j = 1; j < i; j++) sum[i][j] = 0;
            if(i-1>=0){
                if(num[i-1] == num[i]) sum[i-1][i] = 1;
                else sum[i-1][i] = 2;
            }
        }

        for(int i = n-1; i > 0; i--){
            for(int j = i + 1; j <= n; j++){
                for(int k = 1; k < j; k++){
                    if (num[k] == num[j]){
                        sum[i][j] = min(sum[i][j], sum[i][k]+sum[k+1][j-1]);
                    }
                    else sum[i][j] = min(sum[i][j], sum[i][k]+sum[k+1][j]);
                }
            }
        }
        cout << "Case " << cnt << ": " << sum[1][n] << "\n";
        cnt++;
    }
}
