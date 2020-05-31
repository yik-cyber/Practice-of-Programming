#include <bits/stdc++.h>
using namespace std;

char out[4][4];
struct Team{
    int point;
    int grade;
    bool operator<(Team b){
        if (point == b.point) return grade < b.grade;
        else return point > b.point;
    }
};
int ans = 10;

void dfs(Team t[], int g){
    if (g > 2){
        sort(t, t+4);
        for(int i = 3; i >= 0; i--){
            if (t[i].grade == 0) ans = min(ans, i+1); //mingci
        }
        return;
    }

    bool ok = false;
    for(int i = g+1; i < 4; i++){
        if (out[g][i] != '?') continue;
        ok = true;
        out[g][i] = 'W'; out[i][g] = 'L';
        t[g].point += 1;
        dfs(t, g+1);
        t[g].point -= 1;
        out[g][i] = '?'; out[i][g] = '?';

        out[g][i] = 'L'; out[i][g]  = 'W';
        t[i].point += 1;
        dfs(t, g+1);
        t[i].point -= 1;
        out[g][i] = '?'; out[i][g] = '?';
    }
    if (!ok) dfs(t, g+1);
    return;
}


int main(){
    char c;
    int n;
    cin >> n;
    while(n--){
        Team t[4];
        ans = 10;
        for(int i = 0; i < 4; i++){
            t[i].grade = i;
            t[i].point = 0;
            for(int j = 0; j < 4; j++){
                cin >> out[i][j];
                if (out[i][j] == 'W') t[i].point += 1;
            }
        }
        for(int i = 1; i < 4; i++){
            if (out[0][i] == '?'){
                out[0][i] = 'W';
                out[i][0] = 'L';
                t[0].point++;
            }
        }
        dfs(t, 1);
        cout << ans << "\n";
    }
}
