#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 15;
int canvas[MAXN];
int tmp_canvas[MAXN];
int canvas_size;
int op = 0; //记录操作数
int MIN_OP = 300;

void Set_Bit(int& n,int j, int v){ //设置
    if (v){
        n |= (1<<j);
    }
    else {
        n &= ~(1<<j);
    }
}

bool Get_Bit(int n, int j){
    return (n>>j)&1;
}

void Flip_Bit(int& n, int j){ //反转
    n ^= (1<<j);
}

int record(int n){
    for(auto i = 0; i < canvas_size; ++i) {
        if ((n >> i) & 1) op++;
    }
}

int main() {
    cin >> canvas_size;
    char c;
    for(auto i = 0; i < canvas_size; ++i){
        for(auto j = 0; j < canvas_size; ++j){
            cin >> c;
            if (c == 'w') Set_Bit(canvas[i], j, 1);
            else Set_Bit(canvas[i], j, 0);
        }
    }
    int all = 1 << canvas_size;
    for(auto n = 0; n < all; ++n){ //第一行的所有可能
        op = 0;
        memcpy(tmp_canvas, canvas, sizeof(canvas));
        int paint = n; //当前第一行方案
        for(auto i = 0; i < canvas_size; ++i){ //为什么这里要....
            record(paint); //记录操作数
            for(auto j = 0; j < canvas_size; ++j){
                if (Get_Bit(paint, j)){
                    Flip_Bit(tmp_canvas[i], j);
                    if (j > 0) Flip_Bit(tmp_canvas[i], j-1);
                    if (j < canvas_size - 1) Flip_Bit(tmp_canvas[i], j+1);
                }
            }
            if (i < canvas_size - 1) tmp_canvas[i+1] ^= paint;
            paint = tmp_canvas[i];
        }
        if (tmp_canvas[canvas_size-1] == 0 && op < MIN_OP) MIN_OP = op;
    }
    if (MIN_OP == 300) cout << "inf\n";
    else cout << MIN_OP<<"\n";
}
