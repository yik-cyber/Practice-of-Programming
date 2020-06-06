/*f[i][j]表示将字符串s1[1-i]通过增加/修改/删除到字符串s2[1-j]的所有方案的最小操作数*/

#include<bits/stdc++.h>
using namespace std;

int f[1010][1010];
int n;

int main(){
	cin >> n;
	while(n--){
		string s1, s2;
	    cin >> s1 >> s2;
	    int len1 = s1.size(), len2 = s2.size();
	    for(int i = 0; i <= len2; i++) f[0][i] = i;
	    for(int j = 0; j <= len1; j++) f[j][0] = j;
	    for(int i = 1; i <= len1; i++){
		    for(int j = 1; j <= len2; j++){
			    f[i][j] = f[i-1][j-1];
			    if(s1[i-1] != s2[j-1]){
				    f[i][j] = min(f[i][j], min(f[i-1][j], f[i][j-1]))+1;
			    }
		    }
	    }
	    cout << f[len1][len2] << "\n";
	}	
}
