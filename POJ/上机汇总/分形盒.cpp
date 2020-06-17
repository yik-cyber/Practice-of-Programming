#include <bits/stdc++.h>
using namespace std;

char box[800][800];
int m;

void fx(int x, int y, int n){
    if(n == 1){
        box[x][y] = 'X';
        return;
    }
    int len = pow(3, n-2);
    fx(x, y, n-1);
    fx(x+len, y+len, n-1);
    fx(x, y+2*len, n-1);
    fx(x+2*len, y, n-1);
    fx(x+2*len, y+2*len, n-1);
}

int main(){
    while (cin >> m && m != -1){
        memset(box, ' ', sizeof(box));
        int len = pow(3, m-1);
        fx(0,0,m);
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                cout << box[i][j];
            }
            cout << "\n";
        }
        cout << "-" << "\n";
    }
}
