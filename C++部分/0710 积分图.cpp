#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class IntegralImage{
//
public:
    int* data;
    int h, w;
    int cnt;
    IntegralImage(int _h, int _w):h(_h),w(_w){
        data = new int[h*w];
        cnt = 0;
    }
    void operator()(int* line){
        int* cur = data + cnt * w;
        int line_sum = 0;
        for(int i = 0; i < w; ++i){
            line_sum += line[i];
            *(cur + i) = line_sum;
            if(cnt>0){
                *(cur + i) += *(data+(cnt-1)*w + i);
            }
        }
        cnt++;
    }
    int* operator[](int i){
        return data+i*w;
    }
//

};
int main(){
    int H, W;
    cin >> H >> W;
    int ** image = new int*[H];
    for(int i=0;i<H;++i){
        image[i]=new int[W];
    }
    for(int i=0;i<H;++i)
        for(int j=0;j<W;++j)
            cin >> image[i][j];
    IntegralImage it(H,W);
    for_each(image, image+H, it);
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j)
            cout<<it[i][j]<<" ";
        cout<<endl;
    }

}
