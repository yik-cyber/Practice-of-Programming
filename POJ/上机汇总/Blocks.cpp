#include<bits/stdc++.h>
using namespace std;

int n, cnt;
int color[210];
int num[210];
int box[210];
int score[210][210][210];

int dp(int l, int r, int rlen){
    if(score[l][r][rlen]) return score[l][r][rlen];

    if(l == r) return (num[r]+rlen) * (num[r]+rlen);

    score[l][r][rlen] = (num[r]+rlen)*(num[r]+rlen) + dp(l,r-1,0);

    for(int k = l; k < r; k++){
        if(color[k] == color[r]){
            score[l][r][rlen] = max(score[l][r][rlen], dp(l,k,num[r]+rlen)+dp(k+1,r-1,0));
        }
    }
    return score[l][r][rlen];
}

int main(){
    int t, cases = 1;
    scanf("%d", &t);
    while (t--){
        memset(score, 0,sizeof(score));
      scanf("%d", &n);
      cnt = 0;
      scanf("%d", &box[0]);
      num[0] = 1;
      color[0] = box[0];
      for(int i = 1; i < n; i++){
          scanf("%d", &box[i]);
          if(box[i]==box[i-1]){
              num[cnt]++;
          }
          else {
              cnt++;
              num[cnt] = 1;
              color[cnt] = box[i];
          }
      }
      int ans = dp(0,cnt,0);
      printf("Case %d: %d\n",cases, ans);
      cases++;
    }
}
