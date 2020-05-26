#include <bits/stdc++.h>
using namespace std;

const int N = 16;
struct DP{
    int pre;
    int min_score;
    int last;
    int finish_day;
};

struct HW{
    string name;
    int ddl;
    int cost;
};

vector<int> get_solution(DP dp[], int status){
    vector<int> solv;
    int num;
    while(status > 0){
        num = dp[status].last;
        solv.push_back(num);
        status = dp[status].pre;
    }
    reverse(solv.begin(), solv.end());
    return solv;

}

int main(){
    int test;
    scanf("%d", &test);
    while (test--){
        int n;
        cin >> n;
        DP dp[1<<n];
        HW hw[n+1];
        for(int i = 0; i < n; i++) cin >> hw[i].name >> hw[i].ddl >> hw[i].cost;
        dp[0].finish_day = 0;
        dp[0].min_score = 0;
        dp[0].last = -1;
        dp[0].pre = -1;

        vector<int> best_solve, tmp_solve1, tmp_solve2;

        int end = 1 << n;
        for(int i = 1; i < end; i++){
            dp[i].min_score = 0x3f3f3f3f;
            for(int j = 0; j < n; j++){
                if (!(i&(1<<j))) continue;
                int pre_hw = 1 << j;
                int pre_status = i - pre_hw;
                int exceed_time = dp[pre_status].finish_day + hw[j].cost - hw[j].ddl;
                int tmp_min_score = dp[pre_status].min_score;
                if (exceed_time > 0) tmp_min_score += exceed_time; //超时了

                if (tmp_min_score < dp[i].min_score){
                    dp[i].min_score = tmp_min_score;
                    dp[i].pre = pre_status;
                    dp[i].last = j;
                    dp[i].finish_day = dp[pre_status].finish_day + hw[j].cost;
                }
                else if (tmp_min_score == dp[i].min_score){
                    tmp_solve1 = get_solution(dp, pre_status);
                    tmp_solve1.push_back(j);
                    tmp_solve2 = get_solution(dp, dp[i].pre);
                    tmp_solve2.push_back(dp[i].last);
                    if(tmp_solve1 < tmp_solve2){
                        dp[i].pre = pre_status;
                        dp[i].last = j;
                        dp[i].finish_day = dp[pre_status].finish_day + hw[j].cost;
                    }
                }
            }
        }
        int min_scores = dp[end-1].min_score;
        best_solve = get_solution(dp, end-1);
        cout << min_scores << "\n";
        for(int i = 0; i < best_solve.size(); i++){
            cout << hw[best_solve[i]].name << '\n';
        }

    }
}
