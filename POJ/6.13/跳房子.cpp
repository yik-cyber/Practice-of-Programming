#include<bits/stdc++.h>
using namespace std;

int n, m;
int ans;
vector<char> path, tpath;

void dfs(int x){
    if (tpath.size() > ans) return;
    if (x == m){
        if (path.empty() || tpath.size() < ans){
            path = tpath;
            ans = tpath.size();
        }
        else if (tpath < path){
            path = tpath;
            ans = tpath.size();
        }
        return;
    }


    tpath.push_back('H');
    dfs(3*x);
    tpath.pop_back();

    tpath.push_back('O');
    dfs(floor(x/2));
    tpath.pop_back();
}

int main(){
    while(cin >> n >> m && n != 0 && m != 0){
        tpath.clear(); path.clear();
        ans = 26;
        dfs(n);
        cout << ans << "\n";
        for(auto p = path.begin(); p != path.end(); p++){
            cout << *p;
        }
        cout << "\n";
    }
}
