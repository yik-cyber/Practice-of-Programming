#include<bits/stdc++.h>
using namespace std;

long long f[5843];
int main(){
    f[1] = 1;
    int f1 = 1, f2 = 1, f3 = 1, f4 = 1;
    for (int i = 2; i < 5843; ++i) {
        f[i] = min(min(min(f[f1]*2, f[f2]*3), f[f3]*5), f[f4]*7);
        if(f[i] == f[f1]*2) f1++;
        if(f[i] == f[f2]*3) f2++;
        if(f[i] == f[f3]*5) f3++;
        if(f[i] == f[f4]*7) f4++;
    }
    int n;
    while (cin >> n && n > 0){
        if(n%100 !=  11 && n%10 == 1){
            cout << "The " << n << "st humble number is " << f[n] <<".\n";
        }
        else if(n%100 != 12 && n%10 == 2){
            cout << "The " << n << "nd humble number is " << f[n] <<".\n";
        }
        else if(n%100 != 13 && n%10 == 3){
            cout << "The " << n << "rd humble number is " << f[n] << ".\n";
        }
        else{
            cout << "The " << n << "th humble number is " << f[n] << ".\n";
        }
    }
    return 0;
}
