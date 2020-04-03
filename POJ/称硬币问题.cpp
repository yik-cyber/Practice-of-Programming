#include <iostream>
#include <cstring>
using namespace std;
string weigh[3][3];
bool judge(char c, bool light){
    bool is_fake = true;
    for(int i = 0; i < 3; ++i){
        if (weigh[i][0].find(c) != weigh[i][0].npos)
            is_fake = light ? "down" == weigh[i][2]: "up" == weigh[i][2] ;
        else if (weigh[i][1].find(c) != weigh[i][1].npos)
            is_fake = light ? "up" == weigh[i][2]: "down" == weigh[i][2] ;
        else
            is_fake = "even" == weigh[i][2];
        if (!is_fake) return false;
    }
    return is_fake;
}
int main() {
    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i < 3; ++i){
            for (int j = 0; j < 3; ++j)
                cin >> weigh[i][j];
        }
        for(auto c = 'A'; c <= 'L'; ++c){
            if (judge(c, true)){
                cout <<c<<" is the counterfeit coin and it is light.\n";
                break;
            }
            else if (judge(c, false)){
                cout << c<<" is the counterfeit coin and it is heavy.\n";
                break;
            }
        }
    }
    return 0;
}
