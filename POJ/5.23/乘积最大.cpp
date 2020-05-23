/*类似于加法表达式的DP，注意一下判断条件就可以了*/

#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, k;
    cin >> n >> k;
    string num;
    cin >> num;
    int f[k+10][n+10];
    int number[n+10][n+10];
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            number[i][j] = atoi(num.substr(i-1, j-i+1).c_str());
        }
    }
    for(int i = 1; i <= n; i++){
        f[0][i] = number[1][i];
    }
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++){
            if (i > j - 1) f[i][j] = 0;// nonsense
            else{
                f[i][j] = 0;
                for(int t = j; t > 0 && t >= i; t--){
                    f[i][j] = max(f[i][j], f[i-1][t] * number[t+1][j]);
                }
            }
        }
    }
    cout << f[k][n] << "\n";
}
