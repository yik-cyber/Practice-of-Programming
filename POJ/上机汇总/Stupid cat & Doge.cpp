#include<bits/stdc++.h>
using namespace std;

struct Point{
    long long x, y;
    Point(long long _x, long long _y):x(_x), y(_y){}
    Point(){}
};

Point cal(int n, long long num){
    if (n == 0) return Point(0,0);
    long long len = 1ll<<(n-1);
    long long m = 1ll<<(2*n-2);
    long long dis = num / m;
    long long next_num = num % m;
    Point p = cal(n-1, next_num);
    long long x = p.x, y = p.y;
    if(dis == 0) return Point(y, x);
    else if(dis == 1) return Point(x, y+len);
    else if(dis == 2) return Point(x + len, y + len);
    else if(dis == 3) return Point(2*len-y-1, len-x-1);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        long long cat, dog;
        cin >> n >> cat >> dog;
        Point catp = cal(n, cat-1);
        Point dogp = cal(n, dog-1);
        long long dx = catp.x-dogp.x, dy = catp.y-dogp.y;
        double out = sqrt(dx*dx + dy*dy)*10;
        long long res = floor(out+0.5);
        cout << res << "\n";
    }
    return 0;
}
