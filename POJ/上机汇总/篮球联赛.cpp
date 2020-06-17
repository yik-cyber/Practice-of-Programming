#include <bits/stdc++.h>
using namespace std;


char matchs[5][5];
unordered_map<int, int> grade;
int ans = 5;

void dfs(int g){
    if(g == 5){
        int sum = 0;
        for(int i = 2; i <= 4; i++){
            if(grade[i] > grade[1]) sum++;
        }
        ans = min(ans, sum+1);
        return;
    }
    bool check = false;
    for(int j = 1; j < g; j++){
        if(matchs[g][j] == '?'){
            check = true;
            matchs[g][j] = 'W';
            grade[g]++;
            dfs(g+1);
            grade[g]--;
            matchs[g][j] = '?';

            matchs[g][j] = 'L';
            grade[j]++;
            dfs(g+1);
            grade[j]--;
            matchs[g][j] = '?';
        }
    }
    if(!check) dfs(g+1);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        grade.clear();
        for(int i = 1; i <= 4; i++){
            grade.insert({i,0});
            for(int j = 1; j <= 4; j++){
                cin >> matchs[i][j];

                if(i>j){
                    grade[i] += (matchs[i][j]=='W'? 1:0);
                    grade[j] += (matchs[i][j]=='L'? 1:0);
                }
            }
        }

        for(int j = 2; j <= 4; j++){
            if(matchs[1][j] == '?'){
                matchs[1][j] = 'W';
                matchs[j][1] = 'L';
                grade[1]++; // 贪心
            }
        }
        ans = 5;
        dfs(2);
        printf("%d\n", ans);
    }
}
