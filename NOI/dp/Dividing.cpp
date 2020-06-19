#include<bits/stdc++.h>
using namespace std;

int n[7];

int main(){
    int cases = 1;
    while (cin>>n[1]>>n[2]>>n[3]>>n[4]>>n[5]>>n[6]){
        if(n[1]==0 && n[2]==0 && n[3]==0 && n[4]==0 && n[5]==0 && n[6]==0) break;
        int sumv = 0, sumn = 0;
        for(int i = 1; i <= 6; i++){
            sumv += i * n[i];
            sumn += n[i];
        }
        int c[sumn+1];
        int cnt = 0;
        for(int i = 1; i <= 6; i++){
            int p = 1;
            while (n[i] - p > 0){
                n[i] -= p;
                c[cnt++] = p*i;
                p *= 2;
            }
            if(n[i] > 0) c[cnt++] = n[i]*i;
        }
        bool can_devide = false;
        if(sumv%2==0){
            int con = sumv/2;
            bool dp[con+1];
            memset(dp,false, sizeof(dp));
            dp[0] = true;
            for(int i = 0; i < cnt; i++){
                for(int j = con; j >= c[i]; j--){
                    if(!dp[j]) dp[j] = dp[j-c[i]];
                }
            }
            if(dp[con]) can_devide = true;
        }
        cout << "Collection #" << cases << ":" << "\n";
        if(can_devide){
            cout<< "Can be divided." << "\n";
        }
        else{
            cout << "Can't be divided." << "\n";
        }
        cout << "\n";
        cases++;
    }
}
