#include <bits/stdc++.h>
using namespace std;

char box[900][900];

void fenxing(int n, int len, int x, int y){
	if(n == 1){
	    box[x][y] = 'X';
		return;	
	} 
	
	int l = len / 3;
	fenxing(n-1, l, x, y);
	fenxing(n-1, l, x+l, y+l);
	fenxing(n-1, l, x+2*l, y);
	fenxing(n-1, l, x, y+2*l);
	fenxing(n-1, l, x+2*l, y+2*l);
}

int main(){
	int n;
	while(cin >> n && n > 0){
		int len = pow(3, n-1);
		memset(box, ' ', sizeof(box));
		fenxing(n, len, 0, 0);
		for(int i = 0; i < len; i++){
			for(int j = 0; j < len; j++){
				cout << box[i][j];
			}
			cout<<"\n";
		}
		cout<<"-"<<"\n";
	}
}
