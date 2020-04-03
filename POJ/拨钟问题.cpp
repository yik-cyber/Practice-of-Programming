#include <stdio.h>

int main() {
    int move[10]; //九种移动的次数
    int clocks[10]; //九个时钟的数值
    for(int i = 1; i <= 9; i++)
        scanf("%d", &clocks[i]);
    int sum = 0;
    for(move[1] = 0; move[1] < 4; move[1]++){
        for(move[2] = 0; move[2] < 4; move[2]++){
            for(move[3] = 0; move[3] < 4; move[3]++){
                move[4] = (4 - (clocks[1]+move[1]+move[2])%4)%4; //通过A确定第四个
                move[5] = (4 - (clocks[2]+move[1]+move[2]+move[3])%4)%4; //通过B确定第五个
                move[6] = (4 - (clocks[3]+move[2]+move[3])%4)%4; //通过C确定第六个
                move[7] = (4 - (clocks[4]+move[1]+move[4]+move[5])%4)%4; //通过D确定第七个
                move[8] = (4 - (clocks[7]+move[4]+move[7])%4)%4; //通过G确定第八个
                move[9] = (4 - (clocks[5]+move[1]+move[3]+move[5]+move[7])%4)%4; //通过E确定第九个
                sum = 0;
                sum+=(clocks[1]+move[1]+move[2]+move[4])%4;
                sum+=(clocks[2]+move[1]+move[2]+move[3]+move[5])%4;
                sum+=(clocks[3]+move[2]+move[3]+move[6])%4;
                sum+=(clocks[4]+move[1]+move[4]+move[5]+move[7])%4;
                sum+=(clocks[5]+move[1]+move[3]+move[5]+move[7]+move[9])%4;
                sum+=(clocks[6]+move[3]+move[5]+move[6]+move[9])%4;
                sum+=(clocks[7]+move[4]+move[7]+move[8])%4;
                sum+=(clocks[8]+move[5]+move[7]+move[8]+move[9])%4;
                sum+=(clocks[9]+move[6]+move[8]+move[9])%4;

                if(sum==0){
                    for(int l = 1;l <= 9;l++){
                        while(move[l]--)printf("%d ",l);
                    }
                    return 0;
                }
            }
        }
    }
}
