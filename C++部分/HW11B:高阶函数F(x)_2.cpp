#include <iostream>
using namespace std;

#include <functional> //抄的大佬的，wrnb
template <typename T1, typename T2>
auto f(T1 x)->function<T2(T2)>{
    return [x](T2 y){return y + x;};
}


int main()
{
    cout << f<int,int>(7)(9) << endl;   //16
    cout << f<string,string> (" hello!")("world")  <<endl; // world hello!
    cout << f<char,string> ('!')("world") << endl;


    return 0;    //world!
}
