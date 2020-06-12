#include<bits/stdc++.h>
using namespace std;

int book[210];
int friends[210];

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> book[i];
		friends[book[i]]++;
	}
	for(int i = 1; i <= n; i++){
		if (friends[book[i]] > 1){
			cout << friends[book[i]]-1 << "\n";
		}
		else cout << "BeiJu" << "\n";
	}
}
