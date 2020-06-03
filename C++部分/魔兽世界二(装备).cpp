#include <iostream>
#include <iomanip>
using namespace std;

const string wa_race[5] = {"dragon", "ninja", "iceman", "lion", "wolf"};
const string wa_arms[3] = {"sword", "bomb", "arrow"};
int wa_life[5];
const string camps[2] = {"red", "blue"};
int min_life;

void c_m_l(){
    int min = 20000;
    for (int i : wa_life) {
        if (i < min) min = i;
    }
    min_life = min;
}
class headquarter;
class warrior{
public:
    headquarter *camp; //武士的所属阵营
    int id;
    int life;
    warrior(headquarter* camp_, int id_, int life_):camp(camp_), id(id_), life(life_){}
};
class dragon:public warrior{
public:
    double morale;
    int arm;
    dragon(headquarter* camp_, int id_, int arm_, double morale_):warrior(camp_, id, wa_life[0]), morale(morale_), arm(arm_){}
    void wa_info(){
        cout <<setiosflags(ios::fixed);
        cout << "It has a " << wa_arms[arm] << ",and it's morale is " << setprecision(2) << morale << endl;
    };
};
class ninja:public warrior{
public:
    int arm[2];
    ninja(headquarter* camp_, int id_, int arm1, int arm2):warrior(camp_, id_, wa_life[1]){
        arm[0] = arm1; arm[1] = arm2;
    }
    void wa_info(){
        cout << "It has a " << wa_arms[arm[0]] << " and a " << wa_arms[arm[1]] << endl;
    }
};
class iceman:public warrior{
public:
    int arm;
    iceman(headquarter* camp_, int id_, int arm_):warrior(camp_, id_, wa_life[2]), arm(arm_){}
    void wa_info(){
        cout << "It has a " << wa_arms[arm] << endl;
    }
};
class lion:public warrior{
public:
    int loyal;
    lion(headquarter* camp_, int id_, int loyal_):warrior(camp_, id_, wa_life[3]), loyal(loyal_){}
    void wa_info(){
        cout << "It's loyalty is " << loyal << endl;
    }
};
class wolf:public warrior{
public:
    wolf(headquarter* camp_, int id_):warrior(camp_, id_, wa_life[4]){}
};





class headquarter{
public:
    int camp;
    int life;
    int stop = 0;
    int total_warriors = 0;
    int warriors[5] = {0,0,0,0,0};
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
    int now_wa_num = seq[camp][now]; //当前产生的武士类型
    warriors[now_wa_num]++;
    total_warriors++;
    life -= wa_life[seq[camp][now]];

    cout << setfill('0') << setw(3) << time;
    cout<<" "<<camps[camp]<<" "<<wa_race[now_wa_num]<<" "<< total_warriors<<" "<<"born with strength "<<wa_life[now_wa_num]
        <<","<<warriors[now_wa_num]<<" "<<wa_race[now_wa_num]<<" in "<<camps[camp]<<" headquarter"<<endl;

    if (now_wa_num == 0) {
        dragon temp_dragon(this, total_warriors, total_warriors%3, 1.0*life/wa_life[0]);
        temp_dragon.wa_info();
    }
    else if (now_wa_num == 1){
        ninja temp_ninja(this, total_warriors, total_warriors%3, (total_warriors+1)%3);
        temp_ninja.wa_info();
    }
    else if (now_wa_num == 2){
        iceman temp_iceman(this, total_warriors, total_warriors%3);
        temp_iceman.wa_info();
    }
    else if (now_wa_num == 3){
        lion temp_lion(this, total_warriors, life);
        temp_lion.wa_info();
    }
    else {
        wolf temp_wolf(this, total_warriors);
    }

    now++;
}


int main(){
    int test;
    cin >> test;
    for (int i = 1; i <= test ; i++) {
        int M;
        cin >> M;
        for (int & j : wa_life) cin >> j;
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
