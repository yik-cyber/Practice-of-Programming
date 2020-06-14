#include<bits/stdc++.h>
using namespace std;

int v[16], s[16];
bool status[16];
int tot_s, ans;
vector<int> before, after;

void dfs(int x, int value, int mental){
    if (mental < 0) return; //注意这里的判断顺序233
    if (x == 16){
        if(before.size() <= after.size()) ans = max(ans, value);
        return;
    }
    

    if(x <= 10){
        before.push_back(x);
        dfs(x+1, value+v[x], mental-s[x]);
        before.pop_back();
    } else{
        after.push_back(x);
        dfs(x+1, value+v[x], mental-s[x]);
        after.pop_back();
    }
    dfs(x+1, value, mental);
}

int main(){
    memset(status, false, sizeof(status));
    scanf("%d", &tot_s);
    for(int i = 1; i <= 15; i++) scanf("%d %d", &v[i], &s[i]);
    dfs(1, 0, tot_s);
    printf("%d", ans);
}
