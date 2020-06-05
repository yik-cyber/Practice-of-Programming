#include <bits/stdc++.h>
using namespace std;
int a, b , n, u, d;
int gcd(int x, int y){
    int z = x % y;
    while(z > 0){
        x = y;
        y = z;
        z = x % y;
    }
    return y;
}

int main(){
    cin >>  n>>a >> b ;
    d = 1000;
    u = 1;
    for(int i = n; i > 0; i--){
        for(int j = i-1; j > 0; j--){
            if (j*b < i*a && j*d > i*u){
                u = j;
                d = i;
            }
        }
    }
    int g = gcd(d, u);
    cout << u/g <<" "<<d/g;
}
