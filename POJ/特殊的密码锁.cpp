#include <iostream>
using namespace std;
int op;
int MIN_OP = 31;
int len;
void SetBit(int& n, int i, int v){
    if(v){
        n |= (1<<i);
    }
    else
        n &= ~(1<<i);
}

bool GetBit(int n, int i){
    return (n>>i)&1;
}

void FlipBit(int& n, int i){
    n ^= (1<<i);
}

bool cmp(int n, int m, int i){
    return ((n>>i)&1)==((m>>i)&1); //相同位数字是否相等
}


int main() {
    int now = 0; int taget = 0;
    string now_c, tag_c;
    cin >> now_c >> tag_c;
    len = now_c.length();
    for(int i = 0; i < len; i++){
        SetBit(now, i, int(now_c[i])-'0');
        SetBit(taget, i, int(tag_c[i])-'0');
    }
    for(int n = 0; n < 2; n++){
        op = 0;
        int tmp = now;
        if (n){ //按了第一个
            FlipBit(tmp, 0);
            FlipBit(tmp, 1);
            op++;
        }
        for(int i = 1; i < len; ++i){
            if (!cmp(tmp,taget,i-1)){
                op++;
                FlipBit(tmp, i);
                if (i > 0) FlipBit(tmp, i-1);
                if (i < len - 1) FlipBit(tmp, i+1);
            }
        }
        if (tmp == taget && op < MIN_OP) MIN_OP = op;
    }
    if (MIN_OP == 31) cout <<"impossible";
    else cout << MIN_OP;
}
