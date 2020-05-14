#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
template <class T>
class CArray3D
{

// 在此处补充你的代码
public:
    T *data;
    int x,y,z;
    CArray3D(int _x, int _y, int _z):x(_x),y(_y),z(_z){
        data = new T[x*y*z];
    }
    class CArray2D{
    public:
        T *data;
        int y,z;
        int layer;
        CArray2D(int _y, int _z, int _layer, T* _data){
            y = _y; z = _z; layer = _layer;
            data = _data + layer*(y*z); //begin
        }
        T* operator[](int i){
            return data + i*z;
        }
    };
    CArray2D operator[](int j){
        return CArray2D(y,z,j,data);
    }
    operator void*(){ //注意这里是void*()
        return data;
    }

};

CArray3D<int> a(3, 4, 5);
CArray3D<double> b(3,2,2);
void PrintA()
{
    for(int i = 0;i < 3; ++i) {
        cout << "layer " << i << ":" << endl;
        for(int j = 0; j < 4; ++j) {
            for(int k = 0; k < 5; ++k)
                cout << a[i][j][k] << "," ;
            cout << endl;
        }
    }
}
void PrintB()
{
    for(int i = 0;i < 3; ++i) {
        cout << "layer " << i << ":" << endl;
        for(int j = 0; j < 2; ++j) {
            for(int k = 0; k < 2; ++k)
                cout << b[i][j][k] << "," ;
            cout << endl;
        }
    }
}

int main()
{

    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    PrintA();
    memset(a, -1, 60 * sizeof(int));        //注意这里
    memset(a[1][1], 0, 5 * sizeof(int));
    PrintA();

    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 2; ++j )
            for( int k = 0; k < 2; ++k )
                b[i][j][k] = 10.0 / (i + j + k + 1);
    PrintB();
    int n = a[0][1][2];
    double f = b[0][1][1];
    cout << "****" << endl;
    cout << n << "," << f << endl;

    return 0;
}
