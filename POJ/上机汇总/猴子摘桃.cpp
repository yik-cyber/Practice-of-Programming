#include <bits/stdc++.h>

using namespace std;

int h;
struct Tree{
    int p, b;
}t[110];
int ans;

int main(){
    while (cin >> h && h != -1){
        int n, m, cnt = 0;
        ans = 0;
        while (cin >> n >> m && n != -1 && m != -1){
            t[cnt].p = n; t[cnt++].b = m;
        }
        int honey, peach;
        for(int i = 0; i < cnt; i++){
            honey = h; peach = 0;
            for(int j = i; j < cnt; j++){
                if(honey>=t[j].b){
                    peach += t[j].p;
                    honey -= t[j].b;
                }
                else break;
            }
            ans = max(ans, peach);
        }
        cout << ans << "\n";
    }
}
