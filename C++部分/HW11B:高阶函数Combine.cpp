#include <iostream>
using namespace std;

// 在此处补充你的代码
template <class T1, class T2, class T3>
class combine{
public:
    T1 f;
    T2 g;
    combine(T1 _f, T2 _g):f(_f),g(_g){}
    T3 operator()(T3 n){
        return f((f(n)+g(n)));
    }
};

int main()
{
    auto Square = [] (double a) { return a * a; };
    auto Inc = [] (double a) { return a + 1; };
    cout << combine<decltype(Square),decltype(Inc),int>(Square,Inc)(3) << endl;
    cout << combine<decltype(Inc),decltype(Square),double>(Inc,Square)(2.5) << endl;

    return 0;
}
