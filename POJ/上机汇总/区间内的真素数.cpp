#include<bits/stdc++.h>
#include<sstream>
using namespace std;

vector<int> primes;
vector<int> real_primes;
int n, m;

void get_primes(){
	primes.push_back(2);
	int j;
	bool is_prime;
	for(int i = 3; i <= 100000; i += 2){
		is_prime = true;
		int s = sqrt(i);
		for(j = 1;j < primes.size() && primes[j] <= s+1; j++){
			if (i % primes[j] == 0){
			    is_prime = false;
				break;
			}
		}
		if (is_prime) primes.push_back(i);
	}
}

int get_reverse(int n){
    int m = 0;
    while(n>0){
        m = m*10 + n%10;
        n /= 10;
    }
    return m;
}

void get_real_primes(){
	for(int i = n; i <= m; i++){
		if (i % 2 == 0) continue;
		int j = get_reverse(i);
		if (find(primes.begin(), primes.end(), i) != primes.end() && find(primes.begin(), primes.end(), j) != primes.end()){
			real_primes.push_back(i);
		}
	}
}

int main(){
	cin >> n >> m;
	get_primes();
	get_real_primes();
	if (real_primes.empty()) cout << "No";
	else{
	    cout << real_primes[0];
	    for(int j = 1; j < real_primes.size(); j++){
	        cout << "," << real_primes[j];
	    }
	}
}
