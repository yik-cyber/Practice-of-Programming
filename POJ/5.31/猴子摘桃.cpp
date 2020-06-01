#include <bits/stdc++.h>
using namespace std;

struct Tree{
    int peach;
    int bee;
}tree[110];
int main(){
    int n;
    while(cin >> n){
        if (n == -1) break;
        int honey = n;
        int x, y, cnt = 0;
        while (cin >> x >> y && x > -1 && y > -1){
            tree[cnt].peach = x;
            tree[cnt].bee = y;
            cnt++;
        }
        int ans = 0;
        int p;
        for(int i = 0; i < cnt; i++){
            p = 0;int j; honey = n;
            for(j = i; j < cnt; j++){
                if(honey - tree[j].bee >= 0){
                  p += tree[j].peach;
                  honey -= tree[j].bee;
                }
                else{
                    ans = max(ans, p);
                }
            }
            if (honey >= 0 && j == cnt){
                ans = max(ans, p);
            }
        }
        cout << ans <<"\n";
    }
}
