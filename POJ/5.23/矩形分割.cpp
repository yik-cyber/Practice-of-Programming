/*哈皮二分，注意一下数据用long long还有特殊情况，因为数据被卡了好久orz（我太菜啦*/


#include <bits/stdc++.h>
using namespace std;

struct rect{
    int l, t, w, h;
}rects[10010];
int R, N;

long long check(int mid){
    long long lefts = 0, rights = 0;
    rect rec;
    for(int i = 0; i < N; i++){
        rec = rects[i];
        if (rec.l + rec.w <= mid) lefts += rec.w * rec.h;
        else if (rec.l >= mid) rights += rec.w * rec.h;
        else{
            lefts += (mid - rec.l) * rec.h;
            rights += (rec.l + rec.w - mid) * rec.h;
        }
    }
    return lefts - rights;
}

int main(){
    scanf("%d", &R);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d %d %d", &rects[i].l, &rects[i].t, &rects[i].w, &rects[i].h);
    }
    if(N == 1 && rects[0].w == 1){
        printf("%d\n", R);
        return 0;
    }
    int l = 0, r = R;
    while(l < r){
        int mid = (l+r)>>1;
        if(check(mid) > 0) r = mid;
        else if (check(mid) < 0) l = mid + 1;
        else {r = mid; break;}
    }
    while(check(r) == check(r+1) && r < R) r++;
    printf("%d\n", r);
}
