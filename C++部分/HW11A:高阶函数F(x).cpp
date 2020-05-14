#include <iostream>
using namespace std;

template <class T1, class T2>
class f{
public:
    T1 t1;
    f(T1 t):t1(t){}
    auto operator()(T2 _t2)->decltype(t1+_t2){
        return _t2+t1;
    }
};


int main()
{
    cout << f<int,int>(7)(9) << endl;   //16
    cout << f<string,string> (" hello!")("world")  <<endl; // world hello!
    cout << f<char,string> ('!')("world") << endl;


    return 0;    //world!
}
