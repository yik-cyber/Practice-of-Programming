#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
using namespace std;

class City;
class headquarter;
class warrior;
class weapon;
int M, N, K, T;
const char wa_race[5][10] = {"dragon", "ninja", "iceman", "lion", "wolf"};
const char wa_arms[3][10] = {"sword", "bomb", "arrow"};
int wa_life[5];
int wa_att[5];
const string camps[2] = {"red", "blue"};
int clocks, minute, tot_minute;
bool over;
City* city[22]; //创建好的城市指针

void print_time(){
    cout << setfill('0') << setw(3) << clocks << ":";
    cout << setfill('0') << setw(2) << minute;
    cout << " ";
}

class weapon{
public:
    int id; //武器编号 0:sword 1:bomb 2:arrow
    int att; // 武器的攻击力
    int limit; // 武器使用的次数限制
    weapon(int id_, int wa_attack):id(id_){
        if (id == 0){att = int(2*wa_attack/10); limit = 100000;} //表示不限使用次数
        else if (id == 1){att = int(4*wa_attack/10); limit = 1;}
        else if (id == 2){att = int(3*wa_attack/10); limit = 2;}
    }
    void reset_attack(int wa_att){ //重新设置攻击力
        if (id == 0){att = int(2*wa_att/10);}
        else if (id == 1){att = int(4*wa_att/10);}
        else if (id == 2){att = int(3*wa_att/10);}
    }
};
int cmp_weapon1(const void* a1, const void* a2){ //给武器排序1
    weapon** w1 = (weapon**)a1;
    weapon** w2 = (weapon**)a2;
    if ((*w1)->id == (*w2)->id){
        return (*w2)->limit - (*w1)->limit; //没用过的放在前面
    }
    return (*w1)->id - (*w2)->id;
}

int cmp_weapon2(const void* a1, const void* a2){ //给武器排序2
    weapon** w1 = (weapon**)a1;
    weapon** w2 = (weapon**)a2;
    if ((*w1)->id == (*w2)->id){
        return (*w1)->limit - (*w2)->limit; //用过的放在前面
    }
    return (*w1)->id - (*w2)->id;
}


class warrior{ //武士类
public:
    headquarter *camp; //武士的所属阵营
    int id;
    int race = 0;
    int life;
    int att;
    int loyal = 0;
    weapon *arms[10] = {nullptr}; //武士拥有的武器。最多十把，指针desu
    int arm_num = 0;
    int sba[3] = {0,0,0};
    warrior(headquarter* camp_, int id_, int life_, int att_):camp(camp_), id(id_), life(life_), att(att_){}
    virtual int attack(warrior* w1, int i) = 0;
    virtual void hurt(int damage){}
    void arms_sort1(){
        qsort(arms, arm_num, sizeof(weapon*), cmp_weapon1);
    }
    void arms_sort2(){
        qsort(arms, arm_num, sizeof(weapon*), cmp_weapon2);
    }
    void arrange_arms(int snatched){ //抢走武器后重新排一下
        arm_num -= snatched; //剩下的武器数量
        for (int i = 0; i < arm_num; ++i) {
            arms[i] = arms[snatched+i];
        }
    }
    void arrange_arms2(int locate){ //战斗中武器使用后重排
        arm_num--;
        for (int i = locate; i < arm_num; ++i) {
            arms[i] = arms[i+1];//往前移动一位
        }
    }
    virtual ~warrior(){}
};
class dragon:public warrior{
public:
    dragon(headquarter* camp_, int id_, int arm_):warrior(camp_, id_, wa_life[0], wa_att[0]){
        arms[0] = new weapon(arm_, att);
        sba[arm_]++;
        arm_num++; race = 0;
    }
    int attack(warrior* w1,int i){
        weapon* now = arms[i];
        w1->hurt(now->att);
        if (now->id == 1) hurt(now->att/2); //如果使用的是bomb
        now->limit--;
        if (now->limit == 0){
            arrange_arms2(i);
            sba[now->id]--;
            return 1;
        } //表示武器被使用了
        return 0;//该武器没有被使用掉
    }
    void hurt(int damage){
        life -= damage;
    }
};
class ninja:public warrior{
public:
    ninja(headquarter* camp_, int id_, int arm1, int arm2):warrior(camp_, id_, wa_life[1], wa_att[1]){
        arms[0] = new weapon(arm1, att); sba[arm1]++;
        arms[1] = new weapon(arm2, att); sba[arm2]++;
        arm_num = 2; race = 1;
    }
    int attack(warrior* w1,int i){
        weapon* now = arms[i];
        w1->hurt(now->att);
        now->limit--;
        if (now->limit == 0){
            arrange_arms2(i);
            sba[now->id]--;
            return 1;
        } //表示武器被使用了
        return 0;//该武器没有被使用掉
    }
    void hurt(int damage){
        life -= damage;
    }
};
class iceman:public warrior{
public:
    iceman(headquarter* camp_, int id_, int arm_):warrior(camp_, id_, wa_life[2], wa_att[2]){
        arms[0] = new weapon(arm_, att);
        sba[arm_]++;
        arm_num = 1; race = 2;
    }
    int attack(warrior* w1,int i){
        weapon* now = arms[i];
        w1->hurt(now->att);
        if (now->id == 1) hurt(now->att/2); //如果使用的是bomb
        now->limit--;
        if (now->limit == 0){
            arrange_arms2(i);
            sba[now->id]--;
            return 1;
        } //表示武器被使用了
        return 0;//该武器没有被使用掉
    }
    void hurt(int damage){
        life -= damage;
    }
};
class lion:public warrior{
public:
    lion(headquarter* camp_, int id_,int arm_,  int loyal_):warrior(camp_, id_, wa_life[3], wa_att[3]){
        arms[0] = new weapon(arm_, att);
        sba[arm_]++;
        loyal = loyal_;
        arm_num = 1; race = 3;
    }
    void wa_info(){
        cout << "It's loyalty is " << loyal << endl;
    }
    int attack(warrior* w1,int i){
        weapon* now = arms[i];
        w1->hurt(now->att);
        if (now->id == 1) hurt(now->att/2); //如果使用的是bomb
        now->limit--;
        if (now->limit == 0){
            arrange_arms2(i);
            sba[now->id]--;
            return 1;
        } //表示武器被使用了
        return 0;//该武器没有被使用掉
    }
    void hurt(int damage){
        life -= damage;
    }
};
class wolf:public warrior{
public:
    wolf(headquarter* camp_, int id_):warrior(camp_, id_, wa_life[4], wa_att[4]){race = 4;}
    int attack(warrior* w1,int i){
        weapon* now = arms[i];
        w1->hurt(now->att);
        if (now->id == 1) hurt(now->att/2); //如果使用的是bomb
        now->limit--;
        if (now->limit == 0){
            arrange_arms2(i);
            sba[now->id]--;
            return 1;
        } //表示武器被使用了
        return 0;//该武器没有被使用掉
    }
    void hurt(int damage){
        life -= damage;
    }
};

class City{ //城市类
public:
    int id;
    warrior* red_wa;
    warrior* blue_wa;
    City(int id_):id(id_), red_wa(nullptr), blue_wa(nullptr){}
};

class headquarter{ //红蓝阵营类
public:
    int camp;
    int life;
    int stop = 0;
    int tot_wa = 0;
    int warriors[5] = {0,0,0,0,0};
    int seq[2][5] = {{2,3,4,1,0}, {3,0,1,2,4}};
    int now = 0;

    headquarter(int n, int M):camp(n), life(M){}
    void Produce();
    void march();
    void report(){
        print_time();
        cout << life << " elements in " << camps[camp] << " headquarter" << endl;
    }
};

void headquarter::Produce(){ //产生武士
    if (stop) return;

    int now_wa_num = seq[camp][now]; //当前产生的武士类型
    if (life < wa_life[now_wa_num]){
        stop = 1; return; //无法制造该武士就停止制造
    }
    warriors[now_wa_num]++;
    tot_wa++;
    life -= wa_life[now_wa_num];

    //输出产生的武士
    print_time();
    cout << camps[camp] << " " << wa_race[now_wa_num] << " " << tot_wa << " born" << endl;
    if (now_wa_num == 3) cout << "Its loyalty is " << life << endl;


    if (now_wa_num == 0) {
        if (!camp) city[0]->red_wa = new dragon(this, tot_wa, tot_wa%3);
        else city[N+1]->blue_wa = new dragon(this, tot_wa, tot_wa%3);
    }
    else if (now_wa_num == 1){
        if (!camp) city[0]->red_wa = new ninja(this, tot_wa, tot_wa%3, (tot_wa+1)%3);
        else city[N+1]->blue_wa = new ninja(this, tot_wa, tot_wa%3, (tot_wa+1)%3);
    }
    else if (now_wa_num == 2){
        if (!camp) city[0]->red_wa = new iceman(this, tot_wa, tot_wa%3);
        else city[N+1]->blue_wa = new iceman(this, tot_wa, tot_wa%3);;
    }
    else if (now_wa_num == 3){
        if (!camp) city[0]->red_wa = new lion(this, tot_wa, tot_wa%3, life);
        else city[N+1]->blue_wa = new lion(this, tot_wa, tot_wa%3, life);
    }
    else {
        if (!camp) city[0]->red_wa = new wolf(this, tot_wa);
        else city[N+1]->blue_wa = new wolf(this, tot_wa);
    }
    now = (now+1)%5;
}

void lion_escape() { // 狮子逃跑， 如果是在敌方阵营。那么上一轮游戏就结束了，可不用管
    for (int i = 0; i <= N+1 ; i++) {
        warrior* temp = city[i]->red_wa;
        if (temp && temp->race == 3 && temp->loyal <= 0){
            print_time();
            cout << "red  lion " << temp->id << " ran away" << endl;
            delete city[i]->red_wa;
            city[i]->red_wa = nullptr;
        }
        temp = city[i]->blue_wa;
        if (temp && temp->race == 3 && temp->loyal <= 0){
            print_time();
            cout << "blue lion " << temp->id << " ran away" << endl;
            delete city[i]->blue_wa;
            city[i]->blue_wa = nullptr;
        }
    }
}

void headquarter::march() {
    if (!camp){ //红方进军
        for (int i = N; i >= 0 ; i--) { //遍历城市进军
            if (city[i]->red_wa){
                city[i+1]->red_wa = city[i]->red_wa;
                if(city[i+1]->red_wa->race == 2) city[i+1]->red_wa->life -= int(city[i+1]->red_wa->life/10);
                if(city[i+1]->red_wa->race == 3) city[i+1]->red_wa->loyal -= K;
            }
            city[i]->red_wa = nullptr;
        }
    } else{
        for (int i = 1; i <= N+1 ; i++) { //遍历城市进军
            if (city[i]->blue_wa) {
                city[i-1]->blue_wa = city[i]->blue_wa;
                if(city[i-1]->blue_wa->race == 2) city[i-1]->blue_wa->life -= int(city[i-1]->blue_wa->life/10);
                if(city[i-1]->blue_wa->race == 3) {
                    city[i-1]->blue_wa->loyal -= K;
                }
            }
            city[i]->blue_wa = nullptr;
        }
    }


}
void print_march(){
    if (city[0]->blue_wa){
        print_time();
        cout << "blue" << " " << wa_race[city[0]->blue_wa->race] << " " << city[0]->blue_wa->id
             << " reached red headquarter with " << city[0]->blue_wa->life << " elements and force "
             << city[0]->blue_wa->att << endl;
        print_time();
        cout << "red headquarter was taken" << endl;
        over = true;
    }
    for (int i = 1; i <= N; i++) {
        if (city[i]->red_wa){
            print_time();
            cout << "red" << " " << wa_race[city[i]->red_wa->race] << " " << city[i]->red_wa->id
                 << " marched to city "<< i << " with " << city[i]->red_wa->life << " elements and force "
                 << city[i]->red_wa->att << endl;
        }
        if (city[i]->blue_wa){
            print_time();
            cout << "blue" << " " << wa_race[city[i]->blue_wa->race] << " " << city[i]->blue_wa->id
                 << " marched to city "<< i << " with " << city[i]->blue_wa->life << " elements and force "
                 << city[i]->blue_wa->att << endl;
        }
    }
    if (city[N+1]->red_wa){
        print_time();
        cout << "red" << " " << wa_race[city[N+1]->red_wa->race] << " " << city[N+1]->red_wa->id
             << " reached blue headquarter with " << city[N+1]->red_wa->life << " elements and force "
             << city[N+1]->red_wa->att << endl;
        print_time();
        cout << "blue headquarter was taken" << endl;
        over = true;
    }
}

void snatch_weapon(){
    for (int i = 1; i <= N; i++) {
        warrior* redwa = city[i]->red_wa;
        warrior* bluewa = city[i]->blue_wa;
        if (redwa && bluewa){
            if (redwa->race == 4 && bluewa->race !=4 && bluewa->arm_num > 0 && redwa->arm_num < 10){ // 抢夺条件
                bluewa->arms_sort1(); //武器排序
                int snatch = bluewa->arms[0]->id; //抢夺的武器id
                int snatch_num = 0;
                int j = 0;
                while(j<bluewa->arm_num && bluewa->arm_num>0 && bluewa->arms[j]->id == snatch && redwa->arm_num < 10){
                    redwa->arms[redwa->arm_num++] = bluewa->arms[j];
                    redwa->arms[redwa->arm_num-1]->reset_attack(wa_att[redwa->race]); //抢来的武器重新设置攻击力
                    redwa->sba[snatch]++; bluewa->sba[snatch]--;
                    snatch_num++;
                    j++;
                }
                bluewa->arrange_arms(snatch_num); //抢完后重新排一下
                print_time();//打印抢夺结果
                cout << "red wolf " << redwa->id << " took " << snatch_num << " " << wa_arms[snatch] << " from blue "
                     << wa_race[bluewa->race] << " " << bluewa->id << " in city " << i << endl;
            }
            if (bluewa->race == 4 && redwa->race !=4 && redwa->arm_num > 0 && bluewa->arm_num < 10){ // 抢夺条件
                redwa->arms_sort1(); //武器排序
                int snatch = redwa->arms[0]->id;
                int snatch_num = 0;
                int j = 0;
                while(j<redwa->arm_num &&redwa->arm_num>0 && redwa->arms[j]->id == snatch && bluewa->arm_num < 10){
                    bluewa->arms[bluewa->arm_num++] = redwa->arms[j];
                    bluewa->arms[bluewa->arm_num-1]->reset_attack(wa_att[bluewa->race]); //抢来的武器重新设置攻击力
                    bluewa->sba[snatch]++; redwa->sba[snatch]--;
                    snatch_num++;
                    j++;
                }
                redwa->arrange_arms(snatch_num); //抢完后重新排一下
                print_time();//打印抢夺结果
                cout << "blue wolf " << bluewa->id << " took " << snatch_num << " " << wa_arms[snatch] << " from red "
                     << wa_race[redwa->race] << " " << redwa->id << " in city " << i << endl;
            }
        }
    }
}

void battle(){
    int i = 1;
    for(;i<=N;i++){
        warrior* red = city[i]->red_wa; warrior* blue = city[i]->blue_wa;
        if (!red||!blue) continue; //没有两方士兵就摸鱼
        red->arms_sort2(); blue->arms_sort2();//对武器进行排序
        if (i%2){ //红方士兵先进攻
            int red_k, blue_k, temp; red_k = blue_k = 0; //当前使用武器
            int turn = 1;
            while(turn++<=200 && red->life>0 && blue->life>0 && (red->arm_num>0||blue->arm_num>0)){//双方都活着且至少有一方有武器
                if (red->arm_num > 0){
                    temp = red->attack(blue, red_k);
                    if (!temp) red_k = (red_k+1)%red->arm_num; //如果武器没有使用完转而使用下一个武器
                    if (temp&&red_k>=red->arm_num) red_k = 0; //如果使用完并且是最后一个，那么直接转移到0
                }

                if (blue->life <= 0) break;
                if (blue->arm_num > 0){
                    temp = blue->attack(red, blue_k);
                    if (!temp) blue_k = (blue_k+1)%blue->arm_num; //如果武器没有使用完转而使用下一个武器
                    if (temp&&blue_k>=blue->arm_num) blue_k = 0;
                }
                if (red->life <= 0) break;
            }
        }
        else{ //蓝方士兵先进攻
            int red_k, blue_k, temp; red_k = blue_k = 0; //当前使用武器
            int turn = 1;
            while(turn++ <= 200 && red->life>0 && blue->life>0 && (red->arm_num>0||blue->arm_num>0)){//双方都活着且至少有一方有武器
                if (blue->arm_num > 0){
                    temp = blue->attack(red, blue_k);
                    if (!temp) blue_k = (blue_k+1)%blue->arm_num; //如果武器没有使用完转而使用下一个武器
                    if (temp&&blue_k>=blue->arm_num) blue_k = 0;
                }
                if (red->life <= 0) break;
                if (red->arm_num > 0){
                    temp = red->attack(blue, red_k);
                    if (!temp) red_k = (red_k+1)%red->arm_num; //如果武器没有使用完转而使用下一个武器
                    if (temp&&red_k>=red->arm_num) red_k = 0;
                }
                if (blue->life <= 0) break;
            }
        }
        //打印战果
        if (red->life>0 && blue->life<=0){
            //缴获武器
            if (blue->arm_num > 0){
                for (int j = 0; j < blue->arm_num; j++) {
                    red->arms[red->arm_num++] = blue->arms[j];
                    red->arms[red->arm_num-1]->reset_attack(wa_att[red->race]); //抢来的武器重新设置攻击力
                    red->sba[blue->arms[j]->id]++;
                }
            }
            print_time();
            cout << "red "<< wa_race[red->race] << " " << red->id << " killed blue " << wa_race[blue->race]
                 <<" " << blue->id << " in city " << i << " remaining " << red->life << " elements" << endl;
            delete city[i]->blue_wa;
            city[i]->blue_wa = nullptr;
        }
        else if (red->life<=0 && blue->life>0){
            //缴获武器
            if (red->arm_num > 0){
                for (int j = 0; j < red->arm_num; j++) {
                    blue->arms[blue->arm_num++] = red->arms[j];
                    blue->arms[blue->arm_num-1]->reset_attack(wa_att[blue->race]); //抢来的武器重新设置攻击力
                    blue->sba[red->arms[j]->id]++;
                }
            }
            print_time();
            cout << "blue "<< wa_race[blue->race] << " " << blue->id << " killed red " << wa_race[red->race]
                 <<" " << red->id << " in city " << i << " remaining " << blue->life << " elements" << endl;
            delete city[i]->red_wa;
            city[i]->red_wa = nullptr;


        }
        else if (red->life<=0 && blue->life<=0){
            print_time();
            cout << "both red " << wa_race[red->race] << " " << red->id << " and blue "
                 << wa_race[blue->race] << " " << blue->id << " died in city " << i << endl;
            delete city[i]->red_wa;
            city[i]->red_wa = nullptr;
            delete city[i]->blue_wa;
            city[i]->blue_wa = nullptr;
        }
        else {
            print_time();
            cout << "both red " << wa_race[red->race] << " " << red->id << " and blue "
                 << wa_race[blue->race] << " " << blue->id << " were alive in city " << i << endl;
        }
        if (red->race == 0 && red->life > 0){
            print_time();
            cout << "red dragon " << red->id << " yelled in city " << i << endl;
        }
        if (blue->race == 0 && blue->life > 0){
            print_time();
            cout << "blue dragon " << blue->id << " yelled in city " << i << endl;
        }
    }
}

void wa_report(){
    for (int i = 0; i <= N+1; i++){
        warrior* temp = city[i]->red_wa;
        if (temp){
            print_time();
            cout << "red " << wa_race[temp->race] << " " << temp->id << " has "
                 << temp->sba[0] << " sword " << temp->sba[1] << " bomb " << temp->sba[2] << " arrow "
                 << "and " << temp->life << " elements" << endl;
        }
        temp = city[i]->blue_wa;
        if (temp){
            print_time();
            cout << "blue " << wa_race[temp->race] << " " << temp->id << " has "
                 << temp->sba[0] << " sword " << temp->sba[1] << " bomb " << temp->sba[2] << " arrow "
                 << "and " << temp->life << " elements" << endl;
        }
    }
}

int main(){
    int test;
    cin >> test;
    for (int i = 1; i <= test ; i++) {
        cin >> M >> N >> K >> T;
        for (int j = 0; j < 5; j++) cin >> wa_life[j];
        for (int k = 0; k < 5; k++) cin >> wa_att[k];
        for (int l = 0; l <= N+1; l++) {
            city[l] = new City(l); //创建城市对象
        }
        clocks = minute = tot_minute = 0;
        headquarter red(0, M);
        headquarter blue(1, M);
        over = false;
        cout << "Case " << i << ":" <<  endl;
        while (tot_minute<=T){ //结束条件
            minute = 0;
            tot_minute += minute;
            //产生武士
            red.Produce();
            blue.Produce();
            if (tot_minute >= T) break;

            //第5分钟狮子逃跑
            minute = 5;
            tot_minute += 5;
            lion_escape();
            if (tot_minute >= T) break;

            //第10分钟各个阵营武士行军
            minute = 10;
            tot_minute += 5;
            red.march();
            blue.march();
            print_march();
            if (over) break;
            if (tot_minute >= T) break;

            //在第35分钟wolf抢夺武器
            minute = 35;
            tot_minute += 25;
            snatch_weapon();
            if (tot_minute >= T) break;

            //在第40分钟开战（我好累啊
            minute = 40;
            tot_minute += 5;
            battle();
            if (tot_minute >= T) break;

            //报告阵营情况
            minute = 50;
            tot_minute += 10;
            red.report();
            blue.report();
            if (tot_minute >= T) break;

            //报告武士情况
            minute = 55;
            tot_minute += 5;
            wa_report();
            if (tot_minute >= T) break;

            tot_minute += 5;


            clocks++;
        }
    }
}
