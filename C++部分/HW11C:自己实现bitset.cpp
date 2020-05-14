#include <iostream>
#include <cstring>
using namespace std;
template <int bitNum>
struct MyBitset
{
    char a[bitNum/8+1];
    MyBitset() { memset(a,0,sizeof(a));};
    void Set(int i,int v) {
        char & c = a[i/8];
        int bp = i % 8;
        if( v )
            c |= (1 << bp);
        else
            c &= ~(1 << bp);
    }

// 在此处补充你的代码
    bool inital = false;
    class bit_container{
    public:
        bool bit;
        bit_container(bool _bit = 0):bit(_bit){}
        friend ostream& operator<<(ostream& out, bit_container& b){
            out<<b.bit;
            return out;
        }
        bit_container& operator=(const bit_container& b){
            if(&b == this) return *this;
            bit = b.bit;
            return *this;
        }
        bit_container& operator=(int v){
            bit = v;
            return *this;
        }

    }bc[bitNum+1];

    bit_container& operator[](int i){
        if(!inital){
            for(int i = 0; i < bitNum; i++){
                bc[i] = (a[i/8]>>(i%8))&1;
            }
            inital = true;
        }
        return bc[i];
    }

    void Print() {
        for(int i = 0;i < bitNum; ++i)
            cout << (*this) [i];
        cout << endl;
    }

};

int main()
{
    int n;
    int i,j,k,v;
    while( cin >>  n) {
        MyBitset<20> bs;
        for(int i = 0;i < n; ++i) {
            int t;
            cin >> t;
            bs.Set(t,1);
        }
        bs.Print();
        cin >> i >> j >> k >> v;
        bs[k] = v;
        bs[i] = bs[j] = bs[k];
        bs.Print();
        cin >> i >> j >> k >> v;
        bs[k] = v;
        (bs[i] = bs[j]) = bs[k];
        bs.Print();
    }
    return 0;
}
