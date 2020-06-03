#include<bits/stdc++.h>
using namespace std;

char maze[110][110];
bool v[110][110][11];
int r, c, k;
struct Node{
    int x, y, t;
    Node(int _x, int _y, int _t):x(_x), y(_y), t(_t){
    }
    Node(){
    }
};
queue<Node> myque;

void add_node(int x, int y, Node p){
    if(x < 0 || x >= r || y < 0 || y >= c) return;
    p.x = x; p.y = y;
    if (maze[x][y] != '#' || p.t % k == 0){
        if (!v[x][y][p.t%k]){
            v[x][y][p.t%k] = true;
            myque.push(p);
        }
    }
    return;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        cin >> r >> c >> k;
        Node start;
        memset(v, false, sizeof(v));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> maze[i][j];
                if (maze[i][j] == 'S'){
                    start.x = i; start.y = j; start.t = 0;
                }
            }
        }
        myque.push(start);
        Node p;
        bool find = false;
        v[start.x][start.y][0] = true;
        while(!myque.empty()){
            p = myque.front();
            myque.pop();

            if(maze[p.x][p.y] == 'E'){
                cout << p.t << "\n";
                find = true;
                break;
            }

            p.t++;
            add_node(p.x-1, p.y, p);
            add_node(p.x, p.y-1, p);
            add_node(p.x+1, p.y, p);
            add_node(p.x, p.y+1, p);
        }
        if(!find) cout << "Oop!" << "\n";
        myque = queue<Node>();
    }
}
