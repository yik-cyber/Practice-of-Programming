/*注意一下判重的条件*/

#include<bits/stdc++.h>
using namespace std;

char maze[110][110];
bool v[110][110][64][10];
struct Point{
    int x, y, key, t, s; // the most big key number
    Point(int _x, int _y, int _k, int _t, int _s):x(_x), y(_y), key(_k), t(_t), s(_s){
    }
    Point(){
    }
};
int n, m, sn;
queue<Point> myque;

void add_point(int x, int y, Point prev){
    if (x < 0 || x >= n || y < 0 || y >= n) return;
    if (maze[x][y] == '#') return;
    Point now = prev;
    now.x = x; now.y = y;
    now.t++;
    int tmp = maze[x][y] - '0';
    if (tmp > 0 && tmp <= m){
        if(now.key == tmp-1) now.key++;
    }
    int snake = maze[x][y] - 'A';
    if (snake >= 0 && snake < sn){
        int ts = (1<<snake);
        if(!(prev.s & ts)){
            now.t++;
            now.s += ts;
        }
    }
    if(!v[x][y][now.s][now.key]){
        v[x][y][now.s][now.key] = true;
        myque.push(now);
    }
}

int main(){
    while(cin >> n >> m){
        if (n == 0 && m == 0) return 0;
        memset(v, false, sizeof(v));
        Point sun;
        sn = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> maze[i][j];
                if (maze[i][j] == 'K'){
                    sun.x = i; sun.y = j;
                    sun.key  = sun.t = 0; sun.s = 0;
                }
                if (maze[i][j] == 'S'){
                    maze[i][j] = 'A' + sn;
                    sn++;
                }
            }
        }
        myque.push(sun);
        int ans = 0x3f3f3f3f;
        bool succeed = false;
        while(!myque.empty()){
            Point p = myque.front();
            myque.pop();
            if (maze[p.x][p.y] == 'T' && p.key == m){
                ans = p.t;
                succeed = true;
                break;
            }
            add_point (p.x+1, p.y, p);
            add_point (p.x, p.y+1, p);
            add_point (p.x-1, p.y, p);
            add_point (p.x, p.y-1, p);
        }
        if (!succeed) cout << "impossible" << "\n";
        else cout << ans << "\n";
        myque = queue<Point>();
    }
}
