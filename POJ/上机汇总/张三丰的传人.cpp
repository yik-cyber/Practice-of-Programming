#include<bits/stdc++.h>
using namespace std;

vector<int> deco;
bool ok;
int m;

void dfs(double sum, int remain, int now){
    if (ok) return;
    if (fabs(sum-1) < 1e-6 && remain == 0){
        ok = true;
        cout << deco.size();
        for(int & p : deco){
            cout << " " << p ;
        }
        cout << "\n";
        return;
    }
    if (sum >= 1) return;
    if (remain <= 0) return;
    for(int i = now; i <= remain && !ok; i++){
        if (sum + 1.0/i - 1 > 1e-6) continue;
        deco.push_back(i);
        dfs(sum + 1.0/i, remain-i, i);
        if (ok) break;
        deco.pop_back();
    }
}
int main(){
    int n;
    cin >> n;
    while(n--){
        ok = false;
        cin >> m;
        dfs(0, m, 1);
        deco.clear();
        if (!ok) cout << -1 << "\n";
    }
}
