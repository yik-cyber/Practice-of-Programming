#include<bits/stdc++.h>
using namespace std;

int share[101][101];
int get_share[101];
bool control[101];
int n;

void dfs(int x){
    for(int i = 1; i <= 100; i++){
        get_share[i] += share[x][i];
        if(get_share[i] > 50 && !control[i]){
            control[i] = true;
            dfs(i);
        }
    }
}


int main(){
    cin >> n;
    int ti, tj, tp;
    for(int i = 0; i < n; i++){
        cin >> ti >> tj >> tp;
        share[ti][tj] = tp;
    }

    for(int i = 1; i <= 100; i++){
        memset(get_share, 0, sizeof(get_share));
        memset(control, false, sizeof(control));
        control[i] = true;
        dfs(i);
        for(int j = 1; j <= 100; j++){
            if(i!=j && control[j]) cout << i  << " "<< j << "\n";
        }
    }
    return 0;

}

