#include<cstdio>
#include<string.h>

bool dilei[110][110];
int num[110][110];
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    char c;
    memset(dilei, false, sizeof(dilei));
    for(int i = 0; i < n; i++){
        scanf("%c", &c);
        for(int j = 0; j < m; j++){
            scanf("%c", &c);
            if (c == '*') dilei[i][j] = true;
            else if (c == '?') dilei[i][j] = false;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dilei[i][j]) continue;
            if(i-1>=0 && j-1>=0 && dilei[i-1][j-1]) num[i][j]++;
            if(i-1>=0 && dilei[i-1][j]) num[i][j]++;
            if(i-1>=0 && j+1<m && dilei[i-1][j+1]) num[i][j]++;
            if(j-1>=0 && dilei[i][j-1]) num[i][j]++;
            if(j+1<m && dilei[i][j+1]) num[i][j]++;
            if(i+1<n && j-1>=0 && dilei[i+1][j-1]) num[i][j]++;
            if(i+1<n && dilei[i+1][j]) num[i][j]++;
            if(i+1<n && j+1<m && dilei[i+1][j+1]) num[i][j]++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dilei[i][j]) printf("*");
            else printf("%d", num[i][j]);
        }
        printf("\n");
    }
}
