#include<bits/stdc++.h>
using namespace std;

struct  Rectangle{
    int x, y, w, h;
    Rectangle(int _x, int _y, int _w, int _h):x(_x), y(_y), w(_w), h(_h){}
    Rectangle(){}
}rec[10010];
int recn, R;

long long check(int mid){
    long long left_sum = 0, right_sum = 0;
    for(int i = 0; i < recn; i++){
        if (rec[i].x >= mid) right_sum += rec[i].w * rec[i].h;
        else if (rec[i].x + rec[i].w <= mid) left_sum += rec[i].w * rec[i].h;
        else{
            left_sum += (mid-rec[i].x)*rec[i].h;
            right_sum += (rec[i].x+rec[i].w-mid)*rec[i].h;
        }
    }
    return left_sum - right_sum;
}

int main(){
    scanf("%d", &R);
    scanf("%d", &recn);
    for(int i = 0; i < recn; i++){
        scanf("%d %d %d %d", &rec[i].x, &rec[i].y, &rec[i].w, &rec[i].h);
    }
    if(recn== 1 && rec[0].w == 1){
        printf("%d\n", R);
        return 0;
    }
    int l = 0, r = R, mid;
    while (l < r){
        mid = (l+r)/2;
        if(check(mid) > 0) r = mid;
        else if(check(mid) < 0) l = mid+1;
        else {r = mid; break;}
    }
    while(check(r)==check(r+1) && r < R) r++;
    printf("%d\n", r);
}
