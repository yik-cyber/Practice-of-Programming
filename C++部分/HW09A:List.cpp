#include <iostream>
#include <map>
#include <list>
using namespace std;

typedef map<int, list<int> > LIST_MAP;

int main(){
    int test; cin >> test;
    LIST_MAP mp;
    string cmd;
    while (test--){
        cin >> cmd;
        if (cmd == "new"){
            int id; cin >> id;
            mp.insert(make_pair(id, list<int>()));
        }
        else if (cmd == "add"){
            int id, n; cin >> id >> n;
            mp[id].push_back(n);
            mp[id].sort(); //???
        }
        else if (cmd == "merge"){
            int id1, id2; cin >> id1 >> id2;
            mp[id1].merge(mp[id2]);
        }
        else if (cmd == "unique"){
            int id; cin >> id;
            mp[id].unique();
        }
        else if (cmd == "out"){
            int id; cin >> id;
            list<int>& id_list = mp[id];
            if (id_list.empty()) cout << endl;
            else {
                id_list.sort();
                list<int>::iterator p = id_list.begin();
                for(; p!=id_list.end(); ++p){
                    cout << *p << " "  ;
                }
                cout << endl;
            }
        }
    }
}
