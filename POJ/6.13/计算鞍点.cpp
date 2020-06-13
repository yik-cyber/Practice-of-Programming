#include<bits/stdc++.h>
using namespace std;

int maze[6][6];
struct Point{
    int y, v;
}c_max[6];

int main(){
    for(int i = 1; i <= 5; i++){
        c_max[i].v = -2e8;
        for(int j = 1; j <= 5; j++){
            cin >> maze[i][j];
            if (maze[i][j] > c_max[i].v){
                c_max[i].v = maze[i][j];
                c_max[i].y = j;
            }
        }
    }
    bool found = false;
    for (int i = 1; i <= 5; i++){
        int line = c_max[i].y;
        int j;
        for(j = 1; j <= 5; j++){
            if (maze[j][line] < c_max[i].v) break;
        }
        if (j == 6){
            found = true;
            cout << i << " " << line << " " << c_max[i].v << "\n";
        }
    }
    if (!found) cout << "not found" << "\n";
}
