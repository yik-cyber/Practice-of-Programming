#include <map>
#include <cstdio>
using namespace std;


int main(){
    map<int, int> members;
    int n;
    scanf("%d", &n);
    members.insert(make_pair(1000000000, 1));
    int id, attack;
    while(n--){
        scanf("%d %d", &id, &attack);
        members.insert(make_pair(attack, id));
        map<int,int>::iterator p1 = members.lower_bound(attack);
        map<int,int>::iterator p2 = members.upper_bound(attack);
        if(p1 == members.begin()){
            printf("%d %d\n", id, p2->second);
        }
        else{
            p1--;
            int before = abs(attack - p1->first);
            int after = abs(attack - p2->first);
            int id2;
            if(before <= after) id2 = p1->second;
            else if(before > after) id2 = p2->second;
            printf("%d %d\n", id, id2);
        }
    }
}
