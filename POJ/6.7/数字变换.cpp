/*参考了一下大佬的代码后终于过了*/

#include<bits/stdc++.h>
#include <sstream>
using namespace std;

int status[100000][4][3];
int out = 2e8;
struct Node{
	int n,add, mul, ops;
	Node(int _n, int _add, int _mul, int _ops):n(_n), add(_add), mul(_mul), ops(_ops){
	}
	Node(){
	}
};

int trans(int* s){
    int x = 0;
    for(int i = 4; i >= 0; i--){
        x += s[i] * pow(10, i);
    }
    return x;
}

int main(){
    memset(status, -1, sizeof(status));
	int n;
	queue<Node> myque;
	myque.push(Node(12345,0,0,0));
	Node p;
	int s1[10], s2[10];
	int t;
	while(!myque.empty()){
	    p = myque.front();
	    myque.pop();

	    if (status[p.n][p.add][p.mul] != -1) continue;
	    status[p.n][p.add][p.mul] = p.ops;

	    int pn = p.n;
	    for(int i = 0; i < 5; i++){
	        s1[i] = pn % 10;
	        pn /= 10;
	    }

	    for(int i = 0; i < 4; i++){
	        memcpy(s2, s1, sizeof(s1));
	        swap(s2[i], s2[i+1]);
	        t = trans(s2);
	        myque.push(Node(t,  p.add, p.mul, p.ops+1));
	    }
	    if (p.add < 3){
            for(int i = 0; i < 5; i++){
                memcpy(s2, s1, sizeof(s1));
                s2[i] = (s2[i]+1)%10;
                t = trans(s2);
                myque.push(Node(t,  p.add+1, p.mul, p.ops+1));
            }
	    }
	    if (p.mul < 2){
	        for(int i = 0; i < 5; i++){
	            memcpy(s2, s1, sizeof(s1));
	            s2[i] = (2*s2[i])%10;
	            t = trans(s2);
	            myque.push(Node(t, p.add, p.mul+1, p.ops+1));
	        }
	    }
	}
	status[12345][0][0] = 0;
	while(cin >> n){
	    out = 2e8;
        for (int i = 0; i <= 3; ++i) {
            for (int j = 0; j <= 2; ++j) {
                if (status[n][i][j] != -1)
                    out = min(out, status[n][i][j]);
            }
        }
	    if(out != 2e8) cout << out << "\n";
	    else cout << -1 << "\n";
	}
}
