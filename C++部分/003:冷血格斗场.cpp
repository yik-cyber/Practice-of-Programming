#include <map>
#include <cstdio>
using namespace std;


int main(){
    map<int, int> members;
    int n;
    int id, attack, id2;
    members.insert(make_pair(1000000000, 1));
    scanf("%d", &n);
    while(n--){
        scanf("%d %d", &id, &attack);
        map<int,int>::iterator p2 = members.upper_bound(attack);
        map<int,int>::iterator p1 = p2;
        p1--;

        if(p2 == members.begin()) id2 = p2->second;
        else if(p1->first == attack) id2 = p1->second;
        else{
            int b = abs(p1->first - attack);
            int a = abs(p2->first - attack);
            if(b < a) id2 = p1->second;
            else if(b > a) id2 = p2->second;
            else id2 = min(p1->second, p2->second);
        }


        printf("%d %d\n",id, id2);
        map<int,int>::iterator t = members.find(attack);
        if(t == members.end()) members.insert(make_pair(attack, id));
        else if(t->second > id) t->second = id;
    }
}
