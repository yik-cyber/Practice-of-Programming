#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;

int M, N, R, K ,T;
string wa_race[5] = {"dragon", "ninja", "iceman", "lion", "wolf"};
string weapon_type[3] = {"sword", "bomb", "arrow"};
string camps[2] = {"red", "blue"};
vector< vector<string> > battle_events;
vector< vector<string> >::iterator p;
int wa_life[5];
int wa_att[5];
int clocks, minute, tot_minute;
bool over[2];
void print_time(){
    cout << setfill('0') << setw(3) << clocks << ":";
    cout << setfill('0') << setw(2) << minute;
    cout << " ";
}
string time_string(){
    string time;
    stringstream ss;
    ss << setfill('0') << setw(3) << clocks << ":";
    ss << setfill('0') << setw(2) << minute;
    ss >> time;
    time += " ";
    return time;
}
string trans(int n){
    stringstream ss;
    ss << n;
    string s = ss.str();
    return s;
}


class Warrior;
class City;
class Weapon;
class Headquarter;
Headquarter* Red;
Headquarter* Blue;
City* city[22];


class Weapon{
public:
    int type_id;
    int att;
    int limit;
    Warrior* owner;
    Weapon(int _id, int _att, Warrior* _owner);
    void passivation();
};

class Warrior{
public:
    int id;
    int race_id;
    string race_name;
    int life; int before_life;
    int att;
    Weapon* arm[3] = {nullptr};
    Headquarter* from;
    int pos;
    bool attack_first = false;
    bool kill_object = false;
    bool arrow_death = false;
    bool reach_op = false;
    Warrior(int _id, int _race_id, int _pos, Headquarter* _from){
        id = _id; race_id = _race_id; race_name = wa_race[race_id];
        life = wa_life[race_id]; att = wa_att[race_id];pos = _pos; from = _from;
        print_produce_info();
    }
    void set_before_life(){
        if (life > 0) before_life = life;
    }
    void attack(Warrior* object, bool pretend);
    void count_attack(Warrior* object, bool pretend);
    void hurt(int damage){
        life -= damage;
    }
    bool is_alive(){
        return life > 0;
    }
    void gain_life();
    void print_death();
    void print_produce_info();

    virtual void loyal_change(Warrior* object){}
    virtual void life_trans(Warrior* object){}
    virtual bool run_away(){return false;}
    virtual void walk_life(){}
    virtual void yell(){}
    virtual void morale_change(Warrior* object){}
    void march_info();
    void check_arrow(){
        arm[2]->limit--;
        if (arm[2] && arm[2]->limit <= 0) arm[2] = nullptr;
    }
    void snatch_weapon(Warrior* object){
        if (race_id!=4 || life<=0 || object->is_alive()) return;
        for (int i = 0; i < 3; ++i) {
            if (!arm[i] && object->arm[i]) arm[i] = object->arm[i];
        }
    }
    void check_sword(){
        if (arm[0]&&arm[0]->att==0) arm[0]= nullptr;
    }
};
class Dragon:public Warrior{
public:
    double morale;

    Dragon(int _id, int _pos, Headquarter* _from);
    void yell();
    void morale_change(Warrior* object){
        if (!is_alive()) return;
        if (!object->is_alive()) morale+=0.2;
        else morale -= 0.2;
    }
    void print_morale(){
        cout<<"Its morale is "<<fixed<<setprecision(2)<<morale<<endl;
    }
    bool run_away(){return false;}
    void walk_life(){return;}
    void loyal_change(Warrior* object){}
    void life_trans(Warrior* object){}
};
class Ninja:public Warrior{
public:
    Ninja(int _id, int _pos, Headquarter* _from):
        Warrior(_id, 1, _pos, _from){
        arm[id%3] = new Weapon(id%3, att, this);
        arm[(id+1)%3] = new Weapon((id+1)%3, att, this);
    }
    bool run_away(){return false;}
    void walk_life(){return;}
    void yell(){}
    void morale_change(){}
    void loyal_change(Warrior* object){}
    void life_trans(Warrior* object){}
};
class Iceman:public Warrior{
public:
    int walks;
    Iceman(int _id, int _pos, Headquarter* _from):
        Warrior(_id, 2, _pos, _from){
        arm[id%3] = new Weapon(id%3, att, this); walks = 0;
    }
    void walk_life(){
        walks++;
        if (walks > 0 && walks%2 == 0){
            life -= 9;
            att += 20;
            if (life<=0)  life = 1;
        }
    }
    bool run_away(){return false;}
    void yell(){}
    void morale_change(Warrior* object){}
    void loyal_change(Warrior* object){}
    void life_trans(Warrior* object){}
};
class Lion:public Warrior{
public:
    int loyal;
    Lion(int _id, int _pos, Headquarter* _from);
    void life_trans(Warrior* object){
        if (life>0 || arrow_death) return; //还活着或被arrow射死不用转移
        object->life += before_life;
    }
    bool run_away();
    void print_loyal(){
        cout<<"Its loyalty is "<<loyal<<endl;
    }
    void walk_life(){return;}
    void yell(){}
    void morale_change(Warrior* object){}
    void loyal_change(Warrior* object){
        if (life>0 && object->is_alive()) loyal -= K;
    }

};
class Wolf:public Warrior{
public:
    Wolf(int _id, int _pos, Headquarter* _from):
        Warrior(_id, 4, _pos, _from){}
    void snatch_weapon(Warrior* object){
        if (object->is_alive()) return;
        for (int i = 0; i < 3; ++i) {
            if (!arm[i]&&!object->arm[i]) *arm[i] = *object->arm[i];
        }
    }
    bool run_away(){return false;}
    void walk_life(){return;}
    void yell(){}
    void morale_change(Warrior* object){}
    void loyal_change(Warrior* object){}
    void life_trans(Warrior* object){}
};
void Weapon::passivation(){
    if (type_id!=0) return;
    att = 8 * att / 10;
    if (att <= 0) owner->arm[0] = nullptr;
}
Weapon::Weapon(int _id, int _att, Warrior* _owner):type_id(_id), owner(_owner){
    if (_id == 0) {
        att = 2 * _att /10;
    }
    if (_id == 2) {
        att = R; limit = 3;
    }
}

class City{
public:
    int id;
    int flag; //0 red 1 blue 2 none
    int life;
    bool is_battle; //记录是否发生战斗
    int winner[2]; //记录连续的战斗
    int now_battle; //记录当前战果 0 red 1 blue 2 even
    Warrior* was[2] = {nullptr, nullptr};
    City(int _id, int _life):id(_id),life(_life){
        flag = 2; now_battle = 3; is_battle = false; winner[0]  = winner[1] = 0;
    }
    void produce_life(){
        life += 10;
    }
    bool red_first(){ //判断红方先手
        if (!flag) return true;
        else return flag == 2 && id % 2;
    }
    void raise_flag(){ //判断升起旗帜
        if (!is_battle || now_battle==2) return;
        for (int i = 0; i < 2; ++i) {
            if (winner[i] == 2 && flag != i){
                flag = i;
                string event = time_string();
                event = event+camps[i]+" flag raised in city "+trans(id);
                p = battle_events.begin() + id - 1;
                p->push_back(event);
            }
        }
    }
};

class Headquarter:public City{
public:
    int camp_id;
    int pos[2] = {0, N+1};
    string camp_name;
    int wa_num;
    int op_wa_num;
    int seq[2][5] = {{2,3,4,1,0}, {3,0,1,2,4}};
    Headquarter(int _id, int _life, int _camp_id):City(_id, _life){
        camp_id = _camp_id; camp_name = camps[camp_id]; now_sq = 0; wa_num = 0; op_wa_num = 0;
    }
    void red_send_reward(){
        for (int i = N; i > 0 ; --i) {
            if (life>=8 && city[i]->was[0] && city[i]->was[0]->is_alive() && (city[i]->was[1]&&!city[i]->was[1]->is_alive())){ //在战斗中杀死敌人才奖励
                city[i]->was[0]->life +=8;
                life -= 8;
                city[i]->was[0]->kill_object = false;
            }
        }
    }
    void blue_send_reward(){
        for (int i = 1; i <= N ; ++i) {
            if (life>=8 && city[i]->was[1] && city[i]->was[1]->is_alive() && (city[i]->was[0]&&!city[i]->was[0]->is_alive())){
                city[i]->was[1]->life +=8;
                life -= 8;
                city[i]->was[1]->kill_object = false;
            }
        }
    }
    void print_head_life(){
        print_time();
        cout<<life<<" elements in "<<camp_name<<" headquarter"<<endl;
    }
    int now_sq;
    void produce_warrior();
};
void Warrior::print_produce_info(){
    print_time();
    cout<<from->camp_name<<" "<<race_name<<" "<<id<<" born"<<endl;
}
void Warrior::march_info(){
    if (reach_op) return;
    print_time();
    if (pos == 0||pos==N+1){
        reach_op = true;
        cout<<from->camp_name<<" "<<race_name<<" "<<id<<" reached "<<camps[!from->camp_id]<<" headquarter with "
            <<life<<" elements and force "<<att<<endl;
        if (!over[0] && pos==N+1 && Blue->op_wa_num==2){
            over[0] = true;
            print_time();
            cout << "blue headquarter was taken"<<endl;
        }
        if (!over[1] && pos==0 && Red->op_wa_num==2){
            over[1] = true;
            print_time();
            cout << "red headquarter was taken"<<endl;
        }
    } else{
        cout<<from->camp_name<<" "<<race_name<<" "<<id<<" marched to city "<<pos<<" with "
            <<life<<" elements and force "<<att<<endl;
    }
}
void Warrior::attack(Warrior* object, bool pretend = false){
    if (life <= 0 || object->life <= 0) return;
    int weapon_att;
    if (arm[0] == nullptr) weapon_att = 0;
    else weapon_att = arm[0]->att;
    object->hurt(att + weapon_att);
    if (pretend) return;
    if (!object->is_alive()){
        kill_object = true;
        city[pos]->now_battle = from->camp_id;
    }
    if (arm[0] != nullptr) arm[0]->passivation();

    string event = time_string();
    event = event+from->camp_name+" "+race_name+" "+trans(id)+" attacked "+object->from->camp_name+" "
            +object->race_name+" "+trans(object->id)+" in city "+trans(pos)+" with "+trans(life)+" elements and force "+trans(att);
    p = battle_events.begin() + pos - 1;
    p->push_back(event);
}
void Warrior::count_attack(Warrior* object, bool pretend = false){
    if (race_id == 1 || life <= 0 || object->life <= 0) return;
    int weapon_att;
    if (arm[0] == nullptr) weapon_att = 0;
    else weapon_att = arm[0]->att;
    object->hurt(att/2 + weapon_att);
    if (pretend) return;
    if (!object->is_alive()){
        kill_object = true;
        city[pos]->now_battle = from->camp_id; //记录战斗结果
    }
    if (arm[0] != nullptr) arm[0]->passivation();
    string event = time_string();
    event = event+from->camp_name+" "+race_name+" "+trans(id)+" fought back against "+object->from->camp_name+" "
            +object->race_name+" "+trans(object->id)+" in city "+trans(pos);
    p = battle_events.begin() + pos - 1;
    p->push_back(event);
}
void Warrior::print_death(){
    if (life>0 || arrow_death || !city[pos]->is_battle) return;
    string event = time_string();
    event = event+from->camp_name+" "+race_name+" "+trans(id)+" was killed in city "+trans(pos);
    p = battle_events.begin() + pos - 1;
    p->push_back(event);
}
void Warrior::gain_life(){
    if (life<=0 || city[pos]->now_battle == 2) return;
    int g_l = city[pos]->life;
    from->life += g_l;
    city[pos]->life = 0;
    string event = time_string();
    event = event+from->camp_name+" "+race_name+" "+trans(id)+" earned "+trans(g_l)+" elements for his headquarter";
    p = battle_events.begin() + pos - 1;
    p->push_back(event);
}
Dragon::Dragon(int _id, int _pos, Headquarter* _from):
        Warrior(_id, 0, _pos, _from){
    morale = 1.0 * from->life / life;
    arm[id%3] = new Weapon(id%3, att, this);
    print_morale();
}
void Dragon::yell(){
    if (attack_first && is_alive() && morale > 0.8){
        string event = time_string();
        event = event+from->camp_name+" "+race_name+" "+trans(id)+" yelled in city "+trans(pos);
        p = battle_events.begin() + pos - 1;
        p->push_back(event);
        attack_first = false;
    }
}
Lion::Lion(int _id, int _pos, Headquarter* _from):
        Warrior(_id, 3, pos, _from){
    loyal = from->life;
    print_loyal();
}
bool Lion::run_away(){
    if (loyal>0 || reach_op) return false;
    //000:05 blue lion 1 ran away
    print_time();
    cout<<from->camp_name<<" lion "<<id<<" ran away"<<endl;
    return true;
}

void Headquarter::produce_warrior(){ //制造武士
    int now_wa = seq[camp_id][now_sq];
    if (life < wa_life[now_wa]) return;
    life -= wa_life[now_wa];
    wa_num++;
    if (now_wa==0) was[camp_id] = new Dragon(wa_num, pos[camp_id], this);
    else if (now_wa==1) was[camp_id] = new Ninja(wa_num, pos[camp_id], this);
    else if (now_wa==2) was[camp_id] = new Iceman(wa_num, pos[camp_id], this);
    else if (now_wa==3) was[camp_id] = new Lion(wa_num, pos[camp_id], this);
    else if (now_wa==4) was[camp_id] = new Wolf(wa_num, pos[camp_id], this);
    was[camp_id]->check_sword();
    now_sq = (now_sq+1)%5;
}

void lion_run_away(){ //狮子逃跑
    for (int i = 0; i <= N+1; ++i) {
        for(auto & wa : city[i]->was){
            if (wa && wa->run_away()) wa = nullptr;
        }
    }
}

void produce_life(){
    for (int i = 1; i <= N ; ++i) city[i]->life += 10;
}

void march(){
     for (int i = N; i >= 0; --i){
         if (!city[i]->was[0]) continue;
         city[i+1]->was[0] = city[i]->was[0]; city[i]->was[0] = nullptr;
         city[i+1]->was[0]->walk_life(); city[i+1]->was[0]->pos = i+1;
         if (i+1==N+1) Blue->op_wa_num++;

     }
    for (int i = 1; i <= N+1 ; ++i) {
        if (!city[i]->was[1]) continue;
        city[i-1]->was[1] = city[i]->was[1]; city[i]->was[1] = nullptr;
        city[i-1]->was[1]->walk_life(); city[i-1]->was[1]->pos = i-1;
        if (i-1==0) Red->op_wa_num++;
    }

    for (int i = 0; i <= N+1 ; ++i) {
        for (auto & wa : city[i]->was) {
            if(wa) wa->march_info();
        }
    }
}

void get_life(){ //获取城市生命
    for (int i = 1; i <= N; ++i) {
        if (city[i]->was[0] && !city[i]->was[1]){
            city[i]->was[0]->from->life += city[i]->life;
            print_time();
            cout<<"red "<<city[i]->was[0]->race_name<<" "<<city[i]->was[0]->id<<" earned "<<city[i]->life<<" elements for his headquarter"<<endl;
            city[i]->life = 0;

        }
        else if(city[i]->was[1] && !city[i]->was[0]){
            city[i]->was[1]->from->life += city[i]->life;
            print_time();
            cout<<"blue "<<city[i]->was[1]->race_name<<" "<<city[i]->was[1]->id<<" earned "<<city[i]->life<<" elements for his headquarter"<<endl;
            city[i]->life = 0;
        }
    }
}

void shoot_arrow(){
    int walk[2] = {1, -1};
    for (int i = 1; i <= N ; ++i) {
        for (int j = 0; j < 2; ++j) {
            Warrior* w1 = city[i]->was[j]; Warrior* w2 = city[i+walk[j]]->was[!j];
            if (w1 && w1->arm[2] && w2 && w2->pos!= 0 && w2->pos != N+1){
                w2->life -= R;
                w1->check_arrow();
                print_time();
                cout<<w1->from->camp_name<<" "<<w1->race_name<<" "<<w1->id<<" shot";
                if (!w2->is_alive()){
                    cout<<" and killed "<<w2->from->camp_name<<" "<<w2->race_name<<" "<<w2->id<<endl;
                    w1->kill_object = true;
                    w2->arrow_death = true;
                    if (city[i+walk[j]]->was[j] && city[i+walk[j]]->was[j]->is_alive()){ //被射死的城市有另一个活武士记作战斗
                        city[w2->pos]->is_battle = true; //判定战斗
                        city[w2->pos]->now_battle = w1->from->camp_id;
                        city[w2->pos]->now_battle = j;
                    }
                }
                else cout<<endl;
            }
        }
    }
    for (int i = 1; i <= N ; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (city[i]->was[j] && !city[i]->was[j]->is_alive() &&  //如果被射死时对方没有武士或者被射死，当无事发生
                    (!city[i]->was[!j]||(city[i]->was[!j]&&!city[i]->was[!j]->is_alive()))) city[i]->was[j] = nullptr;
        }
    }
}

void bomb(){
    for (int i = 1; i <= N ; ++i) {
        Warrior* w1 = city[i]->was[0]; Warrior* w2 = city[i]->was[1];
        if (w1 && w2 && w1->is_alive() && w2->is_alive() && (w1->arm[1]||w2->arm[1])){
            Warrior cp_w1 = *w1; Warrior cp_w2 = *w2;
            if (city[i]->red_first()){
                cp_w1.attack(&cp_w2, true);
                cp_w2.count_attack(&cp_w1, true);
            }
            else{
                cp_w2.attack(&cp_w1, true);
                cp_w1.count_attack(&cp_w2, true);
            }
            if (!cp_w1.is_alive() && w1->arm[1]){
                print_time();
                cout<<"red "<<w1->race_name<<" "<<w1->id<<" used a bomb and killed blue "<<w2->race_name<<" "<<w2->id<<endl;
                city[i]->was[0] = city[i]->was[1] = nullptr;
            }
            else if (!cp_w2.is_alive() && w2->arm[1]){
                print_time();
                cout<<"blue "<<w2->race_name<<" "<<w2->id<<" used a bomb and killed red "<<w1->race_name<<" "<<w1->id<<endl;
                city[i]->was[0] = city[i]->was[1] = nullptr;
            }
        }
    }
}

void battles(){
    for (int i = 1; i <= N; ++i) {
        if (!(city[i]->was[0]) || !city[i]->was[1]) continue; //武士不足

        int j = city[i]->red_first()? 0:1; //先手判断
        city[i]->was[j]->attack_first = true;

        if (!city[i]->is_battle){ //还没有发生过战斗
            city[i]->was[0]->set_before_life(); city[i]->was[1]->set_before_life();
            city[i]->was[0]->kill_object = city[i]->was[1]->kill_object = false; //战斗开始前设置一下
            city[i]->is_battle = true;

            city[i]->was[j]->attack(city[i]->was[!j]);
            city[i]->was[!j]->count_attack(city[i]->was[j]);
        }

        if (city[i]->was[1]->is_alive() && !city[i]->was[0]->is_alive()){
            city[i]->winner[0] = 0;
            city[i]->winner[1]++;
        }
        if (city[i]->was[0]->is_alive() && !city[i]->was[1]->is_alive()) {
            city[i]->winner[1] = 0;
            city[i]->winner[0]++;
        }


        city[i]->was[0]->print_death();
        city[i]->was[1]->print_death();

        city[i]->was[0]->loyal_change(city[i]->was[1]);
        city[i]->was[0]->life_trans(city[i]->was[1]);
        city[i]->was[1]->loyal_change(city[i]->was[0]);
        city[i]->was[1]->life_trans(city[i]->was[0]);

        city[i]->was[0]->snatch_weapon(city[i]->was[1]);
        city[i]->was[1]->snatch_weapon(city[i]->was[0]);

        city[i]->was[0]->morale_change(city[i]->was[1]);
        city[i]->was[1]->morale_change(city[i]->was[0]);
        city[i]->was[0]->yell();
        city[i]->was[1]->yell();
    }
    Red->red_send_reward(); Blue->blue_send_reward();
    for (int i = 1; i <= N ; ++i) {
        if (!city[i]->was[0] || !city[i]->was[1]) continue; //武士不足
        if (city[i]->was[0]->is_alive() && city[i]->was[1]->is_alive()){
            city[i]->winner[0] = city[i]->winner[1] = 0;
            city[i]->now_battle = 2;
        }
        city[i]->was[0]->gain_life();
        city[i]->was[1]->gain_life();
        if (!city[i]->was[0]->is_alive()){
            city[i]->was[0] = nullptr;
        }
        if (!city[i]->was[1]->is_alive()) {
            city[i]->was[1] = nullptr;
        }
        city[i]->raise_flag();
    }
    for (int i = 1; i <= N ; ++i) {
        city[i]->is_battle = false; city[i]->now_battle = 3;
    }
    for (p = battle_events.begin(); p!=battle_events.end(); ++p) {
        vector<string> city_events = *p;
        vector<string>::iterator p2 = city_events.begin();
        for(; p2!=city_events.end();++p2){
            cout << *p2 << endl;
        }
    }
}

void print_weapons(){
    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i <= N+1; ++i) {
            Warrior* w = city[i]->was[j];
            if (!w) continue;
            print_time();
            cout<<w->from->camp_name<<" "<<w->race_name<<" "<<w->id<<" has ";
            if (w->arm[2]) cout<<"arrow("<<w->arm[2]->limit<<")";
            if (w->arm[1]) {
                if (w->arm[2]) cout<<",";
                cout<<"bomb";
            }
            if (w->arm[0]){
                if (w->arm[1]||(w->arm[2]&&!w->arm[1])) cout<<",";
                cout<<"sword("<<w->arm[0]->att<<")";
            }
            if (!w->arm[0]&&!w->arm[1]&&!w->arm[2]) cout<<"no weapon";
            cout << endl;
        }
    }
}

int main(){
    int test; cin >> test;
    int case_num = 1;
    while (test--){
        cin >> M >> N >> R >> K >> T;
        for(int i = 0; i < 5; ++i) cin >> wa_life[i];
        for(int i = 0; i < 5; ++i) cin >> wa_att[i];
        Red = new Headquarter(0, M, 0);
        Blue = new Headquarter(N+1, M, 1);
        city[0] = Red; city[N+1] = Blue;
        for (int j = 1; j <= N; ++j) {
            city[j] = new City(j, 0);
        }
        clocks = 0; minute = 0; tot_minute = 0;
        cout<<"Case "<<case_num<<":"<<endl; //pay attention
        case_num++;
        over[0] = over[1] =  false;
        while(tot_minute<=T&&!over[0]&&!over[1]){ //胜负未定，时间未到
            //双方制造武士
            if (tot_minute>T) break;
            Red->produce_warrior();
            Blue->produce_warrior();


            //lion逃跑
            minute = 5; tot_minute +=5;
            if (tot_minute>T) break;
            lion_run_away();


            //武士行军
            minute = 10; tot_minute += 5;
            if (tot_minute>T) break;
            march();
            if (over[0]||over[1]||tot_minute>=T) break;

            //城市产生生命元
            minute = 20; tot_minute += 10;
            if (tot_minute>T) break;
            produce_life();

            //夺取城市生命元
            minute = 30; tot_minute += 10;
            if (tot_minute>T) break;
            get_life();

            //射箭
            minute = 35; tot_minute += 5;
            if (tot_minute>T) break;
            shoot_arrow();

            //bomb判断
            minute = 38; tot_minute += 3;
            if (tot_minute>T) break;
            bomb();
            
            //战斗
            minute = 40; tot_minute += 2;
            if (tot_minute>T) break;
            battle_events.erase(battle_events.begin(), battle_events.end());
            for(int i = 1; i <= N; ++i) battle_events.push_back(vector<string>());
            battles();

            //报告生命元数量
            minute = 50; tot_minute += 10;
            if (tot_minute>T) break;
            Red->print_head_life();
            Blue->print_head_life();

            //武士报告
            minute = 55; tot_minute += 5;
            if (tot_minute>T) break;
            print_weapons();

            minute = 0; tot_minute += 5;
            clocks++;

        }
    }
}
