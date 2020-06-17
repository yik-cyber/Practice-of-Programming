#include<bits/stdc++.h>
using namespace std;

int n;
struct HW{
    int p, d;
    bool operator<(HW b){
        if(d == b.d) return p < b.p;
        else return d < b.d;
    }
}hw[10010];
int f[10010];

int main(){
    cin >> n;
    HW tmp;
    tmp.p = tmp.d = 0;
    int maxd = 0;
    for(int i = 1; i <= n; i++){
        cin >> hw[i].p >> hw[i].d;
        maxd = max(maxd, hw[i].d);
    }
    sort(hw+1, hw+n+1);
    for(int i = maxd; i >= 1; i--){
        f[i] = f[i+1];
        for(int j = 1; j <= n; j++){
            if(hw[j].d >= i){
                f[i] = max(f[i+1]+hw[j].p, f[i]);
            }
        }
        for(int j = n; j>=1; j--){
            if(hw[j].d>=i && f[i] == f[i+1] + hw[j].p){
                hw[j] = tmp;
                break;
            }
        }
    }
    cout << f[1] << "\n";

}
