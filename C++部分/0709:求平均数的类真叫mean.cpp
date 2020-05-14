#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class CMean {

public:
    int sum;
    int cnt;
    int& target;
    CMean(int& t):target(t){sum = 0; cnt=0;}
    int& operator()(int x){
        sum += x;
        cnt++;
        target = sum / cnt;
        return target;
    }

};

int main(int argc, char* argv[]) {
    int  v;
    int t;
    cin >> t;
    while ( t -- ) {
        cin >> v;
        vector<int> vec;
        while (v) {
            vec.push_back(v);
            cin >> v;
        }
        int myAver = 0;
        for_each(vec.begin(), vec.end(), CMean(myAver));
        cout << myAver << endl;
    }
    return 0;
}
