#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

int count_prime(int n){
    int cnt = 0;
    int t = n;
    for(int i = 2; i <= t/2; i++){
        if(n%i == 0){
            cnt++;
            while(n%i == 0) n/= i;
        }
    }
    return cnt;
}
int count[10000000];

template<class T>
class myless{
public:
    bool operator()(int a, int b){
        if(count[a] == -1) count[a] = count_prime(a);
        if(count[b] == -1) count[b] = count_prime(b);
        if (count[a] == count[b]) return a > b;
        else return count[a] > count[b];
    }
};
template<class T>
class mybig{
public:
    bool operator()(int a, int b){
        if(count[a] == -1) count[a] = count_prime(a);
        if(count[b] == -1) count[b] = count_prime(b);
        if (count[a] == count[b]) return a < b;
        else return count[a] < count[b];
    }
};

int main(){
    int t;
    scanf("%d", &t);
    priority_queue<int,vector<int>, myless<int> > pq1;
    priority_queue<int,vector<int>, mybig<int> > pq2;
    memset(count, -1, sizeof(count));
    while(t--){
        int x;
        for(int i = 0; i < 10; ++i) {
            scanf("%d", &x);
            pq1.push(x);
            pq2.push(x);
        }
        printf("%d %d\n", pq2.top(), pq1.top());
        pq1.pop();
        pq2.pop();
    }
}
