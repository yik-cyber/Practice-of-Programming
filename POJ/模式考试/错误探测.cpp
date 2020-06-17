#include <bits/stdc++.h>
using namespace std;

int num[110][110];
int a[110], b[110];
int n;
int main(){
    while(cin >> n){
        memset(num, 0, sizeof(num));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> num[i][j];
                if(num[i][j] == 1) {
                    a[i]++;
                    b[j]++;
                }
            }
        }
        bool is_ok = true, is_out = false;
        for(int i = 0; i < n; i++){
            if(a[i]%2 || b[i]%2) is_ok = false;
        }
        int cnt = 0, x, y;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i]%2 && b[j]%2) {
                    cnt++;
                    x = i+1; y = j+1;
                }
            }
        }
        if(cnt == 1) is_out = true;
        if (is_ok) cout << "OK" << "\n";
        else if(is_out) cout << x << " " << y << "\n";
        else cout << "Corrupt" << "\n";

    }
}
