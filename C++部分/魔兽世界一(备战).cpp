#include <iostream>
#include <iomanip>
using namespace std;

const char wa_race[5][10] = {"dragon", "ninja", "iceman", "lion", "wolf"};
int wa_life[5];
const string camps[2] = {"red", "blue"};
int min_life;

void c_m_l(){
    int min = 20000;
    for (int i = 0; i < 5; ++i) {
        if (wa_life[i] < min) min = wa_life[i];
    }
    min_life = min;
}

class headquarter{
public:
    int camp;
    int life;
    int stop = 0;
    int total_warrios = 0;
    int warrios[5] = {0,0,0,0,0};
    int seq[2][5] = {{2,3,4,1,0}, {3,0,1,2,4}};
    int now = 0;

    headquarter(int n, int M):camp(n), life(M){}
    void Produce(int time);
};
void headquarter::Produce(int time){
    if (stop) return;
    if (life < min_life){
        stop = 1;
        cout << setfill('0') << setw(3) << time;
        cout << " " << camps[camp] << " " << "headquarter stops making warriors"<<endl;
        return;
    }
    while (now>= 5 || life < wa_life[seq[camp][now]]){
        now++;
        if (now >= 5) now = 0;
    }
    warrios[seq[camp][now]]++;
    total_warrios++;
    life -= wa_life[seq[camp][now]];
    cout << setfill('0') << setw(3) << time;
    cout<<" "<<camps[camp]<<" "<<wa_race[seq[camp][now]]<<" "<< total_warrios<<" "<<"born with strength "<<wa_life[seq[camp][now]]
        <<","<<warrios[seq[camp][now]]<<" "<<wa_race[seq[camp][now]]<<" in "<<camps[camp]<<" headquarter"<<endl;
    now++;
}


int main(){
    int test;
    cin >> test;
    for (int i = 1; i <= test ; i++) {
        int M;
        cin >> M;
        for (int j = 0; j < 5; j++) cin >> wa_life[j];
        c_m_l();
        headquarter red(0, M);
        headquarter blue(1, M);
        int time = 0;
        cout << "Case:" << i <<  endl;
        while (!red.stop || !blue.stop){
            red.Produce(time);
            blue.Produce(time);
            time++;
        }
    }
}
